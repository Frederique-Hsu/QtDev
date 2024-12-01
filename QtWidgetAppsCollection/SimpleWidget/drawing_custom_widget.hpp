/*!
 *  \file       drawing_custom_widget.hpp
 *  \brief
 *
 */


#pragma once

#include <QWidget>

class QGraphicsView;
class QGraphicsScene;

class DrawingCustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingCustomWidget(QWidget* parent = nullptr);
private:
    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
};
