/*!
 *  \file       main.cpp
 *  \brief      Implement the main() entry function for project TaskMaster
 *  \author     Frederique Hsu (frederique.hsu@outlook.com)
 *  \date       Thu.    08 Jan. 2026
 *  \copyright  (C) 2026    All rights reserved.
 *
 */


#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(&engine,
                     &QQmlApplicationEngine::objectCreationFailed,
                     &app,
                     []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);
    engine.loadFromModule("TaskMaster", "Main");

    return app.exec();
}
