/*!
 *  \file       ui_mainwindow.hpp
 *  \brief
 *
 */


#pragma once

class QMainWindow;

class Ui_MainWindow
{
public:
public:
    void setupUi(QMainWindow* mainwindow);
    void retranslateUi(QMainWindow* mainwindow);
};

namespace Ui
{
    class MainWindow : public Ui_MainWindow
    {
    };
}
