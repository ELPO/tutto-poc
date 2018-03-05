QT += quick multimedia
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    Backend.cpp \
    audiorecorder.cpp

RESOURCES += qml.qrc

# Function to copy specified files to build directory
defineTest(copyToBuildDir) {
    files = $$1
    DDIR = $${OUT_PWD}/release

    for(FILE, files) {
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g
        QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}


# SFML
INCLUDEPATH += $$PWD/../3rdParty/SFML/include
win32:CONFIG(release, debug|release): {
    LIBS += -L$$PWD/../3rdParty/SFML/lib/Release/ -lsfml-audio
}

win32 {
    if(isEmpty($$TARGET_EXT))tame
    {
        TARGET_EXT = ".exe"
    }

    DEPLOY_COMMAND = windeployqt
}

CONFIG( debug, debug|release ) {
    # debug
    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/debug/$${TARGET}$${TARGET_EXT}))
} else {
    RELEASE_LIBS = $$PWD/../3rdParty/SFML/bin/Release/sfml-audio-2.dll \
                   $$PWD/../3rdParty/SFML/bin/Release/sfml-system-2.dll \
                   $$PWD/../3rdParty/SFML/bin/Release/openal32.dll
    copyToBuildDir($$RELEASE_LIBS)
    # release
    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/release/$${TARGET}$${TARGET_EXT}))

    # Check if DLLs exist
    for (dll, RELEASE_LIBS) {
        if(!exists($$dll)) {
            message("Cannot find required release library: $${dll}.")
            warning("Please build release $${dll} before building Tutto App.")
        }
    }
}

#  # Uncomment the following line to help debug the deploy command when running qmake
#  warning($${DEPLOY_COMMAND} $${DEPLOY_TARGET})

# Use += instead of = if you use multiple QMAKE_POST_LINKs
QMAKE_POST_LINK += $${DEPLOY_COMMAND} $${DEPLOY_TARGET}

#LIBS += -L"C:\Program Files\boost\boost_1_55_0\stage\lib" -llibboost_locale-vc-mt-1_55

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    scripts/ocr.py \
    scripts/stt.py \
    scripts/tts.py \
    scripts/voiceDetect.py

HEADERS += \
    Backend.h \
    audiorecorder.h
