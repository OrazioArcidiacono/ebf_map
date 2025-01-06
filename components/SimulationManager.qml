import QtQuick 2.15
import QtPositioning 5.15

Item {
    id: simManager
    // Aggiungi questa proprietà per il controller
    property var controller
    // Stato della simulazione: "stopped", "running", "paused"
    property string simulationState: "stopped"

    // Velocità del veicolo (km/h)
    property real vehicleSpeed: 50

    // Riferimenti a oggetti esterni:
    property var routeModel: null      // il tuo RouteModel
    property var routeQuery: null      // se ti serve manipolare waypoints
    property var vehicleItem: null     // un MapQuickItem con l'icona del veicolo, se lo usi
    property var mapView: null         // se vuoi centrare la mappa sul veicolo

    // Array di punti (lat, lon) della rotta
    property var routePoints: []
    // Indice del tratto corrente
    property int currentIndex: 0

    // Timer di simulazione
    Timer {
        id: simulationTimer
        interval: 16
        repeat: true
        running: false

        property real elapsedTime: 0       // tempo trascorso sul tratto corrente (ms)
        property real segmentDuration: 0   // durata complessiva del tratto (ms)

        onTriggered: {
            if (currentIndex < routePoints.length - 1) {
                let start = routePoints[currentIndex];
                let end   = routePoints[currentIndex + 1];

                // Se abbiamo superato la durata del tratto, passiamo al successivo
                if (elapsedTime >= segmentDuration) {
                    currentIndex++
                    elapsedTime = 0

                    // Se siamo arrivati all’ultimo punto, stop
                    if (currentIndex >= routePoints.length - 1) {
                        if (vehicleItem) {
                            vehicleItem.coordinate = QtPositioning.coordinate(end.latitude, end.longitude)
                        }
                        simulationTimer.stop()
                        simulationState = "stopped"
                        console.log("Simulation finished at:", end)
                        return
                    }

                    // Calcola la durata del prossimo tratto
                    start = routePoints[currentIndex]
                    end   = routePoints[currentIndex + 1]
                    let distance = calculateDistance(start, end)
                    segmentDuration = distanceToDuration(distance, vehicleSpeed)
                }

                // Interpola la posizione sul tratto
                elapsedTime += simulationTimer.interval
                let progress = Math.min(elapsedTime / segmentDuration, 1.0)
                let interpolatedLat = start.latitude + (end.latitude - start.latitude) * progress
                let interpolatedLon = start.longitude + (end.longitude - start.longitude) * progress

                // Aggiorna la posizione del veicolo
                if (vehicleItem) {
                    vehicleItem.coordinate = QtPositioning.coordinate(interpolatedLat, interpolatedLon)
                }

                // Se vuoi centrare la mappa sul veicolo:
                if (mapView) {
                    console.log("mapView is defined:", mapView);
                    if (mapView.map) {
                        //console.log("map is defined:", mapView.map);
                        mapView.map.center = QtPositioning.coordinate(interpolatedLat, interpolatedLon);
                    } else {
                        //console.log("map is undefined");
                    }
                } else {
                    //console.log("mapView is undefined");
                }
            }
        }
    }

    // =========================
    //     FUNZIONI
    // =========================

    // Avvia la simulazione
    function startSimulation() {
        if (!routeModel || routeModel.count === 0) {
            console.log("No routeModel or empty routeModel")
            return
        }

        // Trova un routeObject che abbia path non vuoto
        routePoints = []
        for (let i = 0; i < routeModel.count; i++) {
            let routeObject = routeModel.get(i)
            if (routeObject && routeObject.path && routeObject.path.length > 1) {
                routePoints = routeObject.path
                console.log("Route points for simulation:", routePoints)
                break
            }
        }

        if (routePoints.length < 2) {
            console.log("No valid route for simulation")
            return
        }

        currentIndex = 0
        simulationTimer.elapsedTime = 0

        // Posiziona il veicolo sul primo punto
        let start = routePoints[0]
        if (vehicleItem) {
            vehicleItem.visible = true
            vehicleItem.coordinate = QtPositioning.coordinate(start.latitude, start.longitude)
        }

        // Calcola la durata del primo tratto
        let end = routePoints[1]
        let distance = calculateDistance(start, end)
        simulationTimer.segmentDuration = distanceToDuration(distance, vehicleSpeed)

        // Avvia timer
        simulationTimer.start()
        simulationState = "running"
        console.log("Simulation started")
    }

    // Metti in pausa
    function pauseSimulation() {
        if (simulationTimer.running) {
            simulationTimer.stop()
            simulationState = "paused"
            console.log("Simulation paused at index:", currentIndex, "elapsed time:", simulationTimer.elapsedTime)
        } else {
            console.log("Cannot pause: Simulation is not running")
        }
    }

    // Ferma completamente
    function stopSimulation() {
        simulationTimer.stop()
        simulationState = "stopped"
        currentIndex = 0
        if (vehicleItem) {
            vehicleItem.visible = false
        }
        console.log("Simulation stopped")
    }

    function resumeSimulation() {
        if (simulationState === "paused") {
            simulationTimer.start(); // Riprende il timer dal punto in cui era stato fermato
            simulationState = "running";
            console.log("Simulation resumed from index:", currentIndex, "elapsed time:", simulationTimer.elapsedTime);
        } else {
            console.log("Cannot resume: Simulation is not paused");
        }
    }

    // Calcola distanza in km tra due coordinate
    function calculateDistance(start, end) {
        const R = 6371
        let dLat = (end.latitude - start.latitude) * Math.PI/180
        let dLon = (end.longitude - start.longitude) * Math.PI/180
        let lat1 = start.latitude * Math.PI/180
        let lat2 = end.latitude * Math.PI/180

        let a = Math.sin(dLat/2)*Math.sin(dLat/2) +
            Math.sin(dLon/2)*Math.sin(dLon/2) * Math.cos(lat1) * Math.cos(lat2)
        let c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a))
        return R * c
    }

    // Distanza (km) e velocità (km/h) => durata in ms
    function distanceToDuration(distanceKm, speedKmh) {
        let hours = distanceKm / speedKmh
        return hours * 3600 * 1000
    }
}
