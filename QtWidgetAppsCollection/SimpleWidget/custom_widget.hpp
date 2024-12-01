/*!
 *  \file   custom_widget.hpp
 *  \brief
 *
 */


#pragma once

#include <QWidget>

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget* parent = nullptr);
private:
    QPoint m_lastPos;
public:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
};
