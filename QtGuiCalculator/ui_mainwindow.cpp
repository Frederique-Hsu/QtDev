/*!
 *  \file       ui_mainwindow.cpp
 *  \brief
 *
 */


#include "ui_mainwindow.hpp"

#include <QMainWindow>

void Ui_MainWindow::setupUi(QMainWindow* mainwindow)
{
    if (mainwindow->objectName().isEmpty())
    {
        mainwindow->setObjectName(QString::fromUtf8("mainwindow"));
    }
}
