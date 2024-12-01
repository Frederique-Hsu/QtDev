/*!
 *  \file       ui_resultdialog.cpp
 *  \brief
 *
 */


#include "ui_resultdialog.hpp"

#include <QCoreApplication>
#include <QFormLayout>
#include <QLabel>
#include <QDialogButtonBox>

void Ui_Dialog::setupUi(QDialog* dialog)
{
    if (dialog->objectName().isEmpty())
    {
        dialog->setObjectName("dialog");
    }

    QFormLayout* formLayout = new QFormLayout();
    formLayout->setObjectName("formLayout");

    resultLabel = new QLabel(dialog);
    resultLabel->setObjectName("resultLabel");
    formLayout->setWidget(0, QFormLayout::LabelRole, resultLabel);

    valueLabel = new QLabel(dialog);
    valueLabel->setObjectName("valueLabel");
    formLayout->setWidget(1, QFormLayout::LabelRole, valueLabel);

    QVBoxLayout* vLayout = new QVBoxLayout(dialog);
    vLayout->setObjectName("vLayout");
    vLayout->addLayout(formLayout);

    buttonBox = new QDialogButtonBox(dialog);
    buttonBox->setObjectName("buttonBox");
    buttonBox->setOrientation(Qt::Orientation::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);

    vLayout->addWidget(buttonBox);

    retranslateUi(dialog);

    QObject::connect(buttonBox, &QDialogButtonBox::accepted, dialog, qOverload<>(&QDialog::accept));
    QObject::connect(buttonBox, &QDialogButtonBox::rejected, dialog, qOverload<>(&QDialog::reject));
}

void Ui_Dialog::retranslateUi(QDialog* dialog)
{
    dialog->setWindowTitle(QCoreApplication::translate("dialog", "Dialog", nullptr));
    resultLabel->setText(QCoreApplication::translate("dialog", "Result", nullptr));
    valueLabel->setText(QCoreApplication::translate("dialog", "value", nullptr));
}
