/*!
 *  \file       ui_qmywidget.cpp
 *  \brief
 *
 */


#include "ui_qmywidget.hpp"

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPlainTextEdit>

void UI_QMyWidget::setupUI(QWidget* QMyWidget)
{
    if (QMyWidget->objectName().isEmpty())
    {
        QMyWidget->setObjectName(QString("QMyWidget"));
    }

    QLabel* labelBoyAge = new QLabel(QMyWidget);
    labelBoyAge->setText(QApplication::translate("QMyWidget", "设置男生年龄", Q_NULLPTR));
    QLabel* labelGirlAge = new QLabel(QMyWidget);
    labelGirlAge->setText(QApplication::translate("QMyWidget", "设置女生年龄", Q_NULLPTR));

    spinBoy = new QSpinBox(QMyWidget);
    spinBoy->setObjectName(QString("spinBoy"));
    spinBoy->setMinimum(0);
    spinBoy->setMaximum(200);
    spinBoy->setValue(10);

    spinGirl = new QSpinBox(QMyWidget);
    spinGirl->setObjectName(QStringLiteral("spinGirl"));
    spinGirl->setMaximum(200);
    spinGirl->setValue(20);

    btnBoyIncrement = new QPushButton(QMyWidget);
    btnBoyIncrement->setObjectName(QString("btnBoyIncrement"));
    btnGirlIncrement = new QPushButton(QMyWidget);
    btnGirlIncrement->setObjectName(QString("btnGirlIncrement"));
    btnClassInfo = new QPushButton(QMyWidget);
    btnClassInfo->setObjectName(QString("btnClassInfo"));
    btnClear = new QPushButton(QMyWidget);
    btnClear->setObjectName(QString("btnClear"));

    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setSpacing(6);
    gridLayout->addWidget(labelBoyAge, 0, 0, 1, 1);
    gridLayout->addWidget(spinBoy, 0, 1, 1, 1);
    gridLayout->addWidget(btnBoyIncrement, 0, 2, 1, 1);
    gridLayout->addWidget(btnClassInfo, 0, 3, 1, 1);
    gridLayout->addWidget(labelGirlAge, 1, 0, 1, 1);
    gridLayout->addWidget(spinGirl, 1, 1, 1, 1);
    gridLayout->addWidget(btnGirlIncrement, 1, 2, 1, 1);
    gridLayout->addWidget(btnClear, 1, 3, 1, 1);

    QVBoxLayout* vlayout = new QVBoxLayout(QMyWidget);
    vlayout->setSpacing(6);
    vlayout->setContentsMargins(11, 11, 11, 11);
    vlayout->addLayout(gridLayout);

    textEdit = new QPlainTextEdit(QMyWidget);
    textEdit->setObjectName(QString("textEdit"));
    vlayout->addWidget(textEdit);

    retranslateUI(QMyWidget);
}

void UI_QMyWidget::retranslateUI(QWidget* QMyWidget)
{
    QMyWidget->setWindowTitle(QApplication::translate("QMyWidget", "Meta Object的使用", Q_NULLPTR));
    btnBoyIncrement->setText(QApplication::translate("QMyWidget", "男生长大了一岁", Q_NULLPTR));
    btnGirlIncrement->setText(QApplication::translate("QMyWidget", "女生长大了一岁", Q_NULLPTR));
    btnClassInfo->setText(QApplication::translate("QMyWidget", "类的元对象信息", Q_NULLPTR));
    btnClear->setText(QApplication::translate("QMyWidget", "清空文本框", Q_NULLPTR));
}
