/*!
 *  \file       custom_widget.cpp
 *  \brief
 *
 */


#include "custom_widget.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsItem>


CustomWidget::CustomWidget(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    m_widget = new QListWidget(this);
    layout->addWidget(m_widget);

    m_edit = new QLineEdit(this);
    layout->addWidget(m_edit);

    m_button = new QPushButton("Quit", this);
    layout->addWidget(m_button);
    setLayout(layout);

    QStringList cities;
    cities << "Paris" << "London" << "Munich";
    foreach (const QString& city, cities)
    {
        m_widget->addItem(city);
    }

    connect(m_widget,
            SIGNAL(itemClicked(QListWidgetItem*)),
            this,
            SLOT(itemClicked(QListWidgetItem*)));
    connect(m_edit,
            SIGNAL(editingFinished()),
            this, SLOT(updateItem()));
    connect(m_button,
            SIGNAL(clicked()),
            qApp,
            SLOT(quit()));
}

void CustomWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QRect rect1 = rect().adjusted(10, 10, -10, -10);
    // painter.setPen(QColor("#33B5E5"));
    painter.setPen(QColor(0x33B5E0));
    painter.drawRect(rect1);

    QRect rect2(QPoint(0, 0), QSize(40, 40));
    if (m_lastPos.isNull())
    {
        rect2.moveCenter(rect1.center());
    }
    else
    {
        rect2.moveCenter(m_lastPos);
    }
    painter.fillRect(rect2, QColor("FFBB33"));
}

void CustomWidget::mousePressEvent(QMouseEvent* event)
{
    m_lastPos = event->pos();
    update();
}

void CustomWidget::mouseMoveEvent(QMouseEvent* event)
{
    m_lastPos = event->pos();
    update();
}

void CustomWidget::itemClicked(QListWidgetItem* item)
{
    Q_ASSERT(item);
    m_edit->setText(item->text());
}

void CustomWidget::updateItem()
{
    QListWidgetItem* item = m_widget->currentItem();
    if (item)
    {
        item->setText(m_edit->text());
    }
}

/*================================================================================================*/

CustomWidgetV2::CustomWidgetV2(QWidget* parent) : QWidget(parent)
{
    m_view = new QGraphicsView(this);
    m_scene = new QGraphicsScene(this);
    m_view->setScene(m_scene);

    QVBoxLayout* layout = new QVBoxLayout(this);
    // layout->setMargin(0);
    layout->addWidget(m_view);
    setLayout(layout);

    QGraphicsItem* rect1 = m_scene->addRect(0, 0, 40, 40, Qt::NoPen, QColor("#FFBB33"));
    rect1->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
}
