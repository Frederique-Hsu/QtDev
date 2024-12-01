/*!
 *  \file       TextExample.qml
 *  \brief
 *
 */


import QtQuick

Text {
    id: thisLabel

    x: 24
    y: 16

    height: 2 * width

    property int times: 24      // custom property
    property alias anotherTimes: thisLabel.times    // property alias

    text: "Greetings" + times
    font.family: "Ubuntu"
    font.pixelSize: 24

    // KeyNavigation.tab: otherLabel

    // signal handler for property changes
    onHeightChanged: console.log('height: ', height)

    focus: true     // focus is need to receive key events
    color: focus ? "red" : "black"
}
