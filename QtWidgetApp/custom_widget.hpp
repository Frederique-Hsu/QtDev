/*!
 *  \file       custom_widget.hpp
 *  \brief
 *
 */


#pragma once

#include <QWidget>

class QListWidgetItem;
class QListWidget;
class QLineEdit;
class QPushButton;

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget* parent = nullptr);
private:
    QPoint m_lastPos;
public:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
private slots:
    void itemClicked(QListWidgetItem* item);
    void updateItem();
private:
    QListWidget* m_widget;
    QLineEdit* m_edit;
    QPushButton* m_button;
};


/*================================================================================================*/

class QGraphicsView;
class QGraphicsScene;

class CustomWidgetV2 : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidgetV2(QWidget* parent = nullptr);
private:
    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
};
