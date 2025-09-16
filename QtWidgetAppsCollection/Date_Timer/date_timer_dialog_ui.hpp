/*!
 *  \file       date_timer_dialog_ui.hpp
 *  \brief
 *
 */


#pragma once

#include <QDialog>

class QGroupBox;
class QLabel;
class QTimeEdit;
class QLineEdit;
class QDateEdit;
class QDateTimeEdit;
class QSpinBox;
class QLCDNumber;
class QProgressBar;
class QCalendarWidget;


class DateTimerDialogUI
{
public:
    QPushButton *get_date_time_button;
    QTimeEdit *time_edit;
    QLineEdit *time_line_edit;
    QPushButton *set_time_button;
    QDateEdit *date_edit;
    QLineEdit *date_line_edit;
    QPushButton *set_date_button;
    QDateTimeEdit *date_time_edit;
    QLineEdit *date_time_line_edit;
    QPushButton *set_date_time_button;

    QPushButton *start_button;
    QPushButton *stop_button;
    QLabel *elapsed_time_label;
    QSpinBox *time_spinbox;
    QPushButton *set_interval_button;

    QLCDNumber *hour_lcd, *min_lcd, *sec_lcd;
    QProgressBar *progress_bar;

    QLineEdit *calendar_line_edit;
    QCalendarWidget *calendar;
    QPushButton *exit_button;

private:
    QGroupBox *date_time_groupbox;
    QLabel *display_date_time_label;
    QLabel *time_label;
    QLabel *date_label;
    QLabel *date_time_label;

    QGroupBox *timer_groupbox;
    QLabel *timer_cycle_label;

    QGroupBox *calendar_groupbox;
    QLabel *selected_date_label;

public:
    void setupUI(QDialog *main_dialog);
    void retranslateUI(QDialog *main_dialog);
};

namespace UI
{
    class DateTimerDialog : public DateTimerDialogUI
    {
    };
}
