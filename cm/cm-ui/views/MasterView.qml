/*!
 *  \file       MasterView.qml
 *  \brief
 *
 */


import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13

import assets 1.0
import components 1.0

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Client Management")

    Connections {
        target: master_controller.ui_navigationController
        function onGoCreateClientView()
        {
            contentFrame.replace(Qt.resolvedUrl("qrc:/views/CreateClientView.qml"));
        }
        function onGoDashboardView()
        {
            contentFrame.replace(Qt.resolvedUrl("qrc:/views/DashboardView.qml"));
        }
        function onGoEditClientView(EditClientView)
        {
            contentFrame.replace(Qt.resolvedUrl("qrc:/views/EditClientView.qml"),
                                 {selectedClient: client});
        }
        function onGoFindClientView()
        {
            contentFrame.replace(Qt.resolvedUrl("qrc:/views/FindClientView.qml"));
        }
    }

    NavigationBar {
        id: navigationBar
    }

    StackView {
        id: contentFrame
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.right
        }
        initialItem: Qt.resolvedUrl("qrc:/views/SplashView.qml")
        clip: true
    }

    Component.onCompleted: contentFrame.replace(Qt.resolvedUrl("qrc:/views/DashboardView.qml"))
}
