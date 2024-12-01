/*!
 *  \file       MyThread.cpp
 *  \brief
 *
 */


#include "MyThread.hpp"

MyThread::MyThread(QObject* parent) : QThread(parent)
{
}

void MyThread::run()
{
    /* perform the expensive operation here */
}
