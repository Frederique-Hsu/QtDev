/*!
 *  \file       my_custom_widget.cpp
 *  \brief
 *
 */


#include "my_custom_widget.hpp"

#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>

MyCustomWidget::MyCustomWidget(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* vlayout = new QVBoxLayout(this);
    m_widget = new QListWidget(this);
    vlayout->addWidget(m_widget);

    m_edit = new QLineEdit(this);
    vlayout->addWidget(m_edit);

    m_button = new QPushButton("Quit", this);
    vlayout->addWidget(m_button);

    setLayout(vlayout);

    QStringList cities;
    cities << "Paris" << "London" << "Munich";
    for (const QString& city : cities)
    {
        m_widget->addItem(city);
    }

    QObject::connect(m_widget, &QListWidget::itemClicked, this, &MyCustomWidget::itemClicked);
    QObject::connect(m_edit, &QLineEdit::editingFinished, this, &MyCustomWidget::updateItem);
    QObject::connect(m_button, &QPushButton::clicked, qApp, &QApplication::quit);
}

void MyCustomWidget::itemClicked(QListWidgetItem* item)
{
    Q_ASSERT(item);
    m_edit->setText(item->text());
}

void MyCustomWidget::updateItem()
{
    QListWidgetItem* item = m_widget->currentItem();
    if (item)
    {
        item->setText(m_edit->text());
    }
}