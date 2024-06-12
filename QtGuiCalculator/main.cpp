/*!
 *  \file       main.cpp
 *  \brief      Develop a GUI application to calculator
 *
 */



#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow wnd;
    wnd.show();

    return app.exec();
}
