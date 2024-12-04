/*!
 *  \file       ArrangeInRow.qml
 *  \brief
 *
 */


import QtQuick


BrightSquare {
    id: root
    width: 400
    height: 120

    Row {
        id: row
        anchors.centerIn: parent
        spacing: 20

        RedSquare {}
        GreenSquare {}
        BlueSquare {}
    }
}
