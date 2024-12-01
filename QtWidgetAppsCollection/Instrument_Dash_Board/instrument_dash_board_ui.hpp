/*!
 *  \file       instrument_dash_board_ui.hpp
 *  \brief
 *
 */


#pragma once

class QWidget;
class QGroupBox;
class QSlider;
class QTextEdit;
class QScrollBar;
class QProgressBar;
class QDial;
class QLCDNumber;
class QRadioButton;
class QPushButton;

class InstrumentDashBoardUI
{
public:
    QSlider *redSlider, *greenSlider, *blueSlider, *alphaSlider;
    QTextEdit* colorBlock;
    QSlider *hslider;
    QScrollBar* hscrollBar;
    QProgressBar* hprogressBar;
    QDial* dial;
    QLCDNumber *decimalLcdNum, *otherLcdNum;
    QRadioButton *binRadioButton, *hexRadioButton, *octRadioButton;
    QSlider* vslider;
    QScrollBar* vscrollBar;
    QProgressBar* vprogressBar;
    QPushButton* closeButton;
public:
    void setupUI(QWidget* dash_board);
    void retranslate(QWidget* dash_board);
private:
    QGroupBox *upGroupBox, *midGroupBox, *downGroupBox;
    QGroupBox *rightGroupBox;
private:
    void buildUpGroupBox(QWidget* dash_board);
    void buildMidGroupBox(QWidget* dash_bord);
    void buildDownGroupBox(QWidget* dash_board);
    void buildRightGroupBox(QWidget* dash_board);
    void buildColorBlock(QGroupBox* up_group_box);
};