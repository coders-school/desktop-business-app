import QtQuick
import QtQuick.Controls
import "qrc:/desktop-business-app/components/bars"

Rectangle {
    id: receptionistMainRect
    visible: true
    color: "lightblue"

    StatusBar{
        id: statusBar
    }

    Rectangle{
        id: receptionistRect
        anchors{
            left: parent.left
            right: parent.right
            top: statusBar.bottom
            bottom: parent.bottom
        }
        color: "lightblue"

        Text{
            text: "Receptionist Graphical Interface"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            font.pixelSize: 24
        }

        Row{
            id: headerRow
            anchors {
                top: parent.top
                topMargin: 60
                left: parent.left
                leftMargin: 10
                right: parent.right
                rightMargin: 10
            }
            spacing: 1
            Rectangle {
                width: parent.width/5
                height: 40
                color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "First Name"
                    color: "white"
                }
            }
            Rectangle {
                width: parent.width/5
                height: 40
                color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "Last Name"
                    color: "white"
                }
            }
            Rectangle {
                width: parent.width/5
                height: 40
                color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "Date"
                    color: "white"
                }
            }
            Rectangle {
                width: parent.width/5
                height: 40
                color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "Treatment"
                    color: "white"
                }
            }
            Rectangle {
                width: parent.width/5
                height: 40
                color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "Room"
                    color: "white"
                }
            }
        }
    }

    TableView {
        id: tableView
        anchors {
            top: headerRow.bottom
            left: headerRow.left
            right: headerRow.right
            bottom: parent.bottom
            bottomMargin: 20
        }
        model: receptionistModel
        delegate: Rectangle {
            implicitWidth: parent.width / 5
            implicitHeight: 40
            border.color: "black"
            Text {
                    anchors.centerIn: parent
                    text: model.display
                }
        }
        clip: true
    }
}