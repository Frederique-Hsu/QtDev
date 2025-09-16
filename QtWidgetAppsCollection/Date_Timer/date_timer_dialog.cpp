/*!
 *  \file       date_timer_dialog.cpp
 *  \brief
 *
 */


#include "date_timer_dialog.hpp"
#include "date_timer_dialog_ui.hpp"

#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QProgressBar>
#include <QTimeEdit>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QCalendarWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>

DateTimerDialog::DateTimerDialog(QWidget *parent) : QDialog(parent), ui{new UI::DateTimerDialog}
{
    ui->setupUI(this);

    timer = new QTimer(this);
    timer->stop();
    timer->setInterval(1000);   // unit: msec
    QObject::connect(timer, &QTimer::timeout, this, &DateTimerDialog::onTimerTimeout);

    QObject::connect(ui->get_date_time_button,
                     &QPushButton::clicked,
                     this,
                     &DateTimerDialog::onGetDateTimeButtonClicked);
    QObject::connect(ui->calendar,
                     &QCalendarWidget::selectionChanged,
                     this,
                     &DateTimerDialog::onCalendarSelectionChanged);
    QObject::connect(ui->set_time_button,
                     &QPushButton::clicked,
                     this,
                     &DateTimerDialog::onSetTimeButtonClicked);
    QObject::connect(ui->set_date_button,
                     &QPushButton::clicked,
                     this,
                     &DateTimerDialog::onSetDateButtonClicked);
    QObject::connect(ui->set_date_time_button,
                     &QPushButton::clicked,
                     this,
                     &DateTimerDialog::onSetDateTimeButtonClicked);
    QObject::connect(ui->set_interval_button,
                     &QPushButton::clicked,
                     this,
                     &DateTimerDialog::onSetIntervalButtonClicked);
    QObject::connect(ui->start_button,
                     &QPushButton::clicked,
                     this,
                     &DateTimerDialog::onStartButtonClicked);
    QObject::connect(ui->stop_button,
                     &QPushButton::clicked,
                     this,
                     &DateTimerDialog::onStopButtonClicked);
    QObject::connect(ui->exit_button,
                     &QPushButton::clicked,
                     this,
                     &DateTimerDialog::close);
}

DateTimerDialog::~DateTimerDialog()
{
    if (ui != nullptr)
    {
        delete ui;
        ui = nullptr;
    }
}

void DateTimerDialog::onTimerTimeout()
{
    QTime curr_time = QTime::currentTime();
    ui->hour_lcd->display(curr_time.hour());
    ui->min_lcd->display(curr_time.minute());
    ui->sec_lcd->display(curr_time.second());

    int progress_value = ui->progress_bar->value();
    progress_value++;
    if (progress_value > 100)
    {
        progress_value = 0;
    }
    ui->progress_bar->setValue(progress_value);
}

void DateTimerDialog::onGetDateTimeButtonClicked()
{
    QDateTime curr_date_time = QDateTime::currentDateTime();
    ui->time_edit->setTime(curr_date_time.time());
    ui->time_line_edit->setText(curr_date_time.toString("hh:mm:ss"));

    ui->date_edit->setDate(curr_date_time.date());
    ui->date_line_edit->setText(curr_date_time.toString("yyyy-MM-dd"));

    ui->date_time_edit->setDateTime(curr_date_time);
    ui->date_time_line_edit->setText(curr_date_time.toString("yyyy-MM-dd hh:mm:ss"));
}

void DateTimerDialog::onCalendarSelectionChanged()
{
    QDate date = ui->calendar->selectedDate();
    QString date_str = date.toString("yyyy年M月d日");
    ui->calendar_line_edit->setText(date_str);
}

void DateTimerDialog::onSetTimeButtonClicked()
{
    QString time_str = ui->time_line_edit->text();
    if (!time_str.isEmpty())
    {
        QTime time = QTime::fromString(time_str, "hh:mm:s");
        ui->time_edit->setTime(time);
    }
}

void DateTimerDialog::onSetDateButtonClicked()
{
    QString date_str = ui->date_line_edit->text();
    date_str = date_str.trimmed();
    if (!date_str.isEmpty())
    {
        QDate date = QDate::fromString(date_str, "yyyy-MM-dd");
        ui->date_edit->setDate(date);
    }
}

void DateTimerDialog::onSetDateTimeButtonClicked()
{
    QString date_time_str = ui->date_time_line_edit->text();
    date_time_str = date_time_str.trimmed();
    if (!date_time_str.isEmpty())
    {
        QDateTime date_time = QDateTime::fromString(date_time_str, "yyyy-MM-dd hh:mm:ss");
        ui->date_time_edit->setDateTime(date_time);
    }
}

void DateTimerDialog::onSetIntervalButtonClicked()
{
    timer->setInterval(ui->time_spinbox->value());
}

void DateTimerDialog::onStartButtonClicked()
{
    timer->start();

    ui->start_button->setEnabled(false);
    ui->stop_button->setEnabled(true);
    ui->set_interval_button->setEnabled(false);
}

void DateTimerDialog::onStopButtonClicked()
{
    timer->stop();
    std::chrono::milliseconds msec = timer->intervalAsDuration();

    int seconds = msec.count() / 1000;
    int msecs = msec.count() % 1000;

    QString elapsed_time_str = QString::asprintf("流逝时间：%d 秒 %d 毫秒", seconds, msecs);
    ui->elapsed_time_label->setText(elapsed_time_str);

    ui->start_button->setEnabled(true);
    ui->stop_button->setEnabled(false);
    ui->set_interval_button->setEnabled(true);
}
