/*!
 *  \file       ui_canvas.cpp
 *  \brief
 *
 */


#include "ui_canvas.hpp"

#include <QWidget>

void Ui_Canvas::setupUi(QWidget* canvas)
{
    if (canvas->objectName().isEmpty())
    {
        canvas->setObjectName(QString::fromUtf8("canvas"));
    }
}
