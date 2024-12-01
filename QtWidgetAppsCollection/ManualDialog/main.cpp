/*!
 *  \file       main.cpp
 *  \brief
 *
 */


#include <QApplication>

#include "qwdlg_manual.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWDlgManual dialog;
    dialog.show();

    return app.exec();
}
