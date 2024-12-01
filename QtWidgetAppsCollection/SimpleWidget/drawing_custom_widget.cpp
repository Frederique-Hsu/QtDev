/*!
 *  \file   drawing_custom_widget.cpp
 *  \brief
 *
 */


#include "drawing_custom_widget.hpp"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QVBoxLayout>

DrawingCustomWidget::DrawingCustomWidget(QWidget* parent) : QWidget(parent)
{
    m_view = new QGraphicsView(this);
    m_scene = new QGraphicsScene(this);
    m_view->setScene(m_scene);

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    // vlayout->setMargin(0);
    vlayout->addWidget(m_view);

    setLayout(vlayout);

    QGraphicsItem* rect = m_scene->addRect(0, 0, 40, 40, Qt::NoPen, QColor("#FFBB33"));
    rect->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
}