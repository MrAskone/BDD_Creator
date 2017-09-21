import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2

Rectangle {
    width: 400
    height : 400
    color : "lavender"
    id : root
    property int largeurBouton : 140



    Column{
        spacing : 15
        x: 5
        y: 5

        Row{
            Text{
                text: "Welcome to Antoine's BDD Creator!"
                color: "blue"
                font.pixelSize: 20
            }
        }

        Row{
            spacing: 15
            Column{


                FileDialog {
                    id: fileSelect
                    title: "Choose a csv file"

                    onAccepted: {
                        console.log("You chose: " + fileSelect.fileUrl)
                        Context.sendActionToCpp("displayAttributeList", fileSelect.fileUrl)
                        Qt.quit()
                    }
                    onRejected: {
                        console.log("Canceled")
                        Qt.quit()
                    }
                    Component.onCompleted: visible = false
                }


                spacing : 10
                MyButton{
                    id : explorateurfichier
                    text : "Add CSV"
                    onClicked : {
                        fileSelect.visible = true
                    }
                }


                MyButton{
                    id: addToList
                    text : "Add to List"
                    onClicked : {
                        if ( directoryPath.text.length > 0)
                        {
                            Context.sendActionToCpp("addToList", fileSelect.fileUrl)
                        }
                        else
                        {
                            Context.propString = "Error: no value entered"
                        }
                    }
                }

                MyButton{
                    id: deleteLast
                    text : "Delete last entry"
                    onClicked : Context.sendActionToCpp("deleteLast")
                }

                Rectangle{
                    width : explorateurfichier.width
                    height : explorateurfichier.height
                    color: "light gray"
                    border.width: 1
                    border.color: "gray"

                    Text{
                        id: actionResult
                        x: 5
                        anchors.verticalCenter: parent.verticalCenter
                        text: Context.propString
                        color: "green"
                    }
                }
            }


            //        Row {

            //            Rectangle{
            //                id: hider1
            //                height: explorateurfichier.height
            //                width: root.width - 120
            //                color: root.color
            //                z:12
            //                Text{
            //                    text: "Directories:"
            //                    font.pixelSize: 20
            //                    font.underline: true
            //                }
            //            }
            //        }

            Column {

                TableView{
                    id: attributeTableView
                    width : 350
                    headerVisible: false
                    TableViewColumn{
                        width : 300
                    }
                    model: attributesListModel
                    itemDelegate : Item {
                        Text{
                            x : 5
                            //                        anchors.verticalCenter: parent.verticalCenter
                            color: styleData.textColor
                            elide: styleData.elideMode
                            font.pixelSize: 11
                            text: styleData.value // keyword in Qt, it never changes
                        }
                    }
                }
            }

            //        Row {
            //            spacing: 10

            //            MyButton{
            //                id: displayFileList
            //                text : "Display File List"
            //                onClicked : Context.sendActionToCpp("displayFileList")
            //            }
            //            Text{
            //                text: "Choose an extension:"
            //                font.pointSize: 14
            //            }

            //            ComboBox {
            //                id : idCombo
            //                currentIndex: 0
            //                model: extensionListModel
            //                width: 140
            //                height: 24
            //                onCurrentIndexChanged:{
            //                    Context.sendActionToCpp("extensionSelected", currentText)
            //                }
            //            }
            //        }

            //        Row{
            //            TableView{
            //                id: fileTableView
            //                width : 800
            //                headerVisible: false
            //                TableViewColumn{
            //                    width : 700
            //                }
            //                model: myFileListModel
            //                //                selectionMode: SelectionMode.MultiSelection
            //                itemDelegate : Item {
            //                    Text{
            //                        x : 5
            //                        //                        anchors.verticalCenter: parent.verticalCenter
            //                        color: styleData.textColor
            //                        elide: styleData.elideMode
            //                        font.pixelSize: 11
            //                        text: styleData.value // keyword in Qt, it never changes
            //                    }
            //                }
            //            }
            //        }

            //        Row {
            //            spacing: 10

            //            MyButton {
            //                id: fileCombiner
            //                text : "Combine files (new)"
            //                onClicked : {
            //                    Context.sendActionToCpp("combineFiles")
            //                    finalMessage.visible = true
            //                }
            //            }
            //            MyButton {

            //                id: removeSelectedFile
            //                text : "Remove single File"
            //                onClicked :
            //                {
            //                    Context.sendActionToCpp("removeSingleFile", fileTableView.currentRow)
            //                    Context.propString = "File removed from list"
            //                }
            //            }

            //            MyButton {
            //                id: clearAllFiles
            //                text : "Clear all Files"
            //                onClicked :
            //                {
            //                    Context.sendActionToCpp("clearAllFiles")
            //                    Context.propString = "File List cleared"
            //                }
            //            }
            //        }
            //        Row {
            //            spacing: 10

            //            MyButton {
            //                id: append
            //                text : "Append (add to txt)"
            //                onClicked : Context.sendActionToCpp("append", fileTableView.currentRow)
            //            }
            //        }

            //        Row {
            //            spacing: 10

            //            Text{
            //                id: finalMessage
            //                text: "The file name is 'combinedFiles.txt'. If it was successfully created, you will find it in C:/_Projects/CombinedFiles'."
            //                color: "black"
            //                visible: false
            //            }
            //        }

        }


    }
}
