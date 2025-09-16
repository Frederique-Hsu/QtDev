/*!
 *  \file       date_timer_dialog_ui.cpp
 *  \brief
 *
 */


#include "date_timer_dialog_ui.hpp"

#include <QCoreApplication>

#include <QGroupBox>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QTimeEdit>
#include <QLineEdit>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QSpinBox>
#include <QLCDNumber>
#include <QProgressBar>
#include <QCalendarWidget>


void DateTimerDialogUI::setupUI(QDialog *main_dialog)
{
    if (main_dialog->objectName().isEmpty())
    {
        main_dialog->setObjectName(QString("main_dialog"));
    }

    {
    date_time_groupbox = new QGroupBox(main_dialog);
    date_time_groupbox->setObjectName(QString("date_time_groupbox"));
    QGridLayout *gridlayout_for_date_time_groupbox = new QGridLayout(date_time_groupbox);
    gridlayout_for_date_time_groupbox->setSpacing(6);
    gridlayout_for_date_time_groupbox->setContentsMargins(11, 11, 11, 11);

    get_date_time_button = new QPushButton(date_time_groupbox);
    get_date_time_button->setObjectName(QString("get_date_time_button"));
    gridlayout_for_date_time_groupbox->addWidget(get_date_time_button, 0, 0, 1, 2);

    display_date_time_label = new QLabel(date_time_groupbox);
    display_date_time_label->setObjectName(QString("display_date_time_label"));
    display_date_time_label->setAlignment(Qt::AlignCenter);
    gridlayout_for_date_time_groupbox->addWidget(display_date_time_label, 0, 3, 1, 1);

    time_label = new QLabel(date_time_groupbox);
    time_label->setObjectName(QString("time_label"));
    gridlayout_for_date_time_groupbox->addWidget(time_label, 1, 0, 1, 1);

    time_edit = new QTimeEdit(date_time_groupbox);
    time_edit->setObjectName(QString("time_edit"));
    time_edit->setCalendarPopup(true);
    time_edit->setTime(QTime(15, 30, 25));
    gridlayout_for_date_time_groupbox->addWidget(time_edit, 1, 1, 1, 1);

    time_line_edit = new QLineEdit(date_time_groupbox);
    time_line_edit->setObjectName(QString("time_line_edit"));
    gridlayout_for_date_time_groupbox->addWidget(time_line_edit, 1, 3, 1, 1);

    set_time_button = new QPushButton(date_time_groupbox);
    set_time_button->setObjectName(QString("set_time_button"));
    gridlayout_for_date_time_groupbox->addWidget(set_time_button, 1, 4, 1, 1);

    date_label = new QLabel(date_time_groupbox);
    date_label->setObjectName(QString("date_label"));
    gridlayout_for_date_time_groupbox->addWidget(date_label, 2, 0, 1, 1);

    date_edit = new QDateEdit(date_time_groupbox);
    date_edit->setObjectName(QString("date_edit"));
    date_edit->setCurrentSection(QDateTimeEdit::YearSection);
    date_edit->setCalendarPopup(true);
    date_edit->setCurrentSectionIndex(0);
    date_edit->setDate(QDate(2025, 8, 12));
    gridlayout_for_date_time_groupbox->addWidget(date_edit, 2, 1, 1, 1);

    date_line_edit = new QLineEdit(date_time_groupbox);
    date_line_edit->setObjectName(QString("date_line_edit"));
    gridlayout_for_date_time_groupbox->addWidget(date_line_edit, 2, 3, 1, 1);

    set_date_button = new QPushButton(date_time_groupbox);
    set_date_button->setObjectName(QString("set_date_button"));
    gridlayout_for_date_time_groupbox->addWidget(set_date_button, 2, 4, 1, 1);

    date_time_label = new QLabel(date_time_groupbox);
    date_time_label->setObjectName(QString("date_time_label"));
    gridlayout_for_date_time_groupbox->addWidget(date_time_label, 3, 0, 1, 1);

    date_time_edit = new QDateTimeEdit(date_time_groupbox);
    date_time_edit->setObjectName(QString("date_time_edit"));
    date_time_edit->setMinimumSize(QSize(160, 0));
    date_time_edit->setDateTime(QDateTime(QDate(2020, 9, 24), QTime(19, 38, 9)));
    date_time_edit->setMaximumDateTime(QDateTime(QDate(3000, 12, 31), QTime(23, 59, 59)));
    date_time_edit->setMinimumDateTime(QDateTime(QDate(1500, 1, 1), QTime(0, 0, 0)));
    date_time_edit->setCurrentSection(QDateTimeEdit::YearSection);
    date_time_edit->setCalendarPopup(false);
    date_time_edit->setCurrentSectionIndex(0);
    date_time_edit->setTimeZone(QTimeZone::utc());
    gridlayout_for_date_time_groupbox->addWidget(date_time_edit, 3, 1, 1, 1);

    date_time_line_edit = new QLineEdit(date_time_groupbox);
    date_time_line_edit->setObjectName(QString("date_time_line_edit"));
    date_time_line_edit->setMinimumSize(QSize(150, 0));
    gridlayout_for_date_time_groupbox->addWidget(date_time_line_edit, 3, 3, 1, 1);

    set_date_time_button = new QPushButton(date_time_groupbox);
    set_date_time_button->setObjectName(QString("set_date_time_button"));
    gridlayout_for_date_time_groupbox->addWidget(set_date_time_button, 3, 4, 1, 1);
    }

    {
    timer_groupbox = new QGroupBox(main_dialog);
    timer_groupbox->setObjectName(QString("timer_groupbox"));

    QGridLayout *gridlayout_for_timer_groupbox = new QGridLayout();
    gridlayout_for_timer_groupbox->setSpacing(6);

    start_button = new QPushButton(timer_groupbox);
    start_button->setObjectName(QString("start_button"));
    gridlayout_for_timer_groupbox->addWidget(start_button, 0, 0, 1, 2);

    stop_button = new QPushButton(timer_groupbox);
    stop_button->setObjectName(QString("stop_button"));
    stop_button->setEnabled(false);
    gridlayout_for_timer_groupbox->addWidget(stop_button, 0, 2, 1, 2);

    elapsed_time_label = new QLabel(timer_groupbox);
    elapsed_time_label->setObjectName(QString("elapsed_time_label"));
    gridlayout_for_timer_groupbox->addWidget(elapsed_time_label, 0, 5, 1, 1);

    timer_cycle_label = new QLabel(timer_groupbox);
    timer_cycle_label->setObjectName(QString("timer_cycle_label"));
    gridlayout_for_timer_groupbox->addWidget(timer_cycle_label, 1, 0, 1, 1);

    time_spinbox = new QSpinBox(timer_groupbox);
    time_spinbox->setObjectName(QString("time_spinbox"));
    time_spinbox->setMaximum(999'999);
    time_spinbox->setValue(1000);
    gridlayout_for_timer_groupbox->addWidget(time_spinbox, 1, 1, 1, 2);

    set_interval_button = new QPushButton(timer_groupbox);
    set_interval_button->setObjectName(QString("set_interval_button"));
    gridlayout_for_timer_groupbox->addWidget(set_interval_button, 1, 3, 1, 2);

    QSpacerItem *hspacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
    gridlayout_for_timer_groupbox->addItem(hspacer, 1, 5, 1, 1);

    hour_lcd = new QLCDNumber(timer_groupbox);
    hour_lcd->setObjectName(QString("hour_lcd"));
    hour_lcd->setSmallDecimalPoint(false);
    hour_lcd->setDigitCount(2);
    hour_lcd->setProperty("value", QVariant(10.000000));
    hour_lcd->setProperty("intValue", QVariant(10));

    min_lcd = new QLCDNumber(timer_groupbox);
    min_lcd->setObjectName(QString("min_lcd"));
    min_lcd->setDigitCount(2);
    min_lcd->setProperty("intValue", QVariant(26));

    sec_lcd = new QLCDNumber(timer_groupbox);
    sec_lcd->setObjectName(QString("sec_lcd"));
    sec_lcd->setDigitCount(2);
    sec_lcd->setProperty("intValue", QVariant(35));

    QHBoxLayout *hlayout_for_lcd = new QHBoxLayout();
    hlayout_for_lcd->setSpacing(6);
    hlayout_for_lcd->addWidget(hour_lcd);
    hlayout_for_lcd->addWidget(min_lcd);
    hlayout_for_lcd->addWidget(sec_lcd);

    progress_bar = new QProgressBar(timer_groupbox);
    progress_bar->setObjectName(QString("progress_bar"));
    progress_bar->setValue(10);
    progress_bar->setTextVisible(true);

    QVBoxLayout *vlayout_for_timer_group = new QVBoxLayout(timer_groupbox);
    vlayout_for_timer_group->setSpacing(6);
    vlayout_for_timer_group->setContentsMargins(11, 11, 11, 11);

    vlayout_for_timer_group->addLayout(gridlayout_for_timer_groupbox);
    vlayout_for_timer_group->addLayout(hlayout_for_lcd);
    vlayout_for_timer_group->addWidget(progress_bar);
    }

    QVBoxLayout *left_vlayout = new QVBoxLayout();
    left_vlayout->setSpacing(6);
    left_vlayout->addWidget(date_time_groupbox);
    left_vlayout->addWidget(timer_groupbox);

    {
    calendar_groupbox = new QGroupBox(main_dialog);
    calendar_groupbox->setObjectName(QString("calendar_groupbox"));

    QGridLayout *gridlayout_for_calendar_groupbox = new QGridLayout(calendar_groupbox);
    gridlayout_for_calendar_groupbox->setSpacing(6);
    gridlayout_for_calendar_groupbox->setContentsMargins(11, 11, 11, 11);

    selected_date_label = new QLabel(calendar_groupbox);
    selected_date_label->setObjectName(QString("selected_date_label"));
    gridlayout_for_calendar_groupbox->addWidget(selected_date_label, 0, 0, 1, 1);

    calendar_line_edit = new QLineEdit(calendar_groupbox);
    calendar_line_edit->setObjectName(QString("calendar_line_edit"));
    gridlayout_for_calendar_groupbox->addWidget(calendar_line_edit, 0, 1, 1, 1);

    calendar = new QCalendarWidget(calendar_groupbox);
    calendar->setObjectName(QString("calendar"));
    calendar->setGridVisible(false);
    gridlayout_for_calendar_groupbox->addWidget(calendar, 1, 0, 1, 2);
    }

    QSpacerItem *vspacer1 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
    QSpacerItem *vspacer2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

    exit_button = new QPushButton(main_dialog);
    exit_button->setObjectName(QString("exit_button"));

    QVBoxLayout *right_vlayout = new QVBoxLayout();
    right_vlayout->setSpacing(6);
    right_vlayout->addWidget(calendar_groupbox);
    right_vlayout->addItem(vspacer1);
    right_vlayout->addWidget(exit_button);
    right_vlayout->addItem(vspacer2);

    QHBoxLayout *parent_window_hlayout = new QHBoxLayout(main_dialog);
    parent_window_hlayout->setSpacing(6);
    parent_window_hlayout->setContentsMargins(11, 11, 11, 11);

    parent_window_hlayout->addLayout(left_vlayout);
    parent_window_hlayout->addLayout(right_vlayout);

    retranslateUI(main_dialog);
}

void DateTimerDialogUI::retranslateUI(QDialog *main_dialog)
{
    main_dialog->setWindowTitle(QCoreApplication::translate("main_dialog", "日期时间，定时器", nullptr));

    {
    date_time_groupbox->setTitle(QCoreApplication::translate("main_dialog", "日期时间", nullptr));
    get_date_time_button->setText(QCoreApplication::translate("main_dialog", "读取当前日期时间", nullptr));
    display_date_time_label->setText(QCoreApplication::translate("main_dialog", "字符串显示", nullptr));
    time_label->setText(QCoreApplication::translate("main_dialog", "时间", nullptr));
    set_time_button->setText(QCoreApplication::translate("main_dialog", "设置时间", nullptr));
    date_label->setText(QCoreApplication::translate("main_dialog", "日期", nullptr));
    set_date_button->setText(QCoreApplication::translate("main_dialog", "设置日期", nullptr));
    date_time_label->setText(QCoreApplication::translate("main_dialog", "日期时间", nullptr));
    set_date_time_button->setText(QCoreApplication::translate("main_dialog", "设置日期时间", nullptr));
    }

    {
    timer_groupbox->setTitle(QCoreApplication::translate("main_dialog", "定时器", nullptr));
    start_button->setText(QCoreApplication::translate("main_dialog", "开始", nullptr));
    stop_button->setText(QCoreApplication::translate("main_dialog", "停止", nullptr));
    elapsed_time_label->setText(QCoreApplication::translate("main_dialog", "流逝时间", nullptr));
    timer_cycle_label->setText(QCoreApplication::translate("main_dialog", "定时周期", nullptr));
    time_spinbox->setSuffix(QCoreApplication::translate("main_dialog", " ms", nullptr));
    set_interval_button->setText(QCoreApplication::translate("main_dialog", "设置周期", nullptr));
    }

    {
    selected_date_label->setText(QCoreApplication::translate("main_dialog", "选择的日期", nullptr));
    exit_button->setText(QCoreApplication::translate("main_dialog", "退出", nullptr));
    }
}
