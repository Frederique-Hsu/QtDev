/*!
 *  \file       QCounter.cpp
 *  \brief
 *
 */


#include "QCounter.hpp"

QCounter::QCounter(QObject* parent) : QObject(parent), m_value(0)
{
}

int QCounter::getValue() const
{
    return m_value;
}

void QCounter::setValue(int value)
{
    // prevent the infinite looping in case of cyclic connections.
    if (m_value != value)
    {
        m_value = value;
        emit valueChanged(value);
    }
}

void QCounter::increment()
{
    int currentValue = getValue();
    setValue(currentValue + 1);
}

void QCounter::decrement()
{
    int currentValue = getValue();
    setValue(currentValue - 1);
}
