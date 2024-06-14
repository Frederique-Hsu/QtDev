/*!
 *  \file       MyObject.cpp
 *  \brief
 *
 */


#include "MyObject.hpp"
#include "MyThread.hpp"


MyObject::MyObject(QObject* parent) : QObject(parent)
{
}

void MyObject::startWorkInAThread()
{
    MyThread* myThread = new MyThread(this);

    // QObject::connect(myThread, &MyObject::threadFinished, this, &MyObject::notifyThreadFinished);
    QObject::connect(myThread, &MyThread::finished, myThread, &QObject::deleteLater);

    myThread->start();
}
