import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import Qt.labs.platform 1.0
import QtQuick.Dialogs 1.2


ApplicationWindow {
    id: root
    visible: true
    width: 1000
    height: 600
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
Column{
    spacing: 5
    y: 5
    x: 5
    Row{
        spacing: 10

        MyButton{
            id: openExplorerForCsv

            text: "Select Csv File"

            onClicked: {
                explorerToPickCsv.visible= true
            }

        }

        FileDialog{
            id: explorerToPickCsv
            visible: false
            title: "Select a Csv"

            onAccepted: {
                console.log("You selected: " + explorerToPickCsv.fileUrl)
            }

            onRejected: {
                console.log("Window closed")
            }

        }

        Rectangle{

            height: openExplorerForCsv.height
            width: root.width - openExplorerForCsv.width - 20
            color: "lightgrey"

            Text{
                text: explorerToPickCsv.fileUrl
            }
        }
    }

        Row{
            MyButton{
                onClicked: DataParser.loadFromCsv(explorerToPickCsv.fileUrl)
            }
        }


}
}
