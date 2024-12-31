/*!
 *  \file       ArrangeInRepeater.qml
 *  \brief
 *
 */


import QtQuick


DarkSquare {
    id: root
    width: 252
    height: 252

    property variant colorArray: ["#00BDE3", "#67C111", "#EA7025"]

    Grid {
        anchors.fill: parent
        anchors.margins: 8
        spacing: 4

        Repeater {
            model: 20
            delegate: Rectangle {
                required property int index
                property int colorIndex: Math.floor(Math.random() * 3)

                width: 56
                height: 56
                color: root.colorArray[colorIndex]
                border.color: Qt.lighter(color)

                Text {
                    anchors.centerIn: parent
                    color: "#F0F0F0"
                    text: "Cell" + (parent.index + 1)
                }
            }
        }
    }
}
