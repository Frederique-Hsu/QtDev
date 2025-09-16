/*!
 *  \file       Rectangle.qml
 *  \brief
 *
 */


import QtQuick

Item {
    width: 200;
    height: 120;

    Rectangle {
        id: rect1;
        x: 12; y:12;
        width: 76; height: 96;
        gradient: Gradient {
            GradientStop { position: 0.0; color: "lightsteelblue"; }
            GradientStop { position: 1.0; color: "slategray"; }
        }
        border.color: "slategray";
    }

    Rectangle {
        id: rect2;
        x: 112; y: 12;
        width: 76; height: 96;
        border.color: "lightsteelblue";
        border.width: 4;
        radius: 8;
    }

}
