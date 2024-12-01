/*!
 *  \file       ReusableComponent.qml
 *  \brief
 *
 */

import QtQuick

Rectangle {
    id: root

    width: 140
    height: 120

    Button {
        id: button
        x: 12
        y: 12
        text: "Start"
        onClicked: {
            status.text = "Button clicked"
        }
    }

    Text {
        id: status
        x: 12
        y: 76
        text: "waiting..."
        horizontalAlignment: Text.AlignHCenter
    }
}
