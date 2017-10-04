import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import Qt.labs.platform 1.0


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    header: ToolBar{
        id: menuBar

        RowLayout {
            anchors.fill: parent

            ToolButton {
                text: qsTr("‹")
                onClicked: stack.pop()
            }
            Label {
                text: "Title"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            ToolButton {
                text: qsTr("⋮")
                onClicked: menu.open()
            }

        }
    }
//    MenuBar {
//        id: menuBar



//        Menu {
//            id: fileMenu
//            title: qsTr("File")

//            MenuItem {
//                text: qsTr("Zoom In")
//                shortcut: StandardKey.ZoomIn
//                onTriggered: zoomIn()
//            }

//            MenuItem {
//                text: qsTr("Zoom Out")
//                shortcut: StandardKey.ZoomOut
//                onTriggered: zoomOut()
//            }
//        }

//        Menu {
//            id: editMenu
//            title: qsTr("&Edit")
//            MenuItem {
//                text: qsTr("Zoom In")
//                shortcut: StandardKey.ZoomIn
//                onTriggered: zoomIn()
//            }

//            MenuItem {
//                text: qsTr("Zoom Out")
//                shortcut: StandardKey.ZoomOut
//                onTriggered: zoomOut()
//            }
//        }

//        Menu {
//            id: viewMenu
//            title: qsTr("&View")
//            MenuItem {
//                text: qsTr("Zoom In")
//                shortcut: StandardKey.ZoomIn
//                onTriggered: zoomIn()
//            }

//            MenuItem {
//                text: qsTr("Zoom Out")
//                shortcut: StandardKey.ZoomOut
//                onTriggered: zoomOut()
//            }
//        }

//        Menu {
//            id: helpMenu
//            title: qsTr("&Help")
//            MenuItem {
//                text: qsTr("Zoom In")
//                shortcut: StandardKey.ZoomIn
//                onTriggered: zoomIn()
//            }

//            MenuItem {
//                text: qsTr("Zoom Out")
//                shortcut: StandardKey.ZoomOut
//                onTriggered: zoomOut()
//            }
//        }
//    }




    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }



    TextEdit {
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        onTextChanged: {
            DataParser.setMessageToUser(text)
            console.log("text changed")
        }
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }
}
