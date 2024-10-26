import QtQuick
import com.company.desktopbusinessapp

Window {
    id: root
    width: 640
    height: 480
    visible: true
    
    Rectangle {
        Application {
            id: application
        }
        id: rec
        anchors.fill: parent
        color: "green"
        anchors{
            top: parent.top
            verticalCenter: parent.verticalCenter
        }
        Text {
          width: rec.width
          elide: Text.ElideRight
          fontSizeMode: Text.Fit
          minimumPixelSize: 10
          color: "white"
          anchors.fill: parent
          text: application.GetData()
          font {
            pixelSize: 20
            bold: true
          }
        }
    }
}