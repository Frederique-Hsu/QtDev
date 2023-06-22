/*!
 *  \file       my_font.qml
 *  \brief
 *
 */


import QtQuick 2.15

Text {
    onFontChanged: console.log("Font changed.")

    text: "Hello Qt QML!"
    Text { id: otherText }
    focus: true

    Keys.onDigit1Pressed: font.pixelSize += 1
    Keys.onDigit2Pressed: font.italic =! font.italic
    Keys.onDigit3Pressed: font = otherText.font
}
