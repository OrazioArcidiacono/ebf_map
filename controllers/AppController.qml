import QtQuick 2.15

QtObject {
    id: appController

    // Segnali
    signal exitApplication()
    signal traceRoute()
    signal clearRoute()
    signal clearMarkers()

    // Stato della simulazione
    property string simulationState: "stopped" // Valori: "stopped", "running", "paused"

    // Segnali per aggiornare il menu
    signal simulationStarted()
    signal simulationPaused()
    signal simulationResumed()
    signal simulationStopped()

    // Funzioni
    function handleExitApplication() {
        console.log("AppController: Exiting application");
        exitApplication();
    }

    function handleTraceRoute() {
        console.log("AppController: Tracing route");
        traceRoute();
    }

    function handleClearRoute() {
        console.log("AppController: Clearing route");
        clearRoute();
    }

    function handleClearMarkers() {
        console.log("AppController: Clearing markers");
        clearMarkers();
    }

    // Funzioni per cambiare stato
    function handleStartSimulation() {
        if (simulationState === "stopped") {
            simulationState = "running";
            console.log("AppController: Simulation start");
            simulationStarted();
        }
    }

    function handlePauseSimulation() {
        if (simulationState === "running") {
            simulationState = "paused";
            console.log("AppController: Simulation pause");
            simulationPaused();
        }
    }

    function handleResumeSimulation() {
        if (simulationState === "paused") {
            simulationState = "running";
            console.log("AppController: Simulation resume");
            simulationResumed();
        }
    }

    function handleStopSimulation() {
        if (simulationState !== "stopped") {
            simulationState = "stopped";
            console.log("AppController: Simulation stop");
            simulationStopped();
        }
    }
}
