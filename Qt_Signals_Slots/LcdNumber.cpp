/*!
 *  \file       LcdNumber
 *  \brief
 *
 */


#include "LcdNumber.hpp"

LcdNumber::LcdNumber(QWidget* parent) : QFrame(parent)
{
}

void LcdNumber::display(int /* num */)
{
}

void LcdNumber::display(double /* num */)
{
}

void LcdNumber::display(const QString& /* str */)
{
    using namespace std;

    throw runtime_error(string(__FUNCTION__) + string("has not yet implemented"));
}

void LcdNumber::setHexMode()
{
}

void LcdNumber::setDecMode()
{
}

void LcdNumber::setOctMode()
{
}

void LcdNumber::setBinMode()
{
}

void LcdNumber::setSmallDecimalPoint(bool /* point */)
{
}
