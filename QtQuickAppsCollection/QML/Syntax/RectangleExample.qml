/*!
 *  \file       RectangleExample.qml
 *  \brief
 *
 */


import QtQuick

Rectangle {         // the root element is the Rectangle
    id: root        // name this element as root

    width: 120
    height: 240
    color: "#4A4A4A"

    Image {         // declare a nested element (child of root)
        id: triangle

        x: (parent.width - width)/2
        y: 40

        source: 'assets/triangle_red.png'
    }

    Text {          // another child of root
        y: triangle.y + triangle.height + 20    // reference element by id

        width: root.width
        color: 'white'
        horizontalAlignment: Text.AlignHCenter
        text: 'Triangle'
    }
}
