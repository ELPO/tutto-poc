#include "audiorecorder.h"

#include <QTime>
#include <QCoreApplication>
#include <QDebug>

AudioRecorder::AudioRecorder() :
    sf::SoundRecorder()
{
    // first check if an input audio device is available on the system
//    if (!sf::SoundBufferRecorder::isAvailable())
//    {
//        // error: audio capture is not available on this system

//    }

//    // create the recorder
//    sf::SoundBufferRecorder recorder;

//    // start the capture
//    recorder.start();

//    // wait...
//    QTime dieTime= QTime::currentTime().addSecs(5);
//    while (QTime::currentTime() < dieTime)
//        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

//    // stop the capture
//    recorder.stop();

//    // retrieve the buffer that contains the captured audio data
//    const sf::SoundBuffer& buffer = recorder.getBuffer();
//    sf::Sound sound;
//    sound.setBuffer(buffer);
//    sound.play();
}

bool AudioRecorder::onStart()
{
    return true;
}

bool AudioRecorder::onProcessSamples(const sf::Int16* Samples, std::size_t SamplesCount)
{
    qDebug() << SamplesCount;
    return true;
}

void AudioRecorder::onStop()
{

}
