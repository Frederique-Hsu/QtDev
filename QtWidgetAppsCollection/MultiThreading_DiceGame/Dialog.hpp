/*!
 *  \file       Dialog.hpp
 *  \brief      
 *  
 */


#pragma once


#include <QDialog>

class DiceThread;

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    DiceThread *m_dice_thread;

    Ui::Dialog *m_ui;

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void Slot_onDiceThreadStarted();
    void Slot_onDiceThreadFinished();
    void Slot_onDiceThreadNewValueArrived(int seq, int dice_value);

    void Slot_onCleanButtonClicked();
    void Slot_onStartThreadButtonClicked();
    void Slot_onBeginDiceButtonClicked();
    void Slot_onPauseDiceButtonClicked();
    void Slot_onTerminateThreadButtonClicked();
};