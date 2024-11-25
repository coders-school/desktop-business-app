import QtQuick
import QtQuick.Controls 

Window {
    id: root
    visible: true
    visibility: Window.Maximized
    color: "lightblue"
    minimumHeight: height
    minimumWidth: width

    Loader {
        id: mainLoader
        active: true
        anchors{
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
        source: "loginScreen.qml"
    }
}

