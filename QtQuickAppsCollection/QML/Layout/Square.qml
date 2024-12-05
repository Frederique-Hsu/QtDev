/*!
 *  \file       Square.qml
 *  \brief
 *
 */


import QtQuick


Rectangle {
    width: 96
    height: width
    border.color: Qt.lighter(color)

    property alias text: label.text

    Text {
        id: label
        anchors.centerIn: parent
        color: "#F0F0F0"
    }

    MouseArea {
        anchors.fill: parent
        drag.target: parent
    }
}
