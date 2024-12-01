/*!
 *  \file       RectangleElement.qml
 *  \brief
 *
 */


import QtQuick


Item {
    id: root
    width: 200
    height: 300

    Rectangle {
        id: rect1
        x: 12; y: 12;
        width: 76
        height: 96
        // color: "lightsteelblue"
        color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
    }

    Rectangle {
        id: rect2

        x: 112; y: 12
        width: 76
        height: 96
        border.color: "lightsteelblue"
        border.width: 4
        radius: 8
    }

    Rectangle {
        id: rect3

        x: 12; y: 120
        width: 176
        height: 96
        gradient: Gradient {
            GradientStop {position: 0.0; color: "lightsteelblue"}
            GradientStop {position: 1.0; color: "slategray"}
        }
        border.color: "red"
    }
}