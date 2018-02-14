import QtQuick 2.10
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Rectangle {
    id: testStT

    color: "white"

    AnimatedImage {
        id: recording;
        source: "Resources/playing.gif"

        width: 50
        height: 50

        anchors.horizontalCenter: parent.horizontalCenter
        y: 75

        visible: false
    }

    RowLayout {
        spacing: 8
        width: 200
        anchors.centerIn: parent

        Item {
            Layout.preferredWidth: 10
        }

        Button {
            id: btnStartSpeech

            text: "Talk"

            onClicked: {
                enabled = false
                recording.visible = true
                backend.speechToText(enRb.checked ? "en-US" : "es-ES")
            }
        }

        ExclusiveGroup { id: lang }

        RadioButton {
            id: enRb
            text: "en"
            checked: true
            exclusiveGroup: lang
        }

        RadioButton {
            id: esRb
            text: "es"
            exclusiveGroup: lang
        }
    }

    TextArea {
        id: convertedText

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width - 100
        height: 140
        readOnly: true

        text: backend.convertedText

        onTextChanged: {
            recording.visible = false
            btnStartSpeech.enabled = true
        }
    }
}
