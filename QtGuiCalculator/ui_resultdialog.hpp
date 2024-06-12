/*!
 *  \file       ui_resultdialog.hpp
 *  \brief
 *
 */


#pragma once


#include <QDialog>

class QLabel;
class QDialogButtonBox;

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel* resultLabel;
    QLabel* valueLabel;
    QDialogButtonBox* buttonBox;
public:
    void setupUi(QDialog* dialog);
    void retranslateUi(QDialog* dialog);
};

namespace Ui
{
    class Dialog : public Ui_Dialog
    {
    };
}

QT_END_NAMESPACE
