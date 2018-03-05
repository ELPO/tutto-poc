#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QProcess>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString speechFile READ speechFile WRITE setSpeechFile NOTIFY speechFileChanged)
    Q_PROPERTY(QString convertedText READ convertedText WRITE setConvertedText NOTIFY convertedTextChanged)
public:
    explicit Backend(QObject *parent = nullptr);

    Q_INVOKABLE void textToSpeech (const QString &text, const QString &lang);
    Q_INVOKABLE void speechToText (const QString &lang);
    Q_INVOKABLE void ocr(const QString &imgPath);

    QString speechFile();
    void setSpeechFile(const QString &speechFile);

    QString convertedText();
    void setConvertedText(const QString &speechFile);

signals:
    void speechFileChanged();
    void convertedTextChanged();
    void speechToTextFinished();
    void textToSpeechFinished();

private:
    QString m_speechFile;
    QString m_convertedText;
};

#endif // BACKEND_H
