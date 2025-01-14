import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtLocation 5.15
import QtPositioning 5.15

ApplicationWindow {
    id: appWindow
    visible: true
    title: qsTr("FC Control Station")
    width: 800
    height: 600

    signal showRouteThroughMarkers()
    signal clearRouteSignal()
    signal clearAllMarkers()

    // Imposta lo stile Material
    Material.theme: Material.Light
    Material.accent: Material.LightBlue

    // Proprietà per tracciare lo stato della simulazione
    property string simulationState: "stopped" // Valori: "stopped", "running", "paused"

    // Menu bar con opzioni Open, Exit e Clear Route
    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered")
            }
            MenuItem {
                text: qsTr("&Exit")
                onTriggered: Qt.quit()
            }
        }
        Menu {
            title: qsTr("Map")
            MenuItem {
                text: qsTr("&Trace Route Through Markers")
                onTriggered: {
                    console.log("Trace Route Through Markers menu item triggered")
                    appWindow.showRouteThroughMarkers()
                }
            }
            MenuItem {
                text: qsTr("&Clear Route")
                onTriggered: {
                    console.log("Clear Route menu item triggered")
                    appWindow.clearRouteSignal()
                }
            }
            MenuItem {
                text: qsTr("&Clear Markers")
                onTriggered: {
                    console.log("Clear Markers menu item triggered")
                    appWindow.clearAllMarkers()
                    appWindow.clearRouteSignal()
                }
            }
        }
        Menu {
            title: qsTr("Simulation")
            MenuItem {
                text: simulationState === "running" ? "Pause Simulation" :
                                                      (simulationState === "paused" ? "Resume Simulation" : "Start Simulation")
                onTriggered: {
                    if (simulationState === "running") {
                        pauseSimulation();
                    } else {
                        startSimulation(routeModel);
                    }
                }
            }
            MenuItem {
                text: "Stop Simulation"
                enabled: simulationState !== "stopped"
                onTriggered: stopSimulation();
            }
        }

    }

    // Plugin per OpenStreetMap
    Plugin {
        id: mapPlugin
        name: "osm"
    }

    // Mappa centrata su Torino con livello di zoom 14
    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(45.0703, 7.6869) // Torino
        zoomLevel: 14

        Component.onCompleted: {
            console.log("Map component completed. Center: ", map.center, " ZoomLevel: ", map.zoomLevel)
        }

        // Mouse area per gestire le interazioni
        MouseArea {
            id: mapMouseArea
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            property var lastMousePosition: null

            onPressed: (mouse) => {
                           if (mouse.button === Qt.LeftButton) {
                               console.log("Left mouse button pressed at: ", mouse.x, ", ", mouse.y)
                               searchField.focus = false
                               lastMousePosition = Qt.point(mouse.x, mouse.y)
                           }
                       }

            onReleased: (mouse) => {
                            console.log("Mouse button released")
                            lastMousePosition = null
                        }

            onPositionChanged: (mouse) => {
                                   if (mouse.buttons === Qt.LeftButton && lastMousePosition) {
                                       var deltaX = mouse.x - lastMousePosition.x
                                       var deltaY = mouse.y - lastMousePosition.y
                                       var deltaCoord = map.toCoordinate(Qt.point(map.width / 2 + deltaX, map.height / 2 + deltaY))
                                       map.center = QtPositioning.coordinate(
                                           map.center.latitude + (map.center.latitude - deltaCoord.latitude),
                                           map.center.longitude + (map.center.longitude - deltaCoord.longitude)
                                           )
                                       lastMousePosition = Qt.point(mouse.x, mouse.y)
                                       console.log("Map panned to new center: ", map.center)
                                   }
                               }

            onClicked: (mouse) => {
                           if (mouse.button === Qt.RightButton) {
                               console.log("Right-clicked on map at: ", mouse.x, ", ", mouse.y)
                               contextMenu.x = mouse.x
                               contextMenu.y = mouse.y
                               contextMenu.open()
                           }
                       }

            onWheel: (wheel) => {
                         if (wheel.angleDelta.y > 0) {
                             map.zoomLevel += 1
                         } else if (wheel.angleDelta.y < 0) {
                             map.zoomLevel -= 1
                         }
                         console.log("Zoom level changed to: ", map.zoomLevel)
                     }
        }

        // Modello per contenere i dati dei marker
        ListModel {
            id: markerModel
        }

        MapQuickItem {
            id: vehicle
            coordinate: QtPositioning.coordinate(0, 0) // Inizialmente fuori mappa
            visible: false // Sarà visibile solo durante la simulazione
            anchorPoint.x: carImage.width / 2
            anchorPoint.y: carImage.height / 2
            sourceItem: Image {
                id: carImage
                source: "qrc:/car.png"
                width: 30
                height: 30
            }
        }

        // Vista per visualizzare i marker sulla mappa
        MapItemView {
            model: markerModel
            delegate: MapQuickItem {
                id: markerItem
                coordinate: QtPositioning.coordinate(latitude, longitude)
                anchorPoint.x: image.width * 0.5
                anchorPoint.y: image.height
                property bool isVehicle: model.isVehicle // Associa la proprietà dal modello

                property real originalX: 0
                property real originalY: 0

                sourceItem: Rectangle {
                    width: 40
                    height: 40
                    color: "transparent"

                    Image {
                        id: image
                        source: "qrc:/marker.png"
                        anchors.centerIn: parent
                    }
                    Text {
                        text: title
                        font.bold: true
                        anchors.top: image.bottom
                        anchors.horizontalCenter: image.horizontalCenter
                    }

                    MouseArea {
                        id: mouseArea
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton | Qt.RightButton
                        drag.target: markerItem
                        drag.axis: Drag.XandYAxis

                        onPressed: {
                            markerItem.originalX = markerItem.x;
                            markerItem.originalY = markerItem.y;
                            console.log("Marker pressed at: ", markerItem.originalX, ", ", markerItem.originalY)
                        }
                        onReleased: {
                            // Controlla se il marker è stato effettivamente spostato
                            if (markerItem.x !== markerItem.originalX || markerItem.y !== markerItem.originalY) {
                                var newCoordinate = map.toCoordinate(Qt.point(markerItem.x + image.width / 2, markerItem.y + image.height))
                                markerModel.set(index, { latitude: newCoordinate.latitude, longitude: newCoordinate.longitude, title: title })
                                console.log("Marker moved to: ", newCoordinate.latitude, ", ", newCoordinate.longitude)
                                appWindow.showRouteThroughMarkers() // Aggiorna la rotta quando il marker viene spostato
                            } else {
                                console.log("Marker not moved")
                            }
                        }

                        onDoubleClicked: {
                            // Rimuove il marker
                            if (index >= 0 && index < markerModel.count) {
                                markerModel.remove(index)
                                console.log("Marker removed at index: ", index)
                                if (markerModel.count < 2) {
                                    appWindow.clearRouteSignal()
                                } else {
                                    appWindow.showRouteThroughMarkers() // Aggiorna la rotta quando il marker viene rimosso
                                }
                            } else {
                                console.log("Invalid marker index: ", index)
                            }
                        }
                    }

                    Drag.active: mouseArea.drag.active
                    Drag.hotSpot.x: image.width / 2
                    Drag.hotSpot.y: image.height / 2
                }
            }
        }

        // Menu combinato per mappa e marker
        Menu {
            id: contextMenu
            property int markerIndex: -1

            MenuItem {
                text: "Add Marker"
                onTriggered: {
                    var coord = map.toCoordinate(Qt.point(contextMenu.x, contextMenu.y));
                    addMarker(coord.latitude, coord.longitude);
                }
                visible: !contextMenu.isMarker
            }
        }

        // Modello per calcolare e visualizzare le rotte
        RouteModel {
            id: routeModel
            plugin: map.plugin
            query: RouteQuery {
                id: routeQuery
                travelModes: RouteQuery.CarTravel
                routeOptimizations: RouteQuery.FastestRoute
            }
            onStatusChanged: {
                console.log("RouteModel status changed: ", status)
                console.log("RouteModel full data:", JSON.stringify(routeModel, null, 2));
                if (status == RouteModel.Ready) {
                    if (count > 0) {
                        console.log("Route calculation succeeded")
                        fitRoute(); // Centra e adatta la vista alla rotta
                    } else {
                        console.log("No routes found")
                    }
                } else if (status == RouteModel.Error) {
                    console.log("Route calculation failed")
                }
            }
        }

        Component {
            id: routeDelegate
            MapRoute {
                id: route
                route: routeData
                line.color: "#46a2da"
                line.width: 5
                smooth: true
                opacity: 0.8
            }
        }

        MapItemView {
            id: routeView
            anchors.fill: parent
            model: routeModel
            delegate: routeDelegate
            autoFitViewport: false
        }
    }

    // Barra di ricerca nella parte superiore della finestra
    Column {
        width: 600
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.margins: 10
        spacing: 5

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
                    background: Rectangle {
                        color: "transparent"
                        radius: 20
                    }
                    onTextChanged: {
                        console.log("Text changed: ", searchField.text)
                        updateSuggestions(searchField.text)
                    }
                    Keys.onReleased: (event) => {
                                         if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                                             console.log("Return/Enter key pressed in search field")
                                             if (suggestionModel.count > 0) {
                                                 var suggestion = suggestionModel.get(0)
                                                 addMarker(parseFloat(suggestion.lat), parseFloat(suggestion.lon))
                                                 searchField.text = "" // Svuota la barra di ricerca
                                                 suggestionModel.clear() // Pulisce i suggerimenti
                                             } else {
                                                 searchCoordinates(searchField.text)
                                             }
                                         }
                                     }
                }
            }
        }

        ListView {
            id: suggestionList
            width: parent.width
            height: suggestionModel.count > 0 ? suggestionModel.count * 30 : 0 // Riduci l'altezza di ogni suggerimento
            model: suggestionModel
            clip: true
            delegate: Item {
                width: suggestionList.width
                height: 30 // Riduci l'altezza di ogni suggerimento

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Suggestion clicked: ", JSON.stringify({
                                                                               display_name: display_name,
                                                                               lat: lat,
                                                                               lon: lon
                                                                           }, null, 2)); // Mostra il JSON formattato
                        map.center = QtPositioning.coordinate(parseFloat(lat), parseFloat(lon))
                        addMarker(parseFloat(lat), parseFloat(lon)) // Aggiungi il marker alle coordinate selezionate
                        searchField.text = "" // Svuota la barra di ricerca
                        suggestionModel.clear() // Pulisce i suggerimenti
                    }
                }

                Text {
                    text: display_name
                    font.pointSize: 10 // Riduci la dimensione del testo
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.margins: 5
                }
            }
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

        // Messaggio di errore con timer
        Text {
            id: errorMessage
            text: qsTr("Unable to fetch suggestions. Retrying in 5 seconds...")
            color: "red"
            anchors.horizontalCenter: parent.horizontalCenter
            visible: false
        }
    }

    ListModel {
        id: suggestionModel
    }

    // Timer per riprovare a stabilire la connessione
    Timer {
        id: retryTimer
        interval: 5000 // Intervallo di 5 secondi
        repeat: true
        running: false
        onTriggered: {
            updateSuggestions(searchField.text)
        }
    }

    // Timer per aggiornare il messaggio di errore
    Timer {
        id: countdownTimer
        interval: 1000 // Intervallo di 1 secondo
        repeat: true
        running: false
        onTriggered: {
            errorMessage.text = qsTr("Unable to fetch suggestions. Retrying in %1 seconds...").arg(countdownSeconds)
            countdownSeconds--
            if (countdownSeconds < 0) {
                countdownTimer.stop()
            }
        }
    }

    // Variabile per il conto alla rovescia
    property int countdownSeconds: 5
    // Funzione per aggiornare i suggerimenti
    function updateSuggestions(input) {
        console.log("Updating suggestions for input: ", input)
        if (input.length < 3) {
            suggestionModel.clear()
            loadingIndicator.running = false
            errorMessage.visible = false
            retryTimer.stop() // Ferma il timer se non c'è input valido
            countdownTimer.stop() // Ferma il timer del conto alla rovescia
            return
        }

        loadingIndicator.running = true
        errorMessage.visible = false

        var url = "https://nominatim.openstreetmap.org/search?format=json&q=" + encodeURIComponent(input)

        var xhr = new XMLHttpRequest()
        xhr.open("GET", url, true)
        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                loadingIndicator.running = false
                if (xhr.status === 200) {
                    console.log("Received response: ", xhr.responseText)
                    var response = JSON.parse(xhr.responseText)
                    suggestionModel.clear()
                    for (var i = 0; i < response.length && i < 5; i++) {
                        suggestionModel.append({
                                                   display_name: response[i].display_name,
                                                   lat: response[i].lat,
                                                   lon: response[i].lon
                                               })
                        console.log("Suggestion added: ", response[i].display_name)
                    }
                    retryTimer.stop() // Ferma il timer se la richiesta ha successo
                    countdownTimer.stop() // Ferma il timer del conto alla rovescia
                } else {
                    errorMessage.visible = true
                    countdownSeconds = 5
                    errorMessage.text = qsTr("Unable to fetch suggestions. Retrying in %1 seconds...").arg(countdownSeconds)
                    countdownTimer.start() // Avvia il timer del conto alla rovescia
                    console.log("Failed to fetch suggestions: ", xhr.statusText)
                    retryTimer.start() // Avvia il timer se la richiesta fallisce
                }
            }
        }
        xhr.send()
    }

    function addMarker(latitude, longitude) {
        if (isNaN(latitude) || isNaN(longitude)) {
            console.log("Invalid coordinates: ", latitude, longitude);
            return;
        }

        // Genera un titolo progressivo (pointA, pointB, ...)
        var markerIndex = markerModel.count;
        var markerTitle = "point" + String.fromCharCode(65 + markerIndex); // Aggiunge 'A', 'B', 'C', ...

        // Aggiunge il nuovo marker al modello
        markerModel.append({
                               latitude: latitude,
                               longitude: longitude,
                               title: markerTitle
                           });

        // Centra la mappa sul nuovo marker (opzionale)
        map.center = QtPositioning.coordinate(latitude, longitude);
        map.zoomLevel = 17; // Opzionale: imposta il livello di zoom

        console.log("Marker created at: ", latitude, longitude, " with title: ", markerTitle);
    }

    // Funzione per cercare coordinate e centrare la mappa
    function searchCoordinates(input) {
        var coords = input.split(',')
        if (coords.length === 2) {
            var latitude = parseFloat(coords[0].trim())
            var longitude = parseFloat(coords[1].trim())
            if (!isNaN(latitude) && !isNaN(longitude)) {
                addMarker(latitude, longitude)
                searchField.text = "" // Svuota la barra di ricerca
                suggestionModel.clear() // Pulisce i suggerimenti
                console.log("Map centered on coordinates: ", latitude, ", ", longitude)
                return
            }
        }
        console.log("Invalid input for coordinates: " + input)

        // Cerca l'indirizzo utilizzando il servizio Nominatim
        var url = "https://nominatim.openstreetmap.org/search?format=json&q=" + encodeURIComponent(input)

        var xhr = new XMLHttpRequest()
        xhr.open("GET", url, true)
        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                if (xhr.status === 200) {
                    var response = JSON.parse(xhr.responseText)
                    if (response.length > 0) {
                        var firstResult = response[0]
                        var latitude = parseFloat(firstResult.lat)
                        var longitude = parseFloat(firstResult.lon)
                        addMarker(latitude, longitude)
                        searchField.text = "" // Svuota la barra di ricerca
                        suggestionModel.clear() // Pulisce i suggerimenti
                        console.log("Map centered on address: ", input, " at coordinates: ", latitude, ", ", longitude)
                    } else {
                        console.log("No results found for address: ", input)
                    }
                } else {
                    errorMessage.visible = true
                    countdownSeconds = 5
                    errorMessage.text = qsTr("Unable to fetch suggestions. Retrying in %1 seconds...").arg(countdownSeconds)
                    countdownTimer.start() // Avvia il timer del conto alla rovescia
                    console.log("Failed to fetch coordinates: ", xhr.statusText)
                    retryTimer.start() // Avvia il timer se la richiesta fallisce
                }
            }
        }
        xhr.send()
    }

    // Funzione per cancellare la rotta corrente
    function clearRoute() {
        if (routeQuery) {
            routeQuery.clearWaypoints()
        }
        if (routeModel) {
            routeModel.reset()
        }
        console.log("Cleared the current route")
    }

    // Funzione per cancellare tutti i marker
    function clearMarkers() {
        for (var i = markerModel.count - 1; i >= 0; i--) {
            markerModel.remove(i)
        }
        console.log("Cleared all markers")
    }

    function fitRoute() {
        if (routeModel.count > 0) {
            console.log("Starting fitRoute, routeModel count:", routeModel.count);

            var minLat = 90.0;
            var maxLat = -90.0;
            var minLon = 180.0;
            var maxLon = -180.0;

            for (var i = 0; i < routeModel.count; i++) {
                var routeObject = routeModel.get(i);
                if (routeObject && routeObject.path) {
                    console.log("Route path found at index", i, ":", routeObject.path);

                    var path = routeObject.path;
                    for (var j = 0; j < path.length; j++) {
                        var coord = path[j];
                        minLat = Math.min(minLat, coord.latitude);
                        maxLat = Math.max(maxLat, coord.latitude);
                        minLon = Math.min(minLon, coord.longitude);
                        maxLon = Math.max(maxLon, coord.longitude);
                    }
                } else {
                    console.log("No valid path for route at index", i);
                }
            }

            var centerLat = (minLat + maxLat) / 2;
            var centerLon = (minLon + maxLon) / 2;
            var center = QtPositioning.coordinate(centerLat, centerLon);
            map.center = center;

            var latDiff = maxLat - minLat;
            var lonDiff = maxLon - minLon;
            var maxDiff = Math.max(latDiff, lonDiff);

            // Calcolo del livello di zoom con limiti
            var zoom = 15 - Math.log(maxDiff) / Math.log(2);
            map.zoomLevel = Math.max(1, Math.min(zoom, 15)); // Limita il livello di zoom tra 1 e 15


            console.log("Fitted map to route with center: ", center, " and zoom level: ", map.zoomLevel);
        } else {
            console.log("No route data to fit");
        }
    }

    // Proprietà per la simulazione
    property var routePoints: [] // Array di punti sulla rotta
    property real vehicleSpeed: 50 // Velocità in km/h
    property int currentIndex: 0 // Indice attuale del veicolo

    Timer {
        id: simulationTimer
        interval: 16 // Aggiornamento ogni 16 ms (~60 FPS)
        repeat: true
        running: false
        property real elapsedTime: 0 // Tempo trascorso sul segmento corrente
        property real segmentDuration: 0 // Durata totale del segmento corrente

        onTriggered: {
            if (currentIndex < routePoints.length - 1) {
                let start = routePoints[currentIndex];
                let end = routePoints[currentIndex + 1];

                if (simulationTimer.elapsedTime >= simulationTimer.segmentDuration) {
                    // Passa al punto successivo
                    currentIndex++;
                    simulationTimer.elapsedTime = 0;

                    if (currentIndex >= routePoints.length - 1) {
                        vehicle.coordinate = QtPositioning.coordinate(end.latitude, end.longitude);
                        simulationTimer.stop();
                        simulationState = "stopped";
                        console.log("Simulation finished at:", vehicle.coordinate);
                        return;
                    }

                    // Calcola la durata del prossimo segmento
                    start = routePoints[currentIndex];
                    end = routePoints[currentIndex + 1];
                    let distance = calculateDistance(start, end); // Distanza in km
                    simulationTimer.segmentDuration = (distance / vehicleSpeed) * 3600 * 1000; // Durata in ms
                }

                // Calcola la posizione interpolata
                simulationTimer.elapsedTime += simulationTimer.interval;
                let progress = Math.min(simulationTimer.elapsedTime / simulationTimer.segmentDuration, 1.0); // Progressione [0,1]
                let interpolatedLat = start.latitude + (end.latitude - start.latitude) * progress;
                let interpolatedLon = start.longitude + (end.longitude - start.longitude) * progress;

                vehicle.coordinate = QtPositioning.coordinate(interpolatedLat, interpolatedLon);

                // Centra la mappa sul veicolo
                map.center = vehicle.coordinate;

                console.log("Vehicle moving to:", vehicle.coordinate);
            }
        }
    }

    // Funzione per calcolare la distanza tra due punti in km
    function calculateDistance(start, end) {
        const R = 6371; // Raggio della Terra in km
        let dLat = (end.latitude - start.latitude) * Math.PI / 180;
        let dLon = (end.longitude - start.longitude) * Math.PI / 180;

        let lat1 = start.latitude * Math.PI / 180;
        let lat2 = end.latitude * Math.PI / 180;

        let a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
                Math.sin(dLon / 2) * Math.sin(dLon / 2) * Math.cos(lat1) * Math.cos(lat2);

        let c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
        return R * c; // Distanza in km
    }

    // Funzione per avviare la simulazione
    function startSimulation(routeModel) {
        routePoints = [];
        for (let i = 0; i < routeModel.count; i++) {
            let routeObject = routeModel.get(i);
            if (routeObject && routeObject.path) {
                routePoints = routeObject.path; // Salva il percorso
                console.log("Route path for simulation:", routePoints);
                break;
            }
        }

        if (routePoints.length > 1) {
            currentIndex = 0;
            simulationTimer.elapsedTime = 0;
            vehicle.coordinate = QtPositioning.coordinate(routePoints[0].latitude, routePoints[0].longitude);
            vehicle.visible = true;

            // Calcola la durata del primo segmento
            let start = routePoints[0];
            let end = routePoints[1];
            let distance = calculateDistance(start, end); // Distanza in km
            simulationTimer.segmentDuration = (distance / vehicleSpeed) * 3600 * 1000; // Durata in ms

            simulationTimer.start();
            simulationState = "running";
            console.log("Simulation started, vehicle at:", vehicle.coordinate);
        } else {
            console.log("No valid route for simulation");
        }
    }


    // Funzione per mettere in pausa la simulazione
    function pauseSimulation() {
        if (simulationTimer.running) {
            simulationTimer.stop();
            simulationState = "paused";
            console.log("Simulation paused at:", vehicle.coordinate);
        } else {
            console.log("Simulation is not running");
        }
    }

    // Funzione per fermare completamente la simulazione
    function stopSimulation() {
        simulationTimer.stop();
        vehicle.visible = false;
        currentIndex = 0; // Resetta l'indice
        simulationState = "stopped";
        console.log("Simulation stopped");
    }

    Connections {
        target: appWindow
        function onShowRouteThroughMarkers() {
            console.log("Calculating route through markers")
            if (markerModel.count < 2) {
                console.log("Not enough markers to calculate a route");
                clearRoute()
                return
            }

            clearRoute()

            // Aggiungere waypoint in ordine
            for (var i = 0; i < markerModel.count; i++) {
                var marker = markerModel.get(i)
                console.log("Adding waypoint:", marker.latitude, marker.longitude);
                routeQuery.addWaypoint(QtPositioning.coordinate(marker.latitude, marker.longitude))
            }

            routeModel.update()
        }

        function onClearRouteSignal() {
            clearRoute()
        }

        function onClearAllMarkers() {
            clearMarkers()
            appWindow.clearRouteSignal()
        }
    }
}
