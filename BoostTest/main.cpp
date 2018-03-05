#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Backend.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>

#include <QTime>
#include <QCoreApplication>

int main(int argc, char *argv[])
{

    if (!sf::SoundBufferRecorder::isAvailable())
    {
        // error: audio capture is not available on this system

    }

    // create the recorder
    sf::SoundBufferRecorder recorder;

    // start the capture
    recorder.start();

    // wait...
    QTime dieTime= QTime::currentTime().addSecs(5);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    // stop the capture
    recorder.stop();

    // retrieve the buffer that contains the captured audio data
    const sf::SoundBuffer& buffer = recorder.getBuffer();
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
}
//#if defined(Q_OS_WIN)
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif

//    QGuiApplication app(argc, argv);

//    qmlRegisterType<Backend>("io.qt.examples.backend", 1, 0, "BackEnd");

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

//    return app.exec();
//}


//#include <string>
//#include <iostream>
//#include <boost/foreach.hpp>

//int main()
//{
//    std::string hello( "Hello, world!" );

//    BOOST_FOREACH( char ch, hello )
//    {
//        std::cout << ch;
//    }

//    return 0;
//}
