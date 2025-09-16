/*!
 *  \file       my.qml
 *  \brief      Start to learn the Qt QML programming.
 *
 */


import QtQuick 2.15 as CoreItems

CoreItems.Rectangle {
    width: 640
    height: 480
    color: "blue"
    CoreItems.Image {
        source: "Alice_Yu.jpg"
        anchors.centerIn: parent
    }
    CoreItems.MouseArea {
        anchors.fill: parent
        onClicked: console.log("The color of rectange: ", color)
    }
}

/*
Item {
    width: 300
    height: 300
    Rectangle {
        width: parent.width - 50
        height: 100
        color: "yellow"
    }
}
 */
