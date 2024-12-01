/*!
 *  \file       QCounter.hpp
 *  \brief
 *
 */


#pragma once

#include <QObject>

class QCounter : public QObject
{
    Q_OBJECT
public:
    QCounter(QObject* parent = nullptr);

    int getValue() const;
public slots:   // public __attribute__((annotate("qt_slot")))
    void setValue(int value);
    void increment();
    void decrement();
signals:        // public __attribute__((annotate("qt_signal")))
    void valueChanged(int newValue);
private:
    int m_value;
};
