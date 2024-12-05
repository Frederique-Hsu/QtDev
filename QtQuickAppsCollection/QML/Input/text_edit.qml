/*!
 *  \file       text_edit.qml
 *  \brief
 *
 */


import QtQuick


Rectangle {
    id: root
    width: 136
    height: 120
    color: "linen"

    TTextEdit {
        id: input
        x: 8
        y: 8
        width: 120
        height: 104
        focus: true
        text: "Text Edit"
    }
}
