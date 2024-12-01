/*!
 *  \file       instrument_dash_board_ui.cpp
 *  \brief
 *
 */


#include "instrument_dash_board_ui.hpp"

#include <QCoreApplication>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QSlider>
#include <QLabel>
#include <QTextEdit>
#include <QPalette>
#include <QScrollBar>
#include <QProgressBar>
#include <QDial>
#include <QLCDNumber>
#include <QRadioButton>
#include <QPushButton>
#include <QSpacerItem>

void InstrumentDashBoardUI::setupUI(QWidget* dash_board)
{
    if (dash_board->objectName().isEmpty())
    {
        dash_board->setObjectName(QString("dash_board"));
    }
    dash_board->setWindowTitle(QString("Display Instrument Dash Board"));

    buildUpGroupBox(dash_board);
    buildMidGroupBox(dash_board);
    buildDownGroupBox(dash_board);

    QVBoxLayout* leftVLayout = new QVBoxLayout();
    leftVLayout->addWidget(upGroupBox);
    leftVLayout->addWidget(midGroupBox);
    leftVLayout->addWidget(downGroupBox);

    buildRightGroupBox(dash_board);

    closeButton = new QPushButton(QString("关闭"), dash_board);
    QIcon exitIcon;
    exitIcon.addFile(QString::fromUtf8(":/icons/images/exit.bmp"), QSize(), QIcon::Normal, QIcon::On);
    closeButton->setIcon(exitIcon);

    QVBoxLayout* rightPaneVLayout = new QVBoxLayout();
    rightPaneVLayout->addWidget(rightGroupBox);
    rightPaneVLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum));
    rightPaneVLayout->addWidget(closeButton);

    QHBoxLayout* totalHLayout = new QHBoxLayout();
    totalHLayout->addLayout(leftVLayout);
    totalHLayout->addLayout(rightPaneVLayout);

    dash_board->setLayout(totalHLayout);
    retranslate(dash_board);
}

void InstrumentDashBoardUI::buildUpGroupBox(QWidget* dash_board)
{
    upGroupBox = new QGroupBox(QString("Slider and Color"), dash_board);
    upGroupBox->setObjectName(QString("upGroupBox"));
    QGridLayout* upGroupGridLayout = new QGridLayout(upGroupBox);
    upGroupGridLayout->setObjectName(QString("upGroupGridLayout"));

    QLabel* redLabel = new QLabel(QString("Red"), upGroupBox);
    redLabel->setObjectName(QString("redLabel"));

    redSlider = new QSlider(Qt::Orientation::Horizontal, upGroupBox);
    redSlider->setObjectName(QString("redSlider"));
    redSlider->setMaximum(0xFF);
    redSlider->setValue(135);

    QLabel* greenLabel = new QLabel(QString("Green"), upGroupBox);
    greenLabel->setObjectName(QString("greenLabel"));

    greenSlider = new QSlider(upGroupBox);
    greenSlider->setObjectName(QString("greenSlider"));
    greenSlider->setMaximum(0xFF);
    greenSlider->setValue(54);
    greenSlider->setOrientation(Qt::Orientation::Horizontal);

    QLabel* blueLabel = new QLabel(QString("Blue"), upGroupBox);
    blueLabel->setObjectName(QString("blueLabel"));

    blueSlider = new QSlider(Qt::Orientation::Horizontal, upGroupBox);
    blueSlider->setObjectName(QString("blueSlider"));
    blueSlider->setMaximum(0xFF);
    blueSlider->setValue(130);

    QLabel* alphaLabel = new QLabel(QString("Alpha"), upGroupBox);
    alphaLabel->setObjectName(QString("alphaLabel"));

    alphaSlider = new QSlider(Qt::Orientation::Horizontal, upGroupBox);
    alphaSlider->setObjectName(QString("alphaSlider"));
    alphaSlider->setMaximum(0xFF);
    alphaSlider->setValue(96);

    buildColorBlock(upGroupBox);

    upGroupGridLayout->addWidget(redLabel,    0, 0, 1, 1);
    upGroupGridLayout->addWidget(redSlider,   0, 1, 1, 1);
    upGroupGridLayout->addWidget(greenLabel,  1, 0, 1, 1);
    upGroupGridLayout->addWidget(greenSlider, 1, 1, 1, 1);
    upGroupGridLayout->addWidget(blueLabel,   2, 0, 1, 1);
    upGroupGridLayout->addWidget(blueSlider,  2, 1, 1, 1);
    upGroupGridLayout->addWidget(alphaLabel,  3, 0, 1, 1);
    upGroupGridLayout->addWidget(alphaSlider, 3, 1, 1, 1);
    upGroupGridLayout->addWidget(colorBlock,  0, 2, 4, 1);
}

void InstrumentDashBoardUI::buildMidGroupBox(QWidget* dash_board)
{
    midGroupBox = new QGroupBox(QString("Horizontal Slider and progress bar"), dash_board);
    midGroupBox->setObjectName(QString("midGroupBox"));

    hslider = new QSlider(Qt::Orientation::Horizontal, midGroupBox);
    hslider->setObjectName(QString("hslider"));
    hslider->setMaximum(100);
    hslider->setValue(10);
    hslider->setInvertedAppearance(false);
    hslider->setInvertedControls(true);
    hslider->setTickPosition(QSlider::TicksAbove);
    hslider->setTickInterval(0);

    hscrollBar = new QScrollBar(Qt::Orientation::Horizontal, midGroupBox);
    hscrollBar->setObjectName(QString("hscrollBar"));
    hscrollBar->setMaximum(100);
    hscrollBar->setValue(10);
    hscrollBar->setSliderPosition(10);

    hprogressBar = new QProgressBar(midGroupBox);
    hprogressBar->setObjectName(QString("hprogressBar"));
    hprogressBar->setValue(10);
    hprogressBar->setTextVisible(true);
    hprogressBar->setOrientation(Qt::Orientation::Horizontal);
    hprogressBar->setTextDirection(QProgressBar::Direction::TopToBottom);

    QVBoxLayout* vlayout = new QVBoxLayout(midGroupBox);
    vlayout->addWidget(hslider);
    vlayout->addWidget(hscrollBar);
    vlayout->addWidget(hprogressBar);
}

void InstrumentDashBoardUI::buildDownGroupBox(QWidget* dash_board)
{
    downGroupBox = new QGroupBox(QString("Dial and LCD Number"), dash_board);
    downGroupBox->setObjectName(QString("downGroupBox"));

    dial = new QDial(downGroupBox);
    dial->setObjectName(QString("dial"));
    dial->setMaximum(0xFF);
    dial->setSliderPosition(0);
    dial->setTracking(true);
    dial->setWrapping(false);
    dial->setOrientation(Qt::Orientation::Horizontal);
    dial->setNotchTarget(10.00);
    dial->setNotchesVisible(true);

    decimalLcdNum = new QLCDNumber(downGroupBox);
    decimalLcdNum->setObjectName(QString("decimalLcdNum"));
    decimalLcdNum->setSmallDecimalPoint(false);
    decimalLcdNum->setDigitCount(4);
    decimalLcdNum->setMode(QLCDNumber::Dec);
    decimalLcdNum->setSegmentStyle(QLCDNumber::Filled);

    otherLcdNum = new QLCDNumber(downGroupBox);
    otherLcdNum->setObjectName(QString("otherLcdNum"));
    otherLcdNum->setMode(QLCDNumber::Bin);
    otherLcdNum->setDigitCount(8);
    otherLcdNum->setSegmentStyle(QLCDNumber::Filled);

    QGroupBox* displayCarryGroupBox = new QGroupBox(QString("LED显示进制"), downGroupBox);
    displayCarryGroupBox->setObjectName(QString("displayCarryGroupBox"));

    binRadioButton = new QRadioButton(QString("二进制"), displayCarryGroupBox);
    binRadioButton->setChecked(true);
    octRadioButton = new QRadioButton(QString("八进制"), displayCarryGroupBox);
    octRadioButton->setChecked(false);
    hexRadioButton = new QRadioButton(QString("十六进制"),displayCarryGroupBox);
    hexRadioButton->setChecked(false);

    QVBoxLayout* vlayout = new QVBoxLayout(displayCarryGroupBox);
    vlayout->addWidget(binRadioButton);
    vlayout->addWidget(octRadioButton);
    vlayout->addWidget(hexRadioButton);

    QGridLayout* glayout = new QGridLayout(downGroupBox);
    glayout->addWidget(dial, 0, 0, 2, 1);
    glayout->addWidget(decimalLcdNum, 0, 1, 1, 1);
    glayout->addWidget(displayCarryGroupBox, 0, 2, 2, 1);
    glayout->addWidget(otherLcdNum, 1, 1, 1, 1);
}

void InstrumentDashBoardUI::buildColorBlock(QGroupBox* group_box)
{
    colorBlock = new QTextEdit(group_box);
    colorBlock->setObjectName(QString("colorBlock"));
    // colorBlock->setMaximumWidth(150);
    colorBlock->setMaximumSize(QSize(100, 100));

    QPalette palette;
    QBrush brush(QColor(170, 255, 0, 255));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Base, brush);
    palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Base, brush);

    QBrush brush2(QColor(240, 240, 240, 255));
    brush2.setStyle((Qt::BrushStyle::SolidPattern));
    palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush2);

    colorBlock->setPalette(palette);
}

void InstrumentDashBoardUI::buildRightGroupBox(QWidget* dash_board)
{
    rightGroupBox = new QGroupBox(QString("垂直滑动块和进度条"), dash_board);
    vslider = new QSlider(Qt::Orientation::Vertical, rightGroupBox);
    vslider->setMaximum(100);
    vslider->setValue(25);
    vslider->setInvertedAppearance(false);
    vslider->setInvertedControls(true);
    vslider->setTickPosition(QSlider::TicksLeft);
    vslider->setTickInterval(0);

    vscrollBar = new QScrollBar(Qt::Orientation::Vertical, rightGroupBox);
    vscrollBar->setMaximum(100);
    vscrollBar->setValue(25);
    vscrollBar->setSliderPosition(25);
    vscrollBar->setSliderDown(false);

    vprogressBar = new QProgressBar(rightGroupBox);
    vprogressBar->setValue(25);
    vprogressBar->setTextVisible(true);
    vprogressBar->setOrientation(Qt::Orientation::Vertical);
    vprogressBar->setTextDirection(QProgressBar::Direction::BottomToTop);

    QHBoxLayout* hlayout = new QHBoxLayout(rightGroupBox);
    hlayout->addWidget(vslider);
    hlayout->addWidget(vscrollBar);
    hlayout->addWidget(vprogressBar);
}

void InstrumentDashBoardUI::retranslate(QWidget* dash_board)
{
    dash_board->setWindowTitle(QCoreApplication::translate("dash_board", "显示仪表盘", nullptr));
    upGroupBox->setTitle(QCoreApplication::translate("dash_board", "颜色滑动块", nullptr));
    midGroupBox->setTitle(QCoreApplication::translate("dash_board", "水平滑动块和进度条", nullptr));
    downGroupBox->setTitle(QCoreApplication::translate("dash_board", "表盘和LED数码管", nullptr));
}