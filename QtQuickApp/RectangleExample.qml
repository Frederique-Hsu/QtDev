/*!
 *  \file       RectangleExample.qml
 *  \brief
 *
 */


import QtQuick

Rectangle {     // The root element is the Rectangle
    id: root;   // name this element root

    // properties: <name>: <value>
    width: 120;
    height: 240;
    color: "#4A4A4A";

    // Declare a nested element (child of root)
    Image {
        id: triangle;

        x: (parent.width - width)/2;    // reference the parent
        y: 40;
        source: "Assets/triangle_red.png";
    }

    Text {
        // un-named element

        y: triangle.y + triangle.height + 20;
        width: root.width;      // reference root element
        color: "white"
        horizontalAlignment: Text.AlignHCenter;
        text: "Triangle";
    }

    Text {
        id: thisLabel;                                          // (1) identifier
        x: 24; y: 16;                                           // (2) set x- and y- position
        height: 2 * width;                                      // (3) bind height to 2 * width
        property int times: 24;                                 // (4) custom property
        property alias anotherTimes: thisLabel.times;           // (5) property alias
        text: "Greetings " + times;                             // (6) set text appended by value
        font.family: "Ubuntu";                                  // (7) font is a grouped property
        font.pixelSize: 24;
        KeyNavigation.tab: label;                          // (8) KeyNavigation is an attached property
        onHeightChanged: console.log('height: ', height)        // (9) signal handler for property changes
        focus: true;                                            //     focus is need to receive key events
        color: focus ? "red" : "black";                         //     change color based on focus value
    }

    Text {
        id: label;
        x: 24; y: 48;
        property int spacePresses: 0;                           // custom counter property for space presses
        text: "Space pressed: " + spacePresses + " times";
        onTextChanged: function(text) {                         // handler for text changes. Need to use function to capture parameters
            console.log("text changed to: ", text);
        }
        focus: true;                                            // need focus to receive key events
        Keys.onSpacePressed: {                                  // handler with some JavaScript
            increment();
        }
        Keys.onEscapePressed: {                                 // clear the text on escape
            label.text = ''
        }
        function increment() {                                  // a JavaScript function
            spacePresses = spacePresses + 1
        }
    }
}
