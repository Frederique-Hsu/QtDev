/*!
 *  \file       Counter.cpp
 *  \brief
 *
 */


#include "CCounter.hpp"

CCounter::CCounter() : m_value(0)
{
}

int CCounter::getValue() const
{
    return m_value;
}

void CCounter::setValue(int value)
{
    m_value = value;
}
