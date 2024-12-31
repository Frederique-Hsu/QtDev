/*!
 *  \file       ClickableImageAnimationl.qml
 *  \brief
 *
 */


import QtQuick


Item {
    id: root
    width: background.width
    height: background.height

    Image {
        id: background
        source: "assets/background_medium.png"
    }

    MouseArea {
        id: area
        anchors.fill: parent
        onClicked: {
            greenBox.y = blueBox.y = redBox.y = 205
        }
    }

    // #region animation-on-property
    ClickableImage {
        id: greenBox
        x: 40
        y: root.height - height
        source: "assets/box_green.png"

        text: qsTr("Animation on property")
        NumberAnimation on y {
            to: 40
            duration: 4000
        }
    }
    // #endregion

    // #region behaviour on property
    ClickableImage {
        id: blueBox
        x: (root.width - width)/2
        y: root.height - height
        source: "assets/box_blue.png"

        text: qsTr("Behaviour on property")
        Behavior on y {
            NumberAnimation {
                duration: 4000
            }
        }

        onClicked: y = 40
        // onClicked: y = 40 + Math.random() * (205 - 40)
    }
    // #endregion

    // #region standalone-animation
    ClickableImage {
        id: redBox
        x: root.width - width - 40
        y: root.height - height
        source: "assets/box_red.png"

        onClicked: anim.start()
        // onClicked: anim.restart()

        text: qsTr("Standalone animation")

        NumberAnimation {
            id: anim
            target: redBox
            properties: "y"
            to: 100
            duration: 4000
        }
    }
    // #endregion
}
