/*!
 *  \file       Counter.hpp
 *  \brief
 *
 */


#pragma once

class CCounter
{
public:
    CCounter();

    int getValue() const;
    void setValue(int value);
private:
    int m_value;
};
