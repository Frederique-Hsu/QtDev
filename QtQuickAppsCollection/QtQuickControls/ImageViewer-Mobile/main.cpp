/*!
 *  \file       main.cpp
 *  \brief      Develop an image viewer application ran on smart phone in Qt QML + C++.
 *
 */


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQuickStyle::setStyle(QString("Material"));

    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreationFailed,
                     &app,
                     []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);

    engine.loadFromModule("ImageViewer-Mobile", "Main");

    return app.exec();
}
