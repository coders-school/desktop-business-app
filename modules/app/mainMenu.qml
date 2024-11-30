import QtQuick
import QtQuick.Controls 

Rectangle {
    id: mainMenuRect
    visible: true
    color: "lightblue"

    StatusBar{
        id: statusBar
    }

    Rectangle{
        anchors{
            left: parent.left
            right: parent.right
            top: statusBar.bottom
            bottom: parent.bottom
        }
        color: "green"
    }
}

