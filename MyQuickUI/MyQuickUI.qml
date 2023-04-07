import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit()
        }
    }

    // title: qsTr("Hello World")
    Text {
        anchors.centerIn: parent
        text: "Hello QML World!"
    }
}
