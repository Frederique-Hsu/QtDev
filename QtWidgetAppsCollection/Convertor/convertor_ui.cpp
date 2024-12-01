/*!
 *  \file       convertor_ui.cpp
 *  \brief
 *
 */


#include "convertor_ui.hpp"

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

#include <QCoreApplication>

void ConvertorUI::setupUI(QWidget* mainUiWidget)
{
    if (mainUiWidget->objectName().isEmpty())
    {
        mainUiWidget->setObjectName(QString("mainUiWidget"));
    }

    QLabel* qtyLabel = new QLabel(mainUiWidget);
    qtyLabel->setObjectName(QString("qtyLabel"));
    qtyLabel->setText(QString("数量"));

    qtyEdit = new QLineEdit(QString("12"), mainUiWidget);
    qtyEdit->setObjectName(QString("qtyEdit"));

    QLabel* unitPriceLabel = new QLabel(QString("单价"), mainUiWidget);
    unitPriceLabel->setObjectName(QString("unitPriceLabel"));

    unitPriceEdit = new QLineEdit(mainUiWidget);
    unitPriceEdit->setObjectName(QString("unitPriceEdit"));

    calculateButton = new QPushButton(QString("Calculate"), mainUiWidget);
    calculateButton->setObjectName(QString("calculateButton"));

    QLabel* totalPriceLabel = new QLabel(QString("总价"), mainUiWidget);
    totalPriceLabel->setObjectName(QString("totalPriceLabel"));

    totalPriceEdit = new QLineEdit(mainUiWidget);
    totalPriceEdit->setObjectName(QString("totalPriceEdit"));

    QGridLayout* topGridLayout = new QGridLayout();
    topGridLayout->setSpacing(6);
    topGridLayout->addWidget(qtyLabel, 0, 0, 1, 1);
    topGridLayout->addWidget(qtyEdit,  0, 1, 1, 1);
    topGridLayout->addWidget(unitPriceLabel, 0, 3, 1, 1);
    topGridLayout->addWidget(unitPriceEdit, 0, 4, 1, 1);
    topGridLayout->addWidget(calculateButton, 1, 1, 1, 1);
    QSpacerItem* hspacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum);
    topGridLayout->addItem(hspacer, 1, 2, 1, 1);
    topGridLayout->addWidget(totalPriceLabel, 1, 3, 1, 1);
    topGridLayout->addWidget(totalPriceEdit, 1, 4, 1, 2);

    QLabel* decimalLabel = new QLabel(QString("十进制"), mainUiWidget);
    decimalLabel->setObjectName(QString("decimalLabel"));

    decimalEdit = new QLineEdit(QString("12"), mainUiWidget);
    decimalEdit->setObjectName(QString("decimalEdit"));

    decConvertorButton = new QPushButton(mainUiWidget);
    decConvertorButton->setObjectName(QString("decConvertorButton"));

    QLabel* binaryLabel = new QLabel(QString("二进制"), mainUiWidget);
    binaryLabel->setObjectName(QString("binaryLabel"));

    binaryEdit = new QLineEdit(mainUiWidget);
    binaryEdit->setObjectName(QString("binaryEdit"));

    binConvertorButton = new QPushButton(mainUiWidget);
    binConvertorButton->setObjectName(QString("binConvertorButton"));

    QLabel* hexLabel = new QLabel(QString("十六进制"), mainUiWidget);
    hexLabel->setObjectName(QString("hexLabel"));

    hexEdit = new QLineEdit(mainUiWidget);
    hexEdit->setObjectName(QString("hexEdit"));

    hexConvertorButton = new QPushButton(mainUiWidget);
    hexConvertorButton->setObjectName(QString("hexConvertorButton"));

    QGridLayout* bottomGridLayout = new QGridLayout();
    bottomGridLayout->setSpacing(6);
    bottomGridLayout->addWidget(decimalLabel, 0, 0, 1, 1);
    bottomGridLayout->addWidget(decimalEdit, 0, 1, 1, 1);
    bottomGridLayout->addWidget(decConvertorButton, 0, 2, 1, 1);
    bottomGridLayout->addWidget(binaryLabel, 1, 0, 1, 1);
    bottomGridLayout->addWidget(binaryEdit, 1, 1, 1, 1);
    bottomGridLayout->addWidget(binConvertorButton, 1, 2, 1, 1);
    bottomGridLayout->addWidget(hexLabel, 2, 0, 1, 1);
    bottomGridLayout->addWidget(hexEdit, 2, 1, 1, 1);
    bottomGridLayout->addWidget(hexConvertorButton, 2, 2, 1, 1);

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->setSpacing(6);
    vlayout->setContentsMargins(10, 10, 10, 10);
    vlayout->addLayout(topGridLayout);
    QSpacerItem* vspacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vlayout->addItem(vspacer);
    vlayout->addLayout(bottomGridLayout);

    mainUiWidget->setLayout(vlayout);
    retranslateUI(mainUiWidget);
}

void ConvertorUI::retranslateUI(QWidget* mainUiWidget)
{
    calculateButton->setText(QCoreApplication::translate("mainUiWidget", "计算", nullptr));
    decConvertorButton->setText(QCoreApplication::translate("mainUiWidget", "转换为二进制与十六进制", nullptr));
    binConvertorButton->setText(QCoreApplication::translate("mainUiWidget", "转换为十进制与十六进制", nullptr));
    hexConvertorButton->setText(QCoreApplication::translate("mainUiWidget", "转换为十进制与二进制", nullptr));
}