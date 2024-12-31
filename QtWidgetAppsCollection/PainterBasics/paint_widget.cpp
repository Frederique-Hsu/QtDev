/*!
 *  \file       paint_widget.cpp
 *  \brief
 *
 */


#include "paint_widget.hpp"
#include "paint_widget_ui.hpp"

#include <QPainter>

PaintWidget::PaintWidget(QWidget* parent) : QWidget(parent), ui(new PaintWidgetUI)
{
    ui->setupUI(this);

    setPalette(QPalette(Qt::GlobalColor::white));
    setAutoFillBackground(true);
}

PaintWidget::~PaintWidget()
{
    if (ui != nullptr)
    {
        delete ui;
    }
}

void PaintWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::RenderHint::Antialiasing);
    painter.setRenderHint(QPainter::RenderHint::TextAntialiasing);

    int width = this->width();
    int height = this->height();
    QRect painting_area(width/4, height/4, width/2, height/2);

    QPen pen;
    pen.setColor(Qt::GlobalColor::red);
    pen.setStyle(Qt::PenStyle::SolidLine);
    pen.setCapStyle(Qt::PenCapStyle::FlatCap);
    pen.setJoinStyle(Qt::PenJoinStyle::BevelJoin);
    painter.setPen(pen);

#if (PAINT == PAINT_COLOR)
    QBrush brush;
    brush.setColor(Qt::GlobalColor::yellow);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter.setBrush(brush);

    painter.drawRect(painting_area);
#elif (PAINT == PAINT_TEXTURE)
    // QPixmap texture_pixmap(":/images/images/wood_texture.jpg");
    // QPixmap texture_pixmap(":/images/images/qt_logo.jpg");
    // QPixmap texture_pixmap(":/images/images/marble_texture.jpg");

    QBrush brush;
    brush.setStyle(Qt::TexturePattern);
    brush.setTexture(QPixmap(":/images/images/wood_texture.jpg"));
    // brush.setTextureImage(QImage(QString(":/images/images/qt_log.jpg")));
    painter.setBrush(brush);

    painter.drawRect(painting_area);
#elif (PAINT == PAINT_GRADIENT)
    QRadialGradient radialGrad(width/2, height/2, qMax(height/8, width/8), width/2, height/2);
    radialGrad.setColorAt(0, Qt::green);
    radialGrad.setColorAt(1, Qt::blue);
    radialGrad.setSpread(QGradient::ReflectSpread);

    painter.setPen(pen);
    painter.setBrush(radialGrad);
    painter.drawRect(this->rect());
#endif
}