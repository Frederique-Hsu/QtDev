/*!
 *  \file       main.cpp
 *  \brief
 *
 */


#include "date_timer_dialog.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DateTimerDialog dialog;
    dialog.show();

    return app.exec();
}