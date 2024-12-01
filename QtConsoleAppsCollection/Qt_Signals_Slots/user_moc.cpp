/*!
 *  \file       user_moc.cpp
 *  \brief
 *
 */


#include "user_moc.hpp"

#include <QtCore/QDebug>
#include <QtCore/QMetaObject>

MyObject::MyObject(QObject* parent) : QObject(parent)
{
}

void MyObject::mySlot(int value)
{
    qDebug() << "Received the value: " << value;
}

void DemoUserMOC()
{
    MyObject obj1, obj2;

    // Retrieve the meta-object information
    const QMetaObject* metaObj1 = obj1.metaObject();
    const QMetaObject* metaObj2 = obj2.metaObject();

    int signalIndex = metaObj1->indexOfSignal(QMetaObject::normalizedSignature("mySignal(int)"));
    int slotIndex = metaObj2->indexOfSlot(QMetaObject::normalizedSignature("mySlot(int)"));

    // Connect the signal and slot
    QMetaObject::Connection connection = QMetaObject::connect(&obj1, signalIndex, &obj2, slotIndex);
    // Emit the signal
    QMetaObject::invokeMethod(&obj1, "mySignal", Qt::DirectConnection, Q_ARG(int, 85));
    // Disconnect
    QObject::disconnect(connection);
}
