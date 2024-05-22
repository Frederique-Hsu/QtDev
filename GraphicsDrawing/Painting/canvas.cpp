/*!
 *  \file       canvas.cpp
 *  \brief
 *
 */


#include "canvas.hpp"

#include "ui_canvas.hpp"

Canvas::Canvas(QWidget *parent) : QWidget(parent), ui(new Ui::Canvas)
{
    ui->setupUi(this);
}

Canvas::~Canvas()
{
    if (ui != nullptr)
    {
        delete ui;
    }
}

void Canvas::paintEvent(QPaintEvent* event)
{

}

