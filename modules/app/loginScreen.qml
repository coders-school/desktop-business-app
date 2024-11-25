import QtQuick
import QtQuick.Controls 

Rectangle {
    id: loginScreenRect
    // visible: true
    color: "lightblue"

    Loader {
        id: loginLoader
        anchors{
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        } 
    }

    Rectangle {
        id: rect1
        width: 600
        height: 250
        color: "lightblue"
        border.color: "black"
        border.width: 5
        radius: 10
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Rectangle{
            id: loginRect
            width: 500
            height: 40
            color: "lightblue"
            border.color: "black"
            border.width: 2
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 30

            TextField{
                id: loginTextField
                width: parent.width
                height: parent.height
                placeholderText: "Login:"
                placeholderTextColor: "black"
                background: null
                color: "black"
                anchors.centerIn: parent
                font.pointSize: parent.height*0.6
            }
        }   

        Rectangle{
            id: passwordRect
            width: 500
            height: 40
            color: "lightblue"
            border.color: "black"
            border.width: 2
            anchors.top: loginRect.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 15

            TextField{
                id: passwordTextField
                width: parent.width
                height: parent.height
                placeholderText: "Password:"
                placeholderTextColor: "black"
                background: null
                color: "black"
                anchors.centerIn: parent
                font.pointSize: parent.height*0.6
            }
        }

        Rectangle{
            id: recoverPasswordRect
            anchors.top: passwordRect.bottom
            anchors.left: passwordRect.left
            anchors.topMargin: 15
            width: 250
            height: 40
            color: parent.color

            Text{
                id: recoverPasswordText
                text: "Recover password"
                font.pointSize: 16
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
               
                color: if (recoverPasswordMouseArea.containsMouse)
                {
                    return Qt.darker(root.color)
                }
                else
                {
                    return "black"
                }
            }

            MouseArea{
                id: recoverPasswordMouseArea
                anchors.fill: recoverPasswordText
                hoverEnabled: true
                onClicked: {
                    // Fun stuff will be here...
                }
            }
        }

        Rectangle{
            id: settingsRectangle
            anchors.top: recoverPasswordRect.bottom
            anchors.left: recoverPasswordRect.left
            anchors.topMargin: 10
            width: 250
            height: 40
            color: parent.color

            Text{
                id: settingsText
                text: "Settings"
                font.pointSize: 16
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
               
                color: if (settingsMouseArea.containsMouse)
                {
                    return Qt.darker(root.color)
                }
                else
                {
                    return "black"
                }
            }

            MouseArea{
                id: settingsMouseArea
                anchors.fill: settingsText
                hoverEnabled: true
                onClicked: {
                    // Fun stuff will be here...
                }
            }
        }

        Rectangle{
            id: loginButtonRect
            width: 250
            height: 40
            color: "lightblue"
            border.color: "black"
            border.width: 2
            anchors.top: passwordRect.bottom
            anchors.right: passwordRect.right
            anchors.topMargin: 15

            Text{
                id: loginButtonText
                width: parent.width
                height: parent.height
                text: "Login"
                anchors.centerIn: parent
                font.pointSize: parent.height*0.6

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                color: if (loginButtonMouseArea.containsMouse)
                {
                    return Qt.darker(root.color)
                }
                else
                {
                    return "black"
                }
            }

            MouseArea{
                id: loginButtonMouseArea
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    rect1.visible = false
                    loginLoader.source = "mainMenu.qml"
                }
            }
        }
    }
}