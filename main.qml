import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtLocation 5.15
import QtPositioning 5.15
import "controllers"
import "components"

ApplicationWindow {
    id: appWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("EBF Control Station")

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
    }

    // Mappa
    MapView {
        id: mapView
        anchors.topMargin: mainMenuBar.height // Imposto un margine per evitare sovrapposizioni con MenuBarView
        controller: appController // Passa il controller
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
}
