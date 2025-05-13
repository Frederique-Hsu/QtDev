/*!
 *  \file       SplashView.qml
 *  \brief      Placeholder view displayed while the UI is loading.
 *
 */


import QtQuick 2.13

import assets 1.0

Item {
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackground
        Text {
            anchors.centerIn: parent
            text: "Splash View"
        }
    }
}