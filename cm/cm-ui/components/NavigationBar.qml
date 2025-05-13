import QtQuick 2.13

import assets 1.0

Item {
    property bool isCollapsed: true

    anchors {
        top: parent.top
        bottom: parent.bottom
        left: parent.left
    }
    width: isCollapsed ? Style.widthNavigationBarCollapsed : Style.heightNavigationBarExpanded

    Rectangle {
        anchors.fill: parent
        color: Style.colourNavigationBarBackgroud

        Column {
            width: parent.width

            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
                hoverColour: "#993333"
                onNavigationButtonClicked: isCollapsed = !isCollapsed
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Dashboard"
                hoverColour: "#DC8A00"
                onNavigationButtonClicked: {
                    isCollapsed = !isCollapsed
                    master_controller.ui_navigationController.goDashboardView()
                }
            }
            NavigationButton {
                iconCharacter: "\uf234"
                description: "New Client"
                hoverColour: "#DCCD00"
                onNavigationButtonClicked: {
                    isCollapsed = !isCollapsed
                    master_controller.ui_navigationController.goCreateClientView()
                }
            }
            NavigationButton {
                iconCharacter: "\uf002"
                description: "Find Client"
                hoverColour: "#8AEF63"
                onNavigationButtonClicked: {
                    isCollapsed = !isCollapsed
                    master_controller.ui_navigationController.goFindClientView()
                }
            }
        }
    }
}
