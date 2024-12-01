/*!
 *  \file       resultdialog.cpp
 *  \brief
 *
 */


#include "resultdialog.hpp"

#include "ui_resultdialog.hpp"

#include <QLabel>

ResultDialog::ResultDialog(QWidget* parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

ResultDialog::~ResultDialog()
{
    if (ui != nullptr)
    {
        delete ui;
    }
}

void ResultDialog::setResult(float r)
{
    ui->valueLabel->setText(QString::number(r));
}
