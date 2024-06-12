/*!
 *  \file       mainwindow.hpp
 *  \brief      Define the UI of main-window
 *
 */


#pragma once

#include <QMainWindow>
#include <QPair>

namespace Ui
{
    class MainWindow;
}

class ResultDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    typedef QPair<float, float> Arguments;
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow* ui;
    ResultDialog* results;
public slots:
    void OnAboutButtonClicked();
    void OnPlusButtonClicked();
    void OnMinusButtonClicked();
    void OnMultiplyButtonClicked();
    void OnDivideButtonClicked();

    void ShowResult(float res);
signals:
    void computed(float f);
public:
    Arguments arguments();
};
