/*!
 *  \file       EasingCurvesAnimation.qml
 *  \brief
 *
 */


import QtQuick
import QtQuick.Layouts


Rectangle {
    id: root
    width: childrenRect.width
    height: childrenRect.height

    color: "#4A4A4A"
    gradient: Gradient {
        GradientStop { position: 0.0; color: root.color }
        GradientStop { position: 1.0; color: Qt.lighter(root.color) }
    }

    ColumnLayout {
        Grid {
            spacing: 8
            columns: 5

            // Row #1
            EasingType {
                easingType: Easing.Linear
                title: "Linear"
                onClicked: {
                    animation.easing.type = easingType
                    box.toggle = !box.toggle
                }
            }
            EasingType {
                easingType: Easing.InExpo
                title: "InExpo"
                onClicked: {
                    animation.easing.type = easingType
                    box.toggle = !box.toggle
                }
            }
            EasingType {
                easingType: Easing.OutExpo
                title: "OutExpo"
                onClicked: {
                    animation.easing.type = easingType
                    box.toggle = !box.toggle
                }
            }
            EasingType {
                easingType: Easing.InOutExpo
                title: "InOutExpo"
                onClicked: {
                    animation.easing.type = easingType
                    box.toggle = !box.toggle
                }
            }
            EasingType {
                easingType: Easing.InOutCubic
                title: "InoutCubic"
                onClicked: {
                    animation.easing.type = easingType
                    box.toggle = !box.toggle
                }
            }

            // Row #2
            EasingType {
                easingType: Easing.SineCurve
                title: "SineCurve"
                onClicked: {
                    animation.easing.type = easingType
                    box.toggle = !box.toggle
                }
            }
            EasingType {
                easingType: Easing.InOutCirc
                title: "InOutCirc"
                onClicked: {
                    animation.easing.type = easingType
                    box.toggle = !box.toggle
                }
            }
            EasingType {
                easingType: Easing.InOutElastic
                title: "InOutElastic"
                onClicked: {
                    animation.easing.type = easingType
                    box.toggle = !box.toggle
                }
            }
            EasingType {
                easingType: Easing.InOutBack
                title: "InOutBack"
                onClicked: {
                    animation.easing.type = easingType
                    box.toggle = !box.toggle
                }
            }
            EasingType {
                easingType: Easing.InOutBounce
                title: "InOutBounce"
                onClicked: {
                    animation.easing.type = easingType
                    box.toggle = !box.toggle
                }
            }
        }
        Item {
            height: 80
            Layout.fillWidth: true

            Box {
                id: box
                property bool toggle

                x: toggle ? 20 : root.width - width - 20

                anchors.verticalCenter: parent.verticalCenter
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#2ED5FA" }
                    GradientStop { position: 1.0; color: "#2467EC" }
                }
                Behavior on x {
                    NumberAnimation {
                        id: animation
                        duration: 500
                    }
                }
            }
        }
    }
}
