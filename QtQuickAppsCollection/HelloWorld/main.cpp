/*!
 *  \file       main.cpp
 *  \brief      This file implements the main() entry function for current project.
 *  \author     Frederique Hsu (frederique.hsu@outlook.com)
 *  \date       Tue.    06 Jan. 2026
 *  \copyright  (C) 2026    All rights reserved.
 *
 */


#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
#if true
    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreationFailed,
                     &app,
                     []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);
    engine.loadFromModule("HelloWorld", "Main");
#else
    const QUrl url(QStringLiteral("qrc:/Main.qml"));
    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreated,
                     &app,
                     [url](QObject* obj, const QUrl& objUrl)
                     {
                        if (!obj && (url == objUrl))
                        {
                            QCoreApplication::exit(-1);
                        }
                     },
                     Qt::QueuedConnection);
    engine.load(url);
#endif

    return app.exec();
}
