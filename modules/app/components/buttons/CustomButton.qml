import QtQuick
import QtQuick.Controls

Button {
    id: customButton
    property alias buttonText: customButton.text

    width: 150
    height: 50
    background: Rectangle {
        color: customButton.pressed ? "#a6a6a6" : "#d9d9d9"
        border.color: "#5a5a5a"
        radius: 10
        border.width: 2
    }
    contentItem: Text {
        text: customButton.text
        font.pixelSize: 16
        font.bold: true
        color: "#333333"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }
}