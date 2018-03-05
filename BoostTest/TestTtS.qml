import QtQuick 2.10
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtMultimedia 5.8

Rectangle {
    id: testStT

    color: "white"

    AnimatedImage {
        id: playing;
        source: "Resources/playing.gif"

        width: 50
        height: 50

        anchors.horizontalCenter: parent.horizontalCenter
        y: 75

        visible: false

        Component.onCompleted: {
            playSpeech.playing.connect(onPlay)
            playSpeech.stopped.connect(onStop)
        }

        function onPlay() {
            visible = true
        }

        function onStop() {
            visible = false
        }
    }


    RowLayout {
        spacing: 8
        width: parent.width
        anchors.centerIn: parent

        Item {
            Layout.preferredWidth: 10
        }

        TextField {
            id: textField
            placeholderText: "Insert Text"
            Layout.preferredWidth: 250
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

        Button {
            id: btnSpeech
            text: "Speech"

            onClicked: {
                if (textField.text !== "") {
                    var langText = enRb.checked ? "en" : "es"
                    var speechText = textField.text
                    textField.text = ""
                    btnSpeech.enabled = false
                    backend.textToSpeech(speechText, langText)
                }
            }
        }

        Audio {
            id: playSpeech

            source: backend.speechFile
            autoPlay: true

            onStopped: btnSpeech.enabled = true
        }
    }
}
