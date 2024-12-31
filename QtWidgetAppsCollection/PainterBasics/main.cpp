/*!
 *  \file       main.cpp
 *  \brief
 *
 */


#include "paint_widget.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PaintWidget widget;
    widget.show();

    return app.exec();
}
