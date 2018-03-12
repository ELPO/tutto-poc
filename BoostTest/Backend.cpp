#include "Backend.h"

#include <QDebug>
#include <QCoreApplication>
#include <QTemporaryFile>
#include <QStandardPaths>

Backend::Backend(QObject *parent)
    : QObject(parent)
    , m_speechFile()
    , m_recorder(std::make_unique<AudioRecorder>())
{
    if (!sf::SoundBufferRecorder::isAvailable())
    {
        // error: audio capture is not available on this system

    }

    // create the recorder


    // start the capture
    m_recorder->start();
    // stop the capture

}

Backend::~Backend()
{
    m_recorder->stop();
    // retrieve the buffer that contains the captured audio data
    const sf::SoundBuffer& buffer = m_recorder->getBuffer();
    buffer.saveToFile("C://Users//Sommerwild//Desktop//audios//test.wav");
}

void Backend::textToSpeech (const QString &text, const QString &lang)
{
    QString scriptPath =  QCoreApplication::applicationDirPath() + "/../../BoostTest/scripts/tts.py";
    QFile scriptFile(scriptPath);
    if (!scriptFile.exists()){
        qDebug() << "Error no tts scriptfile";
        return;
    }

    QTemporaryFile file;
    if (file.open()) {
        const QString &fileName = file.fileName();
        QProcess *process = new QProcess();
        connect(process, static_cast<void (QProcess::*)(int)>(&QProcess::finished), [&]() {
            setSpeechFile(fileName);
            speechFileChanged();
        });

        connect(process, static_cast<void (QProcess::*)(int)>(&QProcess::finished), process, &QProcess::deleteLater);

        QStringList pythonCommandArguments = QStringList() << scriptPath
            << text << lang << file.fileName();

        qDebug() << "PyCommand: " << pythonCommandArguments;
        process->start ("python", pythonCommandArguments);

    } else {
        qDebug() << "Temp file creation failed, TtS aborted";
    }
}

void Backend::speechToText (const QString &lang)
{
    QString scriptPath =  QCoreApplication::applicationDirPath() + "/../../BoostTest/scripts/stt.py";
    QFile scriptFile(scriptPath);
    if (!scriptFile.exists()){
        qDebug() << "Error no sts scriptfile";
        return;
    }

    QTemporaryFile *file = new QTemporaryFile();
    if (file->open()) {
        QProcess *process = new QProcess();
        connect(process, static_cast<void (QProcess::*)(int)>(&QProcess::finished), [&]() {
            setConvertedText(file->readAll());
            file->deleteLater();
            convertedTextChanged();
        });

        connect(process, static_cast<void (QProcess::*)(int)>(&QProcess::finished), process, &QProcess::deleteLater);

        QStringList pythonCommandArguments = QStringList() << scriptPath
                                                           << lang << file->fileName();

        qDebug() << "PyCommand: " << pythonCommandArguments;
        process->start ("python", pythonCommandArguments);

    } else {
        qDebug() << "Temp file creation failed, StT aborted";
    }
}

void Backend::ocr(const QString &imgPath)
{
    QString imPath =  QCoreApplication::applicationDirPath() + "/../../BoostTest/scripts/ts.jpg";
    QFile scriptFile(imPath);
    if (!scriptFile.exists()){
        qDebug() << "Error no sts scriptfile";
        return;
    }

    QTemporaryFile *file = new QTemporaryFile();
    if (file->open()) {
        QProcess *process = new QProcess();
        connect(process, static_cast<void (QProcess::*)(int)>(&QProcess::finished), [&]() {
            //setConvertedText(file->readAll());
            file->deleteLater();
            //convertedTextChanged();
        });

        connect(process, static_cast<void (QProcess::*)(int)>(&QProcess::finished), process, &QProcess::deleteLater);

        QStringList tesseractCommandArguments = QStringList() << imgPath;

        qDebug() << "TessCommand: " << tesseractCommandArguments;
        process->start ("tesseract.exe", tesseractCommandArguments);

    } else {
        qDebug() << "Temp file creation failed, StT aborted";
    }
}

QString Backend::speechFile()
{
    return m_speechFile;
}

void Backend::setSpeechFile(const QString &speechFile)
{
    m_speechFile = speechFile;
}

QString Backend::convertedText()
{
    return m_convertedText;
}

void Backend::setConvertedText(const QString &convertedText)
{
    m_convertedText = convertedText;
}
