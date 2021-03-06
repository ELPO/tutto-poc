#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "backend.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<Backend>("io.qt.examples.backend", 1, 0, "BackEnd");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}


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
