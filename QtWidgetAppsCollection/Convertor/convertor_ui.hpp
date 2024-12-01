/*!
 *  \file       convertor_ui.hpp
 *  \brief
 *
 */


#pragma once


class QWidget;
class QLineEdit;
class QPushButton;

class ConvertorUI
{
public:
    QLineEdit* qtyEdit;
    QLineEdit* unitPriceEdit;
    QLineEdit* totalPriceEdit;
    QPushButton* calculateButton;
    QLineEdit* decimalEdit;
    QPushButton* decConvertorButton;
    QLineEdit* binaryEdit;
    QPushButton* binConvertorButton;
    QLineEdit* hexEdit;
    QPushButton* hexConvertorButton;
public:
    void setupUI(QWidget* mainUiWidget);
    void retranslateUI(QWidget* mainUiWidget);
};

namespace ui
{
    class Convertor : public ConvertorUI
    {
    };
}