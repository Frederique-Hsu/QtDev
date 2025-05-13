/*!
 *  \file       date_timer_dialog.hpp
 *  \brief
 *
 */


#pragma once


#include <QDialog>

class DateTimerDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DateTimerDialog(QWidget *parent = nullptr);
    ~DateTimerDialog();
};
