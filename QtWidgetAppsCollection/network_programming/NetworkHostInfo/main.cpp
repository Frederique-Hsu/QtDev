/*!
 *  \file       main.cpp
 *  \brief
 *
 */


#include <QApplication>
#include <QDebug>

#include "Dialog.hpp"

int main(int argc, char *argv[])
{
    qDebug() << "Current C++ standard no. is " << __cplusplus << Qt::endl;
    qDebug() << "Current program is " << sizeof(void*) * 8 << "-bits." << Qt::endl;

    QApplication app(argc, argv);

    Dialog dialog;
    dialog.show();

    return app.exec();
}
