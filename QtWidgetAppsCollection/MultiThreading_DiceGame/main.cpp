/*!
 *  \file       main.cpp
 *  \brief      
 *  
 */



#include <QApplication>

#include "Dialog.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Dialog dialog;
    dialog.show();

    return app.exec();
}
