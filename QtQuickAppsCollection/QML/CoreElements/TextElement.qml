/*!
 *  \file       TextElement.qml
 *  \brief
 *
 */


import QtQuick


Item {
    id: root
    width: 360
    height: 480

    Text {
        id: label

        text: "The quick brown fox"
        color: "#303030"
        font.family: "Ubuntu"
        font.pixelSize: 28
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    /*
    Text {
        width: 40
        height: 120
        text: "A very long text"
        elide: Text.ElideMiddle
        style: Text.Sunken
        styleColor: "#F4F5F6"
        verticalAlignment: Text.AlignTop
        wrapMode: Text.WordWrap
    }
     */
}
