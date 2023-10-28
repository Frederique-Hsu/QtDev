/*!
 *  \file       Text_Element.qml
 *  \brief
 *
 */


import QtQuick

Item {
    width: 480;
    height: 240;

    Text {
        text: "The quick brown fox";
        color: "#B03030";
        font {
            family: "Ubuntu";
            pixelSize: 24
        }
        anchors.centerIn: parent;
    }

    Text {
        width: 40; height: 120;
    }
}
