import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15

Item {
    id: mapView
    anchors.fill: parent
    // Aggiungi questa proprietà per il controller
    property var controller

    property alias routeModel: routeModel
    property alias routeQuery: routeQuery
    property alias vehicle: vehicle
    // Espone l'oggetto `Map` come proprietà
    property alias map: map

    signal completedRoute()

    Plugin {
        id: mapPlugin
        name: "osm"
        parameters: [
                    PluginParameter { name: "osm.mapping.providersrepository.address"; value: "https://tile.openstreetmap.org/" },
                    PluginParameter { name: "osm.mapping.providersrepository.enabled"; value: true }
                ]
    }

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

        // Vista per visualizzare i marker sulla mappa
        MapItemView {
            model: markerModel
            delegate: MapQuickItem {
                id: markerItem
                coordinate: QtPositioning.coordinate(latitude, longitude)
                anchorPoint.x: image.width * 0.5
                anchorPoint.y: image.height
                //property bool isVehicle: model.isVehicle // Associa la proprietà dal modello

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
                                showRouteThroughMarkers() // Aggiorna la rotta quando il marker viene spostato
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
                                    clearRoute()
                                } else {
                                    showRouteThroughMarkers() // Aggiorna la rotta quando il marker viene rimosso
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
                //console.log("RouteModel full data:", JSON.stringify(routeModel, null, 2));
                // Ottieni il JSON completo del RouteModel
                var routeJson = JSON.stringify(routeModel, null, 2);
                // Emetti il segnale con il JSON della rotta
                mapView.routeCompleted(routeJson);

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

    SearchBarView {
        id: searchBar
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.9
        anchors.topMargin: 20 // Aggiungi un margine superiore
        controller: mapView.controller // Passa il controller
    }

    // Funzione per aggiungere un marker
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

    // Funzione per cancellare tutti i marker
    function clearMarkers() {
        for (var i = markerModel.count - 1; i >= 0; i--) {
            markerModel.remove(i)
        }
        clearRoute()
        console.log("Cleared all markers")
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

    // funzione per tracciare una rotta tra i marker
    function showRouteThroughMarkers() {
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
        controller.hasRoute=true
    }

    // funzione per gestire lo zoom della mappa dopo il calcolo della rotta
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
}
