import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
            fichierTab.open
        }
    }

    Menu{
        id: fichierTab
        title: "Fichier"

        MenuItem{
            text: "first item"
        }
        MenuItem{
            text: "second item"
        }
        MenuItem{
            text: "third item"
        }

    }
    Menu{
        id: editTab
        title: "Edit"

        MenuItem{
            text: "first edit"
        }
        MenuItem{
            text: "second edit"
        }
        MenuItem{
            text: "third edit"
        }

    }

    TextEdit {
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }
}
