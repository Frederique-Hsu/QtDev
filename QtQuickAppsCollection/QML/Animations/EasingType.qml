/*!
 *  \file       EasingType.qml
 *  \brief
 *
 */


import QtQuick

Rectangle {
    id: root

    property real value: 0.0
    property int pointCount: 100
    property string title

    property alias easingType: anim.easing.type

    signal clicked()

    width: 100
    height: 100
    clip: true

    Image {
        anchors.fill: parent
        source: "assets/blueprint.jpg"
    }
    Rectangle {
        anchors.fill: view
        anchors.leftMargin: -8
        anchors.rightMargin: -8
        color: "transparent"
        border.color: "#53D769"
        border.width: 4
        opacity: 0.5
    }
    NumberAnimation {
        id: anim
        target: root
        property: 'value'
        from: 0
        to: 1
        duration: 2000
    }
    ListModel {
        id: valueModel
    }
    AnimationController {
        id: controller
        animation: anim
        Component.onCompleted: {
            valueModel.clear()
            for (var i = 0; i < root.pointCount; i++)
            {
                progress = i / root.pointCount;
                valueModel.append({value: root.value});
            }
        }
    }
    PathView {
        id: view
        anchors.fill: parent
        anchors.topMargin: root.height * 0.2
        anchors.bottomMargin: root.height * 0.2
        model: valueModel
        pathItemCount: root.pointCount
        delegate: Item {
            id: delegate
            required property var model
            width: 4
            height: 4
            Rectangle {
                width: parent.width
                height: width
                radius: width/2
                y: -delegate.model.value * view.height
                color: "#FF8800"
                border.color: Qt.lighter(color, 1.2)
                opacity: 0.5
            }
        }
        path: Path {
            startX: 0
            startY: view.height
            PathLine {
                x: view.width
                y: view.height
            }
        }
    }
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        color: "#FFF"
        font.pixelSize: 14
        text: root.title
    }
    MouseArea {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
