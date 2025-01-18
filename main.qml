import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtLocation 5.15
import QtPositioning 5.15
import fc.proto 1.0
import "controllers"
import "components"

ApplicationWindow {
    id: appWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("FC Control Station")

    Material.theme: Material.Light
    Material.accent: Material.LightBlue

    // Controller
    AppController {
        id: appController
        onExitApplication: Qt.quit()
        onClearMarkers: mapView.clearMarkers()
        onTraceRoute: mapView.showRouteThroughMarkers()
        onClearRoute: mapView.clearRoute()
        onSimulationStarted: simManager.startSimulation()
        onSimulationPaused: simManager.pauseSimulation()
        onSimulationResumed: simManager.resumeSimulation()
        onSimulationStopped: simManager.stopSimulation()
        onThreadStarting: function (routeMessage) {
            console.log("Start following Route");
            protoManager.startRouteThreads(routeMessage)
        }
    }

    ProtoManager {
        id: protoManager

        // Funzione con parametro formale per gestire i segnali
        onMessageGenerated: function(message) {
            console.log("Messaggio generato:", message);
        }
    }

    // Barra dei menu
    MenuBarView {
        id: mainMenuBar
        controller: appController // Passa il controller
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        onApplicationExit: appController.handleExitApplication() // Notifica l'uscita al controller
        onTraceRoute: appController.handleTraceRoute()
        onClearRoute: appController.handleClearRoute()
        onClearMarkers: appController.handleClearMarkers()
        onSimulationStarted: appController.handleStartSimulation()
        onSimulationPaused: appController.handlePauseSimulation()
        onSimulationResumed: appController.handleResumeSimulation()
        onSimulationStopped: appController.handleStopSimulation()
        onThreadStarting: appController.handleThreadStarting()
    }

    // Mappa
    MapView {
        id: mapView
        anchors.topMargin: mainMenuBar.height // Imposto un margine per evitare sovrapposizioni con MenuBarView
        controller: appController // Passa il controller
        onRouteCompleted: function(routeJson) {
            appController.handleAvailableRoute(routeJson);
        }
    }

    SimulationManager {
        id: simManager
        controller: appController        // Passa il controller
        routeModel: mapView.routeModel   // Collegato a quello della MapView
        routeQuery: mapView.routeQuery   // Se serve manipolare i waypoint
        vehicleItem: mapView.vehicle
        mapView: mapView                 // Se vuoi centrare la mappa sul veicolo
        vehicleSpeed: 50                 // km/h di default
    }

    Component.onCompleted: {
        // Crea un messaggio con lo stato ONLINE
        var onlineMessage = protoManager.createServiceMessage(ProtoManager.SERVICE_STATUS_ONLINE);
        console.log("Messaggio Online:", onlineMessage);

        // Crea messaggi multipli
        var multipleMessages = protoManager.createMultipleMessages();
        console.log("Messaggi Multipli:", multipleMessages);

        // Legge il messaggio
        var parsedOnlineMessage = protoManager.readMessage(onlineMessage);
        console.log("Messaggio Deserializzato:", parsedOnlineMessage);

//        // Leggi i messaggi multipli
//        var parsedMultiMessage = protoManager.readMessage(multipleMessages);
//        console.log("Messaggio Multiplo Deserializzato:\n", parsedMultiMessage);
    }
    Component.onDestruction: {
        // Crea un messaggio con lo stato OFFLINE
        var offlineMessage = protoManager.createServiceMessage(ProtoManager.SERVICE_STATUS_OFFLINE);
        console.log("Messaggio Offline:", offlineMessage);

        // Legge il messaggio
        var parsedOfflineMessage = protoManager.readMessage(offlineMessage);
        console.log("Messaggio Deserializzato:", parsedOfflineMessage);
    }
}
