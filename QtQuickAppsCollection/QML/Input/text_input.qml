/*!
 *  \file       text_input.qml
 *  \brief
 *
 */


import QtQuick


Rectangle {
    width: 200
    height: 80
    color: "linen"

    TextInput {
        id: input1
        x: 8
        y: 8
        width: 96
        height: 20
        focus: true
        text: "Text Input1"
        KeyNavigation.tab: input2
    }

    TextInput {
        id: input2
        x: 8
        y: 36
        width: 96
        height: 20
        text: "Text Input2"
        KeyNavigation.tab: input1
    }
}
