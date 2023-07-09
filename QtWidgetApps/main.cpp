/*!
 *  \file       main.cpp
 *  \brief
 *
 */



#include <QtGui>
#include <QApplication>

#include "custom_widget.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QScopedPointer<QWidget> widget(new CustomWidget());
    widget->resize(240, 120);
    widget->show();

    return app.exec();
}
