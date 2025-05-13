/*!
 *  \file       main.cpp
 *  \brief      This file implements the main() portal function for current project.
 *
 */


#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/sizingDemo.qml")));

    return app.exec();
}