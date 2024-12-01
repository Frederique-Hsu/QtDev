/*!
 *  \file       convertor.hpp
 *  \brief      Define the Convertor class
 *
 */


#pragma once

#include <QWidget>


namespace ui
{
    class Convertor;
}

class Convertor : public QWidget
{
    Q_OBJECT
public:
    explicit Convertor(QWidget* parent = nullptr);
    ~Convertor();
private:
    ui::Convertor* ui;
private slots:
    void calculateTotalPrice();
    void convertFromDecToBinAndHex();
    void convertFromBinToDecAndHex();
    void convertFromHexToDecAndBin();
};
