/*!
 *  \file       main.cpp
 *  \brief
 *
 */

#include <QApplication>
#include <QWidget>
#include <QtGui>

#define CUSTOM_WIDGET   1
#define DESKTOP_WIDGET  2
#define DRAWING_WIDGET  3

#define WIDGET_TYPE     CUSTOM_WIDGET

#if (WIDGET_TYPE == CUSTOM_WIDGET)
    #include "custom_widget.hpp"
#elif (WIDGET_TYPE == DESKTOP_WIDGET)
    #include "my_custom_widget.hpp"
#elif (WIDGET_TYPE == DRAWING_WIDGET)
    #include "drawing_custom_widget.hpp"
#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if (WIDGET_TYPE == CUSTOM_WIDGET)
    QScopedPointer<QWidget> widget(new CustomWidget());
#elif (WIDGET_TYPE == DESKTOP_WIDGET)
    QScopedPointer<QWidget> widget(new MyCustomWidget());
#elif (WIDGET_TYPE == DRAWING_WIDGET)
    QScopedPointer<QWidget> widget(new DrawingCustomWidget());
#endif
    widget->resize(240, 120);
    widget->show();

    return app.exec();
}