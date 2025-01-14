/*!
 *  \file       LcdNumber.hpp
 *  \brief
 *
 */


#pragma once

#include <QFrame>

class LcdNumber : public QFrame
{
    Q_OBJECT
public:
    LcdNumber(QWidget* parent = nullptr);
signals:
    void overflow();
public slots:
    void display(int num);
    void display(double num);
    void display(const QString& str);
    void setHexMode();
    void setDecMode();
    void setOctMode();
    void setBinMode();
    void setSmallDecimalPoint(bool point);
};
