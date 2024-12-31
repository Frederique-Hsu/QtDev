/*!
 *  \file       ClickableImage.qml
 *  \brief
 *
 */


import QtQuick

Item {
    id: root

    property alias text: label.text
    property alias source: image.source

    signal clicked()

    width: container.childrenRect.width + 16
    height: container.childrenRect.height + 16

    // add a framed rectangle as a container
    property bool framed: false
    Rectangle {
        anchors.fill: parent
        color: "white"
        visible: root.framed
    }

    Column {
        id: container
        x: 8; y: 8

        Image {
            id: image
        }
        Text {
            id: label
            width: image.width
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.WordWrap
            color: "#E0E0E0"
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
