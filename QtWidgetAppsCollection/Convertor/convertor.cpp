/*!
 *  \file       convertor.cpp
 *  \brief
 *
 */


#include "convertor.hpp"
#include "convertor_ui.hpp"

#include "../qt_utils/qt_io_stream.hpp"

#include <QPushButton>
#include <QLineEdit>
#include <QDebug>

Convertor::Convertor(QWidget* parent) : QWidget(parent), ui{new ui::Convertor}
{
    ui->setupUI(this);
    setFixedSize(sizeHint());

    QObject::connect(ui->calculateButton,    &QPushButton::clicked, this, &Convertor::calculateTotalPrice);
    QObject::connect(ui->decConvertorButton, &QPushButton::clicked, this, &Convertor::convertFromDecToBinAndHex);
    QObject::connect(ui->binConvertorButton, &QPushButton::clicked, this, &Convertor::convertFromBinToDecAndHex);
    QObject::connect(ui->hexConvertorButton, &QPushButton::clicked, this, &Convertor::convertFromHexToDecAndBin);
}


Convertor::~Convertor()
{
    if (ui != nullptr)
    {
        delete ui;
    }
}

void Convertor::calculateTotalPrice()
{
    QString qty_str = ui->qtyEdit->text();
    int qty = qty_str.toInt();

    QString unit_price_str = ui->unitPriceEdit->text();
    float unit_price = unit_price_str.toFloat();

    float total_price = qty * unit_price;
    QString total_price_str = QString::asprintf("%.2f", total_price);
    ui->totalPriceEdit->setText(total_price_str);
}

void Convertor::convertFromDecToBinAndHex()
{
    QString dec_str = ui->decimalEdit->text();

    bool ok_flag = false;
    int dec_value = dec_str.toInt(&ok_flag);
    if (ok_flag == false)
    {
        qDebug() << "conversion from digit string to int failed.\n";
        return;
    }

    QString hex_str, bin_str;
    hex_str.setNum(dec_value, 16);
    bin_str = QString::number(dec_value, 2);

    ui->binaryEdit->setText(bin_str);
    ui->hexEdit->setText(hex_str.toUpper());
}

void Convertor::convertFromBinToDecAndHex()
{
    QString bin_str = ui->binaryEdit->text();
    bool ok_flag = false;
    int val = bin_str.toInt(&ok_flag, 2);
    if (ok_flag == false)
    {
        Qt::cout << "conversion from binary string to int failed." << Qt::endl;
        return;
    }

    QString dec_str, hex_str;
    dec_str.setNum(val, 10);
    hex_str = QString::number(val, 16);

    ui->decimalEdit->setText(dec_str);
    ui->hexEdit->setText(hex_str.toUpper());
}

void Convertor::convertFromHexToDecAndBin()
{
    QString hex_str = ui->hexEdit->text();
    bool ok_flag = false;
    int val = hex_str.toInt(&ok_flag, 16);
    if (ok_flag == false)
    {
        Qt::cout << "conversion from hex string to int failed." << Qt::endl;
        return;
    }
    QString dec_str = QString::number(val, 10), bin_str = QString::number(val, 2);
    ui->decimalEdit->setText(dec_str);
    ui->binaryEdit->setText(bin_str);
}