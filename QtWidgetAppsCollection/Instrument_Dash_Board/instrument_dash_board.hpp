/*!
 *  \file       instrument_dash_board.hpp
 *  \brief
 *
 */


#pragma once


#include <QWidget>


class InstrumentDashBoardUI;

class InstrumentDashBoard : public QWidget
{
    Q_OBJECT
public:
    explicit InstrumentDashBoard(QWidget* parent = nullptr);
    ~InstrumentDashBoard();
private:
    InstrumentDashBoardUI* ui;
public slots:
    void onColorSliderValueChanged(int value);
    void onDialValueChanged(int value);
    void onBinRadioButtonClicked();
    void onOctRadioButtonClicked();
    void onHexRadioButtonClicked();
    void onHorSliderValueChanged(int value);
    void onVerSliderValueChanged(int value);
    void onHorScrollBarSliderMoved(int position);
    void onVerScrollBarSliderMoved(int position);
};
