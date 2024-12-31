/*!
 *  \file       paint_widget.hpp
 *  \brief
 *
 */


#pragma once


#include <QWidget>


class PaintWidgetUI;

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    PaintWidget(QWidget* parent = nullptr);
    ~PaintWidget();
private:
    PaintWidgetUI* ui;
protected:
    void paintEvent(QPaintEvent* event) override;
};


#define PAINT_COLOR     1
#define PAINT_TEXTURE   2
#define PAINT_GRADIENT  3
#define PAINT           PAINT_GRADIENT