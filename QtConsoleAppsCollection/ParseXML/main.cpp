/*!
 *  \file       main.cpp
 *  \brief      This project study how to parse the XML using Qt
 *
 */


#include <QCoreApplication>
#include <QSslSocket>

#include "WorkerThread.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "Support SSL: " << QSslSocket::supportsSsl();
    qDebug() << "SSL version: " << QSslSocket::sslLibraryBuildVersionString();

    WorkerThread thread(&app);
    thread.fetch("https://raw.githubusercontent.com/PacktPublishing/Application-Development-with-Qt-Creator-Third-Edition/master/Chapter%204/ParsingXml/sample.xml");

    return app.exec();
}
