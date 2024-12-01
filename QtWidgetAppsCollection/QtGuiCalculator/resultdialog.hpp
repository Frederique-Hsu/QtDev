/*!
 *  \file       resultdialog.hpp
 *  \brief
 *
 */


#pragma once


#include <QDialog>

namespace Ui
{
    class Dialog;
}

class ResultDialog : public QDialog
{
    Q_OBJECT
public:
    ResultDialog(QWidget* parent = nullptr);
    ~ResultDialog();
private:
    Ui::Dialog* ui;
public:
    void setResult(float r);
};
