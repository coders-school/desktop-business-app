import QtQuick
import QtQuick.Controls
import DoctorApp 1.0

ApplicationWindow {
    visible: true
    width: Screen.width
    height: Screen.height
    title: "Doctor Graphical Interface"

    DoctorModel {
        id: doctorModel
    }

    Rectangle {
        anchors.fill: parent
        color: "lightblue"

        Text {
            text: "Doctor Graphical Interface"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
            font.pixelSize: 24
        }

        Row {
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
                width: tableView.width / 5
                height: 40
                color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "First Name"
                    color: "white"
                }
            }
            Rectangle {
                width: tableView.width / 5
                height: 40
                color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "Last Name"
                    color: "white"
                }
            }
            Rectangle {
                width: tableView.width / 5
                height: 40
                color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "Date"
                    color: "white"
                }
            }
            Rectangle {
                width: tableView.width / 5
                height: 40
                color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "Treatment"
                    color: "white"
                }
            }
            Rectangle {
                width: tableView.width / 5
                height: 40
                color: "gray"
                Text {
                    anchors.centerIn: parent
                    text: "Room"
                    color: "white"
                }
            }
        }

        TableView {
            id: tableView
            anchors {
                top: headerRow.bottom
                left: headerRow.left
                right: headerRow.right
                bottom: addButton.top
                bottomMargin: 20
            }
            model: doctorModel

            delegate: Rectangle {
                implicitWidth: headerRow.width / 5
                implicitHeight: 40
                border.color: "black"
                Text {
                    anchors.centerIn: parent
                    text: model.display
                }
            }

            clip: true
        }

        Button {
            id: addButton
            text: "Add Appointment"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            onClicked: {
                doctorModel.addAppointment("Anna", "Smith", "2024-12-06", "Consultation", "202");
            }
        }

        Button {
            id: backButton
            text: "Back"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.rightMargin: 10
            onClicked: {
                mainLoader.source = "mainMenu.qml"
            }
        }
    }
}
