/*!
 *  \file       Transformation.qml
 *  \brief
 *
 */


import QtQuick

Item {
    id: root

    // set width based on given background
    width: bg.width
    height: bg.height

    Image {
        id: bg
        source: "assets/background.png"
    }

    MouseArea {
        id: backgroundClicker

        anchors.fill: parent
        onClicked: {
            circle.x = 84
            box.rotation = 0
            triangle.rotation = 0
            triangle.scale = 1.0
        }
    }

    ClickableImage {
        id: circle
        x: 84; y: 68
        source: "assets/circle_blue.png"
        antialiasing: true
        onClicked: {
            x += 20
        }
    }

    ClickableImage {
        id: box
        x: 164; y: 68
        source: "assets/box_green.png"
        antialiasing: true
        onClicked: {
            rotation += 15
        }
    }

    ClickableImage {
        id: triangle
        x: 248; y: 68
        source: "assets/triangle_red.png"
        antialiasing: true
        onClicked: {
            rotation += 15
            scale += 0.05
        }
    }
}
