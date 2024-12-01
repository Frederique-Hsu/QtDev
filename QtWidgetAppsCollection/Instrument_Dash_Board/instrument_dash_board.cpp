/*!
 *  \file       instrument_dash_board.cpp
 *  \brief
 *
 */


#include "instrument_dash_board.hpp"
#include "instrument_dash_board_ui.hpp"

#include <QSlider>
#include <QTextEdit>
#include <QLCDNumber>
#include <QDial>
#include <QRadioButton>
#include <QProgressBar>
#include <QScrollBar>
#include <QPushButton>

InstrumentDashBoard::InstrumentDashBoard(QWidget* parent) : QWidget(parent), ui{new InstrumentDashBoardUI}
{
    ui->setupUI(this);
    {   // 固定窗口的高度，只能调整窗口的宽度
        QSize original_size = this->size();
        auto original_width = original_size.width();
        auto original_height = original_size.height();
        setMinimumSize(QSize(original_width, original_height));
        setMaximumSize(QSize(QWIDGETSIZE_MAX, original_height));
    }

    connect(ui->redSlider,   &QSlider::valueChanged, this, &InstrumentDashBoard::onColorSliderValueChanged);
    connect(ui->greenSlider, &QSlider::valueChanged, this, &InstrumentDashBoard::onColorSliderValueChanged);
    connect(ui->blueSlider,  &QSlider::valueChanged, this, &InstrumentDashBoard::onColorSliderValueChanged);
    connect(ui->alphaSlider, &QSlider::valueChanged, this, &InstrumentDashBoard::onColorSliderValueChanged);

    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(onDialValueChanged(int)));

    connect(ui->binRadioButton, SIGNAL(clicked(bool)), this, SLOT(onBinRadioButtonClicked()));
    connect(ui->octRadioButton, SIGNAL(clicked(bool)), this, SLOT(onOctRadioButtonClicked()));
    connect(ui->hexRadioButton, SIGNAL(clicked(bool)), this, SLOT(onHexRadioButtonClicked()));

    connect(ui->hslider,    SIGNAL(valueChanged(int)), this, SLOT(onHorSliderValueChanged(int)));
    connect(ui->hscrollBar, SIGNAL(valueChanged(int)), this, SLOT(onHorScrollBarSliderMoved(int)));
    connect(ui->vslider,    SIGNAL(valueChanged(int)), this, SLOT(onVerSliderValueChanged(int)));
    connect(ui->vscrollBar, SIGNAL(valueChanged(int)), this, SLOT(onVerScrollBarSliderMoved(int)));

    connect(ui->closeButton, &QPushButton::clicked, this, &QWidget::close);
}

InstrumentDashBoard::~InstrumentDashBoard()
{
    if (ui != nullptr)
    {
        delete ui;
    }
}

void InstrumentDashBoard::onColorSliderValueChanged(int value)
{
    Q_UNUSED(value);

    int R = ui->redSlider->value(),
        G = ui->greenSlider->value(),
        B = ui->blueSlider->value(),
        A = ui->alphaSlider->value();
    QColor color(R, G, B, A);
    QPalette palette = ui->colorBlock->palette();
    palette.setColor(QPalette::Base, color);
    ui->colorBlock->setPalette(palette);
}

void InstrumentDashBoard::onDialValueChanged(int value)
{
    ui->decimalLcdNum->display(value);
    ui->otherLcdNum->display(value);
}

void InstrumentDashBoard::onBinRadioButtonClicked()
{
    ui->otherLcdNum->setDigitCount(8);
    ui->otherLcdNum->setBinMode();
    ui->otherLcdNum->display(ui->decimalLcdNum->value());
}

void InstrumentDashBoard::onOctRadioButtonClicked()
{
    ui->otherLcdNum->setDigitCount(4);
    ui->otherLcdNum->setOctMode();
    ui->otherLcdNum->display(ui->decimalLcdNum->value());
}

void InstrumentDashBoard::onHexRadioButtonClicked()
{
    ui->otherLcdNum->setDigitCount(4);
    ui->otherLcdNum->setHexMode();
    ui->otherLcdNum->display(ui->decimalLcdNum->value());
}

void InstrumentDashBoard::onHorSliderValueChanged(int value)
{
    ui->hprogressBar->setValue(value);
    ui->hscrollBar->setValue(value);
}

void InstrumentDashBoard::onHorScrollBarSliderMoved(int position)
{
    ui->hprogressBar->setValue(position);
    ui->hslider->setValue(position);
}

void InstrumentDashBoard::onVerSliderValueChanged(int value)
{
    ui->vprogressBar->setValue(value);
    ui->vscrollBar->setValue(value);
}

void InstrumentDashBoard::onVerScrollBarSliderMoved(int position)
{
    ui->vprogressBar->setValue(position);
    ui->vslider->setValue(position);
}