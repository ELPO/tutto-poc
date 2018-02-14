import QtQuick 2.10
import QtQuick.Window 2.10

import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtGraphicalEffects 1.0

import io.qt.examples.backend 1.0


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Tutto_PoC_1.0")

    BackEnd {
        id: backend
    }

    Rectangle {
        anchors.fill: parent
        color: "black"

        Rectangle {
            id: screen

            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter

            width: 600
            height: 450

            focus: true

            color: "white"

            Rectangle {
                id: buttonsMenu

                width: 150
                height: parent.height
                anchors.left: parent.left
                anchors.top: parent.top
                color: "#57a9df"
                visible: true

                ColumnLayout {
                    anchors.fill: parent

                    Button {
                        text: "Launch Demo"
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignCenter

                        onClicked: {
                            loading.activeScreen = 4
                        }
                    }

                    Button {
                        text: "Test Camera"
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignCenter

                        onClicked: {
                            loading.activeScreen = 1
                        }
                    }

                    Button {
                        text: "Test StT"
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignCenter

                        onClicked: {
                            loading.activeScreen = 2
                        }
                    }

                    Button {
                        text: "Test TtS"
                        Layout.fillWidth: true
                        Layout.alignment: Qt.AlignCenter

                        onClicked: {
                            loading.activeScreen = 3
                        }
                    }
                }
            }

            Rectangle {
                id: loading

                anchors.left: buttonsMenu.right
                width: parent.width - buttonsMenu.width
                height: parent.height

                property int activeScreen: 0

                TestCamera {
                    id: testCamera

                    anchors.fill: parent

                    visible:  loading.activeScreen === 1
                }

                TestStT {
                    id: testStT

                    anchors.fill: parent

                    visible: loading.activeScreen === 2
                }

                TestTtS {
                    id: testTsS

                    anchors.fill: parent

                    visible: loading.activeScreen === 3
                }
            }

            Keys.onEscapePressed: {
                Qt.quit()
            }
        }
    }

    Component.onCompleted: {
        showFullScreen(true)
    }
}
