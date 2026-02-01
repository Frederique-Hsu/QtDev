/*!
 *  \file       DiceThread.hpp
 *  \brief      
 *  
 */


#pragma once

#include <QThread>

class DiceThread : public QThread
{
    Q_OBJECT
public:
    DiceThread();
    ~DiceThread();

private:
    int m_seq;
    int m_dice_value;
    bool m_is_paused;
    bool m_is_stopped;

public:
    void beginDice();
    void pauseDice();
    void stopThread();

protected:
    void run() override;

signals:
    void newValue(int seq, int dice_value);
};