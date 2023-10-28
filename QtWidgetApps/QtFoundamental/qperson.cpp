/*!
 *  \file       qperson.cpp
 *  \brief
 *
 */


#include "qperson.hpp"

QPerson::QPerson(QString fname, QObject* parent) : QObject(parent),
                                                   m_age(10),
                                                   m_name(fname),
                                                   m_score(79)
{
}

void QPerson::incAge()
{
    m_age++;
    emit ageChanged(m_age);
}

int QPerson::age()
{
    return m_age;
}

void QPerson::setAge(int value)
{
    m_age = value;
    emit ageChanged(m_age);
}
