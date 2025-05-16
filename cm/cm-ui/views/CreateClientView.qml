/*!
 *  \file       CreateClientView.qml
 *  \brief      View for entering details of a new client
 *
 */


import QtQuick 2.13

import assets 1.0
import components 1.0

Item {
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackground

        Text {
            anchors.centerIn: parent
            text: "Create Client View"
        }
    }

    CommandBar {
        commandList: master_controller.ui_commandController.ui_createClientViewContextCommands
    }
}
