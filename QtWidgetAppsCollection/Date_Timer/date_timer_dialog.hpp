/*!
 *  \file       date_timer_dialog.hpp
 *  \brief
 *
 */


#pragma once


#include <QDialog>
#include <QTime>

namespace UI
{
    class DateTimerDialog;
}

class QTimer;
class QTime;

class DateTimerDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DateTimerDialog(QWidget *parent = nullptr);
    ~DateTimerDialog();

private:
    UI::DateTimerDialog *ui;

private slots:
    void onTimerTimeout();
    void onGetDateTimeButtonClicked();
    void onCalendarSelectionChanged();
    void onSetTimeButtonClicked();
    void onSetDateButtonClicked();
    void onSetDateTimeButtonClicked();
    void onSetIntervalButtonClicked();
    void onStartButtonClicked();
    void onStopButtonClicked();

private:
    QTimer *timer;
    // QTime time_counter;
};
