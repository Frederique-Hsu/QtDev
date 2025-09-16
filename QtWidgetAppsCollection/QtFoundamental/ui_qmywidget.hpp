/*!
 *  \file       ui_qmywidget.hpp
 *  \brief      Define the UI for user-defined QMyWidget, based on QWidget.
 *
 */


#pragma once

class QSpinBox;
class QWidget;
class QPushButton;
class QPlainTextEdit;

class UI_QMyWidget
{
public:
    QSpinBox *spinBoy, *spinGirl;
    QPushButton *btnBoyIncrement, *btnGirlIncrement;
    QPushButton *btnClassInfo;
    QPushButton *btnClear;
    QPlainTextEdit *textEdit;
public:
    void setupUI(QWidget* QMyWidget);
    void retranslateUI(QWidget* QMyWidget);
};


namespace UI
{
    class QMyWidget : public UI_QMyWidget
    {
    };
}
