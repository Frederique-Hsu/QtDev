/*!
 *  \file       StateTransition.qml
 *  \brief
 *
 */


import QtQuick


Rectangle {
    id: root

    property color black: "#1F1F1F"
    property color red: "#FC3D39"
    property color green: "#53D769"

    width: childrenRect.width + 25
    height: childrenRect.height + 15

    // gradient: Gradient {
    //     GradientStop { position: 0.0; color: "#2ED5FA" }
    //     GradientStop { position: 1.0; color: "#2467EC" }
    // }

    Rectangle {
        id: red_light
        x: 25; y: 15
        width: 100
        height: width
        radius: width/2
        color: root.black   // default color
        border.color: Qt.lighter(color, 1.1)
    }
    Rectangle {
        id: green_light
        x: 25; y: 135
        width: 100
        height: width
        radius: width/2
        color: root.black
        border.color: Qt.lighter(color, 1.1)
    }
    Text {
        id: state_text
        anchors.horizontalCenter: green_light.horizontalCenter
        anchors.top: green_light.bottom
        y: green_light.bottom + 10
    }

    state: "stop"

    states: [
        State {
            name: "go"
            PropertyChanges {
                target: red_light; color: root.black
            }
            PropertyChanges {
                target: green_light; color: root.green
            }
        },
        State {
            name: "stop"
            PropertyChanges { target: red_light;    color: root.red }
            PropertyChanges { target: green_light;  color: root.black }
        }
    ]

    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.state = (parent.state === "stop" ? "go" : "stop")
            state_text.text = parent.state
        }
    }

    transitions: [
        Transition {
            from: "stop"; to: "go"
            ColorAnimation { target: red_light;     properties: "color";    duration: 2000 }
            ColorAnimation { target: green_light;   properties: "color";    duration: 2000 }
        }
    ]
}
