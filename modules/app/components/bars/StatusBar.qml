import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../buttons"


Rectangle{
    id: statusBar
    height: 50
    anchors{
        left: parent.left
        top: parent.top
        right: parent.right
    }
    color: Qt.rgba(0,0,0,0)
    
    RowLayout{
        id: buttonRow
        height: statusBar.height
        width: statusBar.width/4
        spacing: 0
        anchors{
            left: statusBar.left
            top: statusBar.top
        }

        CustomButton{
            id: backButton
            text: "Back"
        }

        CustomButton{
            id: homeButton
            text: "Home"
        }

        CustomButton{
            id: exitButton
            text: "Exit"
            onClicked: Qt.quit()
        }

        CustomButton {
            id: doctorButton
            text: "Doctor"
            onClicked: {
                mainLoader.source = "qrc:/desktop-business-app/interfaces/DoctorGraphicalInterface.qml";
            }
        }
    }
}
