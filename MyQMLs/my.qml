/*!
 *  \file       my.qml
 *  \brief      Start to learn the Qt QML programming.
 *
 */


import QtQuick 2.15

Rectangle {
    width: 640
    height: 480
    color: "blue"
    Image {
        source: "Alice_Yu.jpg"
        anchors.centerIn: parent
    }
}
