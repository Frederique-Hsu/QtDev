/*!
 *  \file       ScriptingExample.qml
 *  \brief
 *
 */


import QtQuick


Rectangle {
    id: root
    width: 240
    height: 120

    Text {
        id: label

        x: 24; y: 24;

        property int spacePresses: 0

        text: "Space pressed: " + spacePresses + " times"

        // handler for text changes. Need to use function to capture parameters
        onTextChanged: function(text) {
            console.log("text changed to: ", text)
        }

        focus: true     // Need focus to receive key events
        // handler with JavaScript
        Keys.onSpacePressed: {
            increment()
            // spacePresses = spacePresses + 1
        }
        Keys.onEscapePressed: {
            label.text = ''
        }
        // A JavaScript function
        function increment() {
            spacePresses = spacePresses + 1
        }
    }
}
