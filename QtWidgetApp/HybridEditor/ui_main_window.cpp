/*!
 *  \file       ui_main_window.cpp
 *  \brief      Implement the MainWindow UI design only in code.
 *
 */


#include "ui_main_window.hpp"

#include <QMainWindow>

namespace my_ui_design
{
    void Ui_MainWindow::setupUi(QMainWindow* MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
        {
            MainWindow->setObjectName("MainWindow");
        }
        // MainWindow->resize(800, 600);

        actOpen = new QAction(MainWindow);
        actOpen->setObjectName("actOpen");

        QIcon iconOpen;
        iconOpen.addFile(QString::fromUtf8(":/images/images/open.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(iconOpen);
    }
}
