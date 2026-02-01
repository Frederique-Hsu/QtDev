/*!
 *  \file       Dialog.cpp
 *  \brief      
 *  
 */


#include "Dialog.hpp"

#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>

#include "DiceThread.hpp"
#include "Ui_Dialog.hpp"

Dialog::Dialog(QWidget *parent) : QDialog(parent), m_dice_thread(new DiceThread()), m_ui(new Ui::Dialog)
{
    m_ui->setupUi(this);

    QObject::connect(m_dice_thread, &QThread::started, this, &Dialog::Slot_onDiceThreadStarted);
    QObject::connect(m_dice_thread, &QThread::finished, this, &Dialog::Slot_onDiceThreadFinished);
    QObject::connect(m_dice_thread, &DiceThread::newValue, this, &Dialog::Slot_onDiceThreadNewValueArrived);

    QObject::connect(m_ui->button_start_thread, &QPushButton::clicked, this, &Dialog::Slot_onStartThreadButtonClicked);
    QObject::connect(m_ui->button_begin_dice, &QPushButton::clicked, this, &Dialog::Slot_onBeginDiceButtonClicked);
    QObject::connect(m_ui->button_pause_dice, &QPushButton::clicked, this, &Dialog::Slot_onPauseDiceButtonClicked);
    QObject::connect(m_ui->button_terminate_thread, &QPushButton::clicked, this, &Dialog::Slot_onTerminateThreadButtonClicked);
    QObject::connect(m_ui->button_clean_text, &QPushButton::clicked, this, &Dialog::Slot_onCleanButtonClicked);
}

Dialog::~Dialog()
{
    if (m_dice_thread)
    {
        delete m_dice_thread;
        m_dice_thread = nullptr;
    }
    if (m_ui)
    {
        delete m_ui;
        m_ui = nullptr;
    }
}

void Dialog::Slot_onDiceThreadStarted()
{
    m_ui->label_bottom_showstatus->setText(QObject::tr("Thread status: Thread started"));
}

void Dialog::Slot_onDiceThreadFinished()
{
    m_ui->label_bottom_showstatus->setText(QObject::tr("Thread status: Thread finished"));
}

void Dialog::Slot_onDiceThreadNewValueArrived(int seq, int dice_value)
{
    QString str = QString::asprintf("第%d次掷骰子， 点数为： %d", seq, dice_value);
    m_ui->plain_text_edit->appendPlainText(str);

    QPixmap dice_picture;
    QString pic_filename = QString::asprintf(":/dice/images/d%d.jpg", dice_value);
    dice_picture.load(pic_filename);
    m_ui->label_dice_picture->setPixmap(dice_picture);
}

void Dialog::Slot_onCleanButtonClicked()
{
    m_ui->plain_text_edit->clear();
}

void Dialog::Slot_onStartThreadButtonClicked()
{
    m_dice_thread->start();
    m_ui->button_start_thread->setEnabled(false);
    m_ui->button_terminate_thread->setEnabled(true);
    m_ui->button_begin_dice->setEnabled(true);
    m_ui->button_pause_dice->setEnabled(false);
}

void Dialog::Slot_onBeginDiceButtonClicked()
{
    m_dice_thread->beginDice();
    m_ui->button_begin_dice->setEnabled(false);
    m_ui->button_pause_dice->setEnabled(true);
}

void Dialog::Slot_onPauseDiceButtonClicked()
{
    m_dice_thread->pauseDice();
    m_ui->button_begin_dice->setEnabled(true);
    m_ui->button_pause_dice->setEnabled(false);
}

void Dialog::Slot_onTerminateThreadButtonClicked()
{
    m_dice_thread->stopThread();
    m_dice_thread->wait();

    m_ui->button_start_thread->setEnabled(true);
    m_ui->button_terminate_thread->setEnabled(false);
    m_ui->button_begin_dice->setEnabled(false);
    m_ui->button_pause_dice->setEnabled(false);
}

void Dialog::closeEvent(QCloseEvent *event)
{
    if (m_dice_thread->isRunning())
    {
        m_dice_thread->stopThread();
        m_dice_thread->wait();
    }
    event->accept();
}
