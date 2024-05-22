/*!
 *  \file       user_moc.hpp
 *  \brief
 *
 */


#pragma once

#include <QtCore/QObject>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject* parent = nullptr);
signals:
    void mySignal(int value);
public slots:
    void mySlot(int value);
};

void DemoUserMOC();
