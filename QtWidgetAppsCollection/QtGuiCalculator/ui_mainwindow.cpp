/*!
 *  \file       ui_mainwindow.cpp
 *  \brief
 *
 */


#include "ui_mainwindow.hpp"

#include <QCoreApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFormLayout>


void Ui_MainWindow::setupUi(QMainWindow* mainwindow)
{
    if (mainwindow->objectName().isEmpty())
    {
        mainwindow->setObjectName("mainwindow");
    }

    QWidget* centralWidget = new QWidget(mainwindow);
    centralWidget->setObjectName("centralWidget");

    QFormLayout* formLayout = new QFormLayout(centralWidget);
    formLayout->setObjectName("formLayout");
    formLayout->setSpacing(6);
    formLayout->setContentsMargins(10, 10, 10, 10);

    QVBoxLayout* vLayout = new QVBoxLayout();
    vLayout->setObjectName("vLayout");
    vLayout->setSpacing(6);

    QHBoxLayout* hLayout = new QHBoxLayout();
    hLayout->setObjectName("hLayout");
    hLayout->setSpacing(6);

    plusButton = new QPushButton(centralWidget);
    plusButton->setObjectName("plusButton");
    hLayout->addWidget(plusButton);

    minusButton = new QPushButton(centralWidget);
    minusButton->setObjectName("minusButton");
    hLayout->addWidget(minusButton);

    multiplyButton = new QPushButton(centralWidget);
    multiplyButton->setObjectName("multiplyButton");
    hLayout->addWidget(multiplyButton);

    divideButton = new QPushButton(centralWidget);
    divideButton->setObjectName("divideButton");
    hLayout->addWidget(divideButton);

    vLayout->addLayout(hLayout);
    vLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    argument1Input = new QLineEdit(centralWidget);
    argument1Input->setObjectName("argument1Input");
    vLayout->addWidget(argument1Input);

    vLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    argument2Input = new QLineEdit(centralWidget);
    argument2Input->setObjectName("argument2Input");
    vLayout->addWidget(argument2Input);

    vLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    aboutButton = new QPushButton(centralWidget);
    aboutButton->setObjectName("aboutButton");
    vLayout->addWidget(aboutButton);

    formLayout->setLayout(0, QFormLayout::LabelRole, vLayout);

    centralWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mainwindow->setCentralWidget(centralWidget);
    mainwindow->resize(centralWidget->width(), centralWidget->height());

    retranslateUi(mainwindow);
}

void Ui_MainWindow::retranslateUi(QMainWindow* mainwindow)
{
    mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "Qt GUI Calculator", nullptr));
    plusButton->setText(QCoreApplication::translate("mainwindow", "+", nullptr));
    minusButton->setText(QCoreApplication::translate("mainwindow", "-", nullptr));
    multiplyButton->setText(QCoreApplication::translate("mainwindow", "*", nullptr));
    divideButton->setText(QCoreApplication::translate("mainwindow", "/", nullptr));
    aboutButton->setText(QCoreApplication::translate("mainwindow", "&About", nullptr));
}
