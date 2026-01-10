/*!
 *  \file       Main.qml
 *  \brief      Implement the Main Window UI for application TaskMaster
 *  \author     Frederique Hsu (frederique.hsu@outlook.com)
 *  \date       Thu.    08 Jan. 2026
 *  \copyright  (C) 2026    All rights reserved.
 *
 */


import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Task-Master")

    StackView {
        id: contentFrame
        anchors.fill: parent

        initialItem: Qt.resolvedUrl("Load_Page.qml")
    }
}
