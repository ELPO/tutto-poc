#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Red);


        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();

        sf::Sound s;
        s.stop();
    }

;

    return 0;
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
