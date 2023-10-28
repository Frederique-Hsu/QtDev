/*!
 *  \file       main.cpp
 *  \brief      Study the Qt Foundamental and core features.
 *
 */


#include "qmywidget.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMyWidget widget;
    widget.show();

    return app.exec();
}
