/*!
 *  \file       qmywidget.cpp
 *  \brief
 *
 */


#include "qmywidget.hpp"
#include "ui_qmywidget.hpp"
#include "qperson.hpp"

#include <QSpinBox>
#include <QPlainTextEdit>
#include <QMetaProperty>
#include <QPushButton>

QMyWidget::QMyWidget(QWidget *parent) : QWidget(parent), ui(new UI::QMyWidget)
{
    ui->setupUI(this);

    boy = new QPerson("徐赞");
    boy->setProperty("score", 95);
    boy->setProperty("age", 40);
    boy->setProperty("gender", "Boy");
    QObject::connect(boy, &QPerson::ageChanged, this, &QMyWidget::on_age_changed);

    girl = new QPerson("余学琴");
    girl->setProperty("score", 81);
    girl->setProperty("age", 41);
    girl->setProperty("gender", "Girl");
    connect(girl, SIGNAL(ageChanged(int)), this, SLOT(on_age_changed(int)));

    ui->spinBoy->setProperty("isBoy", true);
    ui->spinGirl->setProperty("isBoy", false);

    connect(ui->spinBoy, SIGNAL(valueChanged(int)), this, SLOT(on_spin_value_changed(int)));
    connect(ui->spinGirl, SIGNAL(valueChanged(int)), this, SLOT(on_spin_value_changed(int)));

    connect(ui->btnClassInfo, SIGNAL(clicked()), this, SLOT(on_btnClassInfo_clicked()));
    connect(ui->btnClear, SIGNAL(clicked()), this, SLOT(on_btnClear_clicked()));
    connect(ui->btnBoyIncrement, SIGNAL(clicked()), this, SLOT(on_btnBoyIncrement_clicked()));
    connect(ui->btnGirlIncrement, &QPushButton::clicked, this, &QMyWidget::on_btnGirlIncrement_clicked);
}

QMyWidget::~QMyWidget()
{
    delete ui;
}

void QMyWidget::on_age_changed(int value)
{
    Q_UNUSED(value);

    QPerson *aperson = qobject_cast<QPerson*>(sender());
    QString his_name = aperson->property("name").toString();
    QString his_gender = aperson->property("gender").toString();
    int his_age = aperson->age();
    // his_age = aperson->property("age").toInt();

    ui->textEdit->appendPlainText(his_name + ", " + his_gender + QString::asprintf(", 年龄=%d", his_age));
}

void QMyWidget::on_spin_value_changed(int arg)
{
    Q_UNUSED(arg);

    QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    if (spinBox->property("isBoy").toBool())
    {
        boy->setAge(spinBox->value());
    }
    else
    {
        girl->setAge(spinBox->value());
    }
}

void QMyWidget::on_btnClassInfo_clicked()
{
    const QMetaObject *meta_obj = boy->metaObject();

    ui->textEdit->clear();
    ui->textEdit->appendPlainText("==元对象信息==\n");
    ui->textEdit->appendPlainText(QString("类名称： %1\n").arg(meta_obj->className()));
    ui->textEdit->appendPlainText("property");

    for (int i = meta_obj->propertyOffset(); i < meta_obj->propertyCount(); ++i)
    {
        QMetaProperty property = meta_obj->property(i);
        const char* property_name = property.name();
        QString property_value = boy->property(property_name).toString();
        ui->textEdit->appendPlainText(QString("属性名称=%1, 属性值=%2\n").arg(property_name)
                                                                      .arg(property_value));
    }

    ui->textEdit->appendPlainText("");
    ui->textEdit->appendPlainText("class info");
    for (int i = meta_obj->classInfoOffset(); i < meta_obj->classInfoCount(); ++i)
    {
        QMetaClassInfo class_info = meta_obj->classInfo(i);
        ui->textEdit->appendPlainText(QString("Name = %1, Value = %2").arg(class_info.name())
                                                                      .arg(class_info.value()));
    }
}

void QMyWidget::on_btnClear_clicked()
{
    ui->textEdit->clear();
}

void QMyWidget::on_btnBoyIncrement_clicked()
{
    boy->incAge();
}

void QMyWidget::on_btnGirlIncrement_clicked()
{
    girl->incAge();
}
