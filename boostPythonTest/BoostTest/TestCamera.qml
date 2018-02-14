import QtQuick 2.10

import QtMultimedia 5.8
import QtQuick.Controls 1.4


VideoOutput {
    id: viewfinder
    visible: true

    anchors.fill: parent

    source: camera
    autoOrientation: true

    Rectangle {
        id: topOp
        anchors.top: parent.top
        width: parent.width
        height: parent.height / 3.0
        opacity: 0.5
    }

    Rectangle {
        id:botOp
        anchors.bottom: parent.bottom
        width: parent.width
        height: parent.height / 3.0
        opacity: 0.5
    }

    Rectangle {
        anchors.bottom: botOp.top
        width: parent.width / 4.0
        height: parent.height / 3.0
        opacity: 0.5
        anchors.left: parent.left
        anchors.top: topOp.bottom
    }

    Rectangle {
        width: parent.width / 4.0
        height: parent.height / 3.0
        opacity: 0.5
        anchors.right: parent.right
        anchors.top: topOp.bottom
        anchors.bottom: botOp.top
    }

    Button {
        id: captureBtn
        anchors.horizontalCenter: parent.horizontalCenter
        y: parent.height / 1.3

        text: "Capture"

        onClicked: {
            enabled = false
            camera.imageCapture.capture()
        }
    }

    Camera {
        id: camera

        captureMode: Camera.CaptureStillImage

        videoRecorder {
             resolution: "1200x720"
             frameRate: 30
        }

        imageCapture {
            id: ic

            resolution: "1200x720"
            onImageSaved: {
                backend.ocr(path)
            }
        }
    }
}





