import QtQuick 2.15

Item {
    width: parent.width
    height: text1.implicitHeight

    property alias text1: text1
    property alias text2: text2

    Text {
        id: text1
        color: "white"
        anchors.left: parent.left
        anchors.leftMargin: 10
    }

    Text {
        id: text2
        color: "white"
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
