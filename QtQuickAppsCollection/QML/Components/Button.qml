/*!
 *  \file   Button.qml
 *  \brief
 *
 */


import QtQuick

Rectangle {
    id: root

    // export button properties
    property alias text: label.text
    signal clicked

    width: 116
    height: 26
    color: "lightsteelblue"
    border.color: "slategrey"

    Text {
        id: label
        anchors.centerIn: parent
        text: "Start"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
}
