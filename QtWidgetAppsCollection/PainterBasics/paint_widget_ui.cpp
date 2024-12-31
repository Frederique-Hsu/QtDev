/*!
 *  \file       paint_widget_ui.cpp
 *  \brief
 *
 */


#include "paint_widget_ui.hpp"

#include <QWidget>
#include <QCoreApplication>

void PaintWidgetUI::setupUI(QWidget* paint_widget)
{
    if (paint_widget->objectName().isEmpty())
    {
        paint_widget->setObjectName(QString("paint_widget"));
    }

    retranslate(paint_widget);
}

void PaintWidgetUI::retranslate(QWidget* paint_widget)
{
    paint_widget->setWindowTitle(QCoreApplication::translate("paint_widget", "QPainter基本绘图", nullptr));
}