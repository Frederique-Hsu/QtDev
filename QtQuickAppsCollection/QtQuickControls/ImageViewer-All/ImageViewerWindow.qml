/*!
 *  \file       ImageViewerWindow.qml
 *  \brief
 *
 */


import QtQuick
import QtQuick.Controls
import Qt.labs.platform as Platform


ApplicationWindow {

    function openFileDialog()
    {
        fileOpenDialog.open();
    }

    function openAboutDialog()
    {
        aboutDialog.open();
    }

    visible: true
    title: qsTr("Image Viewer")

    background: Rectangle {
        color: "darkGray"
    }
    Image {
        id: image
        anchors.fill: parent
        fillMode:
    }
}
