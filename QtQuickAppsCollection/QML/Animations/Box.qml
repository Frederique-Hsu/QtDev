/*!
 *  \file       Box.qml
 *  \brief
 *
 */


import QtQuick


Rectangle {
    id: root

    width: 64
    height: 64
    color: "#FFFFFF"
    border.color: Qt.darker(color, 1.2)

    property alias text: label.text
    property color fontColor: "#1F1F1F"

    Text {
        id: label
        anchors.centerIn: parent
        font.pixelSize: 14
        color: root.fontColor
    }
}
