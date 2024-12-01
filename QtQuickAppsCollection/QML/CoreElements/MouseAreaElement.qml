/*!
 *  \file       MouseAreaElement.qml
 *  \brief
 *
 */


import QtQuick


Rectangle {
    id: root

    width: 200
    height: 120

    Rectangle {
        id: rect1
        x: 12
        y: 12
        width: 76
        height: 96
        color: "lightsteelblue"
        MouseArea {
            id: area
            width: parent.width
            height: parent.height
            onClicked: rect2.visible = !rect1.visible
        }
    }
    Rectangle {
        id: rect2
        x: 112
        y: 12
        width: 76
        height: 96
        border.color: "red"
        border.width: 4
        radius: 8
    }
}
