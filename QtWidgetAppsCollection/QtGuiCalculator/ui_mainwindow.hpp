/*!
 *  \file       ui_mainwindow.hpp
 *  \brief
 *
 */


#pragma once

class QMainWindow;
class QLineEdit;
class QPushButton;

class Ui_MainWindow
{
public:
    QPushButton* plusButton;
    QPushButton* minusButton;
    QPushButton* multiplyButton;
    QPushButton* divideButton;

    QLineEdit* argument1Input;
    QLineEdit* argument2Input;
    QPushButton* aboutButton;
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
