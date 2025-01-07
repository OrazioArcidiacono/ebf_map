import QtQuick 2.15
import QtQuick.Controls 2.15

MenuBar {
    id: menuBarView
    // Aggiungi questa proprietà per il controller
    property var controller
    // Segnali che verranno emessi in risposta alle azioni del menu
    signal traceRoute()
    signal clearRoute()
    signal clearMarkers()
    signal applicationExit()

    // Segnali per aggiornare il menu
    signal simulationStarted()
    signal simulationPaused()
    signal simulationResumed()
    signal simulationStopped()

    Menu {
        title: qsTr("File")
        MenuItem {
            text: qsTr("&Open")
            onTriggered: console.log("Open action triggered")
        }
        MenuItem {
            text: qsTr("&Exit")
            onTriggered: {
                applicationExit() // Emette il segnale al Controller
            }
        }
    }

    Menu {
        title: qsTr("Map")
        MenuItem {
            text: qsTr("&Trace Route Through Markers")
            onTriggered: {
                traceRoute()
            }
        }
        MenuItem {
            text: qsTr("&Clear Route")
            onTriggered: {
                clearRoute()
            }
        }
        MenuItem {
            text: qsTr("&Clear Markers")
            onTriggered: {
                clearMarkers()
            }
        }
    }

    Menu {
        title: qsTr("Simulation")
        enabled: controller.hasRoute // Abilitato solo se c'è una rotta
        MenuItem {
            text: controller.simulationState === "running" ? qsTr("Pause Simulation") :
                                                             (controller.simulationState === "paused" ? qsTr("Resume Simulation") : qsTr("Start Simulation"))
            onTriggered: {
                if (controller.simulationState === "running") {
                    simulationPaused();
                } else if (controller.simulationState === "paused") {
                    simulationResumed();
                } else {
                    simulationStarted();
                }
                console.log("simulationState:",controller.simulationState)
            }
        }

        MenuItem {
            text: qsTr("Stop Simulation")
            enabled: controller.simulationState !== "stopped"
            onTriggered: simulationStopped()
        }
    }
}
