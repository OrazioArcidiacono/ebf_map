import QtQuick 2.15
import QtQuick.Controls 2.15
import QtPositioning 5.15

Column {
    width: 600
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.top: parent.top
    anchors.margins: 10
    spacing: 5

    // Proprietà per il controller (se lo usi davvero in un componente esterno)
    property var controller

    // Proprietà di gestione errori/tempo
    property int countdownSeconds: 5
    property int retryAttempts: 3 // Numero massimo di tentativi
    property bool isRequestInProgress: false // Stato della richiesta
    property var suggestionCache: ({}) // Cache per i suggerimenti

    // Barra di ricerca
    Rectangle {
        width: parent.width
        height: 40
        color: "#80FFFFFF" // Trasparente con un po' di bianco
        radius: 20

        Row {
            anchors.fill: parent
            anchors.margins: 5

            TextField {
                id: searchField
                width: parent.width
                height: parent.height
                placeholderText: qsTr("Enter coordinates (latitude, longitude) or address")
                color: "#87CEFA" // Blu chiaro
                background: Rectangle {
                    color: "transparent"
                    radius: 20
                }

                // Quando l'utente preme Invio/Return
                onAccepted: handleSearch()

                // Quando il testo cambia, usiamo il debounce
                onTextChanged: {
                    console.log("Text changed: ", searchField.text)
                    debounceUpdateSuggestions(searchField.text)
                }
            }
        }
    }

    // Contenitore per i suggerimenti
    Rectangle {
        id: suggestionContainer
        width: parent.width
        height: suggestionModel.count > 0 ? suggestionModel.count * 30 : 0
        clip: true
        border.color: "#d0d0d0"
        border.width: 1
        radius: 5
        color: "#ffffff"
        visible: suggestionModel.count > 0

        ListView {
            id: suggestionList
            width: parent.width
            height: suggestionModel.count > 0 ? suggestionModel.count * 30 : 0
            model: suggestionModel
            clip: true

            delegate: Item {
                width: suggestionList.width
                height: 30

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Suggestion clicked: ", JSON.stringify({
                                                                               display_name: display_name,
                                                                               lat: lat,
                                                                               lon: lon
                                                                           }, null, 2))

                        // Centra la mappa sulle coordinate
                        map.center = QtPositioning.coordinate(parseFloat(lat), parseFloat(lon))
                        addMarker(parseFloat(lat), parseFloat(lon))

                        // Svuota la barra di ricerca e i suggerimenti
                        searchField.text = ""
                        suggestionModel.clear()
                    }
                }

                Text {
                    text: display_name
                    font.pointSize: 10
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.margins: 5
                }
            }
        }
    }

    // Modello dei suggerimenti
    ListModel {
        id: suggestionModel
    }

    // Indicatore di caricamento
    BusyIndicator {
        id: loadingIndicator
        width: 40
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        running: false
        visible: running
    }

    // Messaggio di errore con countdown
    Text {
        id: errorMessage
        text: qsTr("Retrying in ...%1 seconds").arg(countdownSeconds)
        color: "red"
        anchors.horizontalCenter: parent.horizontalCenter
        visible: false
        font.bold: true
        font.pointSize: 14
    }

    // Timer per retry automatici (se li vuoi abilitare in caso di errore)
    Timer {
        id: retryTimer
        interval: 5000
        repeat: true
        running: false
        onTriggered: {
            if (retryAttempts > 0) {
                retryAttempts--
                countdownSeconds = 5 // Reset countdown per ogni tentativo
                updateSuggestions(searchField.text)
            } else {
                retryTimer.stop()
                errorMessage.text = qsTr("Max retry attempts reached. Please try again later.")
                console.log("Max retry attempts reached.")
            }
        }
    }

    // Timer per il conto alla rovescia
    Timer {
        id: countdownTimer
        interval: 1000
        repeat: true
        running: false
        onTriggered: {
            if (countdownSeconds > 1) {
                countdownSeconds--
                errorMessage.text = qsTr("Retrying in ...%1 seconds").arg(countdownSeconds)
            } else {
                countdownTimer.stop()
                errorMessage.visible = false
            }
        }
    }

    // Timer per effettuare il debounce della ricerca
    Timer {
        id: debounceTimer
        interval: 500 // Ritardo di 500 ms
        repeat: false
        onTriggered: {
            updateSuggestions(searchField.text)
        }
    }

    // Funzione di debounce: riavvia il timer ogni volta che il testo cambia
    function debounceUpdateSuggestions(input) {
        if (debounceTimer.running) {
            debounceTimer.stop()
        }
        debounceTimer.start()
    }

    // Funzione principale per aggiornare i suggerimenti
    function updateSuggestions(input) {
        // Se l'input è troppo corto, svuota i suggerimenti
        if (input.length < 3) {
            suggestionModel.clear()
            loadingIndicator.running = false
            return
        }

        // Se abbiamo già in cache i suggerimenti, usali
        if (suggestionCache[input]) {
            console.log("Using cached suggestions for input: ", input)
            suggestionModel.clear()
            suggestionCache[input].forEach(suggestion => suggestionModel.append(suggestion))
            return
        }

        // Se è già in corso una richiesta, non farne un'altra
        if (isRequestInProgress) {
            console.log("Request already in progress. Skipping...")
            return
        }

        isRequestInProgress = true
        loadingIndicator.running = true

        // Richiesta HTTP a Nominatim
        sendHttpRequest("https://nominatim.openstreetmap.org/search?format=json&q=" + encodeURIComponent(input), function(response) {
            suggestionModel.clear()
            suggestionCache[input] = []

            // Aggiunge i primi 5 suggerimenti
            for (var i = 0; i < response.length && i < 5; i++) {
                var suggestion = {
                    display_name: response[i].display_name,
                    lat: response[i].lat,
                    lon: response[i].lon
                }
                suggestionModel.append(suggestion)
                suggestionCache[input].push(suggestion)
                console.log("Suggestion added: ", response[i].display_name)
            }
            isRequestInProgress = false
            loadingIndicator.running = false
        })
    }

    // Funzione generica per inviare una richiesta HTTP
    function sendHttpRequest(url, successCallback) {
        var xhr = new XMLHttpRequest()
        xhr.open("GET", url, true)
        xhr.timeout = 15000 // Timeout per la richiesta
        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                if (xhr.status === 200) {
                    try {
                        var response = JSON.parse(xhr.responseText)
                        successCallback(response)
                    } catch (e) {
                        handleError("Error parsing response: " + e)
                    }
                } else {
                    handleError("Request failed with status: " + xhr.statusText)
                }
            }
        }
        xhr.onerror = function() {
            handleError("Network error occurred.")
        }
        xhr.ontimeout = function() {
            handleError("Request timed out.")
        }
        xhr.send()
    }

    // Gestione degli errori
    function handleError(message) {
        console.error(message)
        isRequestInProgress = false
        loadingIndicator.running = false

        // Se vuoi avviare il retry in automatico:
        // retryTimer.start()
        // countdownTimer.start()
        // errorMessage.visible = true
        // errorMessage.text = qsTr("Retrying in ...%1 seconds").arg(countdownSeconds)
    }

    // Funzione invocata quando l'utente preme Invio
    function handleSearch() {
        var input = searchField.text.trim()
        if (!input) return

        // 1) Tenta di interpretare l'input come coordinate
        var coords = input.split(',')
        if (coords.length === 2) {
            var latitude = parseFloat(coords[0].trim())
            var longitude = parseFloat(coords[1].trim())
            if (!isNaN(latitude) && !isNaN(longitude)) {
                // Centra la mappa
                addMarker(latitude, longitude)
                searchField.text = ""
                suggestionModel.clear()
                console.log("Map centered on coordinates: ", latitude, ", ", longitude)
                return
            }
        }

        // 2) Se ci sono già dei suggerimenti, usa il primo
        if (suggestionModel.count > 0) {
            var suggestion = suggestionModel.get(0)
            addMarker(parseFloat(suggestion.lat), parseFloat(suggestion.lon))
            searchField.text = ""
            suggestionModel.clear()
            return
        }

        // 3) Altrimenti, cerca direttamente l'indirizzo su Nominatim
        searchCoordinates(input)
    }

    // Cerca coordinate da un input generico (indirizzo, etc.)
    function searchCoordinates(input) {
        var url = "https://nominatim.openstreetmap.org/search?format=json&q=" + encodeURIComponent(input)
        var xhr = new XMLHttpRequest()
        xhr.open("GET", url, true)
        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                if (xhr.status === 200) {
                    try {
                        var response = JSON.parse(xhr.responseText)
                        if (response.length > 0) {
                            var firstResult = response[0]
                            var latitude = parseFloat(firstResult.lat)
                            var longitude = parseFloat(firstResult.lon)

                            if (!isNaN(latitude) && !isNaN(longitude)) {
                                addMarker(latitude, longitude)
                                searchField.text = ""
                                suggestionModel.clear()
                                console.log("Map centered on address: ", input, " at coordinates: ", latitude, ", ", longitude)
                            } else {
                                console.error("Invalid coordinates in response: ", firstResult)
                                showErrorAndStartCountdown()
                            }
                        } else {
                            console.warn("No results found for address: ", input)
                            showErrorAndStartCountdown()
                        }
                    } catch (e) {
                        console.error("Error parsing response: ", e)
                        showErrorAndStartCountdown()
                    }
                } else {
                    console.error("Failed to fetch coordinates: ", xhr.statusText)
                    showErrorAndStartCountdown()
                }
            }
        }
        xhr.send()
    }

    // Mostra un messaggio di errore e avvia il conto alla rovescia
    function showErrorAndStartCountdown() {
        countdownSeconds = 5
        errorMessage.visible = true
        errorMessage.text = qsTr("Retrying in ...%1 seconds").arg(countdownSeconds)
        countdownTimer.start()
    }
}
