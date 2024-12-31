/*!
 *  \file       SoccerBallAnimation.qml
 *  \brief
 *
 */


import QtQuick

Item {
    id: root

    property int duration: 3000

    width: 480
    height: 300

    Rectangle {
        id: sky
        width: parent.width
        height: 200
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#0080FF" }
            GradientStop { position: 1.0; color: "#66CCFF" }
        }
    }
    Rectangle {
        id: ground
        anchors.top: sky.bottom
        anchors.bottom: root.bottom
        width: parent.width
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#00FF00" }
            GradientStop { position: 1.0; color: "#00803F" }
        }
    }

    Image {
        id: soccer_ball
        x: 0
        y: root.height - height
        scale: 0.6
        source: "assets/soccer_ball.png"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                soccer_ball.x = 0
                soccer_ball.y = root.height - soccer_ball.height
                soccer_ball.rotation = 0
                anim.restart()
            }
        }
    }

    ParallelAnimation {
        id: anim

        SequentialAnimation {
            NumberAnimation {
                target: soccer_ball
                properties: "y"
                to: 20
                duration: root.duration * 0.4
                easing.type: Easing.OutCirc
            }
            NumberAnimation {
                target: soccer_ball
                properties: "y"
                to: root.height - soccer_ball.height
                duration: root.duration * 0.6
                easing.type: Easing.OutBounce
            }
        }
        NumberAnimation {
            target: soccer_ball
            properties: "x"
            to: root.width - soccer_ball.width
            duration: root.duration
        }
        RotationAnimation {
            target: soccer_ball
            properties: "rotation"
            to: 720
            duration: root.duration
        }
    }
}
