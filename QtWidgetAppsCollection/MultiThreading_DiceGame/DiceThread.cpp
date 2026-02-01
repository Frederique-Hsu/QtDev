/*!
 *  \file       DiceThread.cpp
 *  \brief      
 *  
 */


#include "DiceThread.hpp"

#include <QTime>
#include <QtGlobal>


DiceThread::DiceThread() : QThread(), m_seq{0}, m_dice_value{}, m_is_paused{true}, m_is_stopped{false}
{
}

DiceThread::~DiceThread()
{
}

/*!
 *  \brief  开始掷骰子
 */
void DiceThread::beginDice()
{
    m_is_paused = false;
}

/*!
 *  \brief  暂停掷骰子
 */
void DiceThread::pauseDice()
{
    m_is_paused = true;
}

/*!
 *  \brief  停止线程
 */
void DiceThread::stopThread()
{
    m_is_stopped = true;
}

/*!
 *  \brief  线程任务
 */
void DiceThread::run()
{
    m_is_stopped = false;
    m_seq = 0;

    srand(QTime::currentTime().msec());
    while (!m_is_stopped)
    {
        if (!m_is_paused)
        {
            m_dice_value = rand();
            m_dice_value = (m_dice_value % 6) + 1;

            m_seq++;
            emit newValue(m_seq, m_dice_value);
        }
        msleep(500);
    }
    quit();     // 退出线程的事件循环
}
