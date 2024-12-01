/*!
 *  \file       main.qml
 *  \brief      
 *  
 */


import QtQuick

Image {
    id: root;
    source: "images/background.png";

    Image {
        id: pole;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.bottom: parent.bottom;
        source: "images/pole.png";
    }

    Image {
        id: wheel;
        anchors.centerIn: parent;
        source: "images/pinwheel.png";

        onWidthChanged: print(width);

        Behavior on rotation {
            NumberAnimation {
                duration: 250;
            }
        }
    }

    MouseArea {
        anchors.fill: parent;
        onClicked: wheel.rotation += 90;
    }
}
