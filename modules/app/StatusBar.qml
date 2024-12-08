import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: statusBar
    height: 50
    anchors {
        left: parent.left
        top: parent.top
        right: parent.right
    }
    color: Qt.rgba(0, 0, 0, 0)

    RowLayout {
        id: buttonRow
        height: statusBar.height
        width: parent.width / 4
        spacing: 0

        Button {
            id: backButton
            width: parent.width / 3
            text: "Back"
        }

        Button {
            id: homeButton
            width: parent.width / 3
            text: "Home"
        }

        Button {
            id: exitButton
            width: parent.width / 3
            text: "Exit"
            onClicked: Qt.quit()
        }

        Button {
            id: doctorButton
            width: parent.width / 3
            text: "Doctor"
            onClicked: {
                mainLoader.source = "DoctorGraphicalInterface.qml";
            }
        }
    }
}
