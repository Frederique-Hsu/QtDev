/*!
 *  \file       ArrangeInFlow.qml
 *  \brief
 *
 */


import QtQuick


BrightSquare {
    id: root

    width: 160
    height: 160

    Flow {
        id: flow
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20

        RedSquare {}
        GreenSquare {}
        BlueSquare {}
        RedSquare {}
        DarkSquare {}
    }
}
