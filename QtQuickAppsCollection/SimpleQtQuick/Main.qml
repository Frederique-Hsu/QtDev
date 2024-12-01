import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Simple Qt Quick")

    Rectangle {
        width: 240
        height: 240
        border.color: "#FFAABB"

        /*
        ListView {
            width: 180
            height: 120
            anchors.centerIn: parent
            model: cityModel
            delegate: Text { text: model.city }
        }
         */

        Rectangle {
            width: 40; height: 40;
            anchors.centerIn: parent
            color: "#FFBB33"
        }
    }
}
