/*!
 *  \file       qwdlg_manual.hpp
 *  \brief
 *
 */



#pragma once

#include <QWidget>

class QCheckBox;
class QRadioButton;
class QPlainTextEdit;
class QPushButton;

class QWDlgManual : public QWidget
{
    Q_OBJECT
public:
    explicit QWDlgManual(QWidget* parent = nullptr);
    ~QWDlgManual();
private:
    QCheckBox* chkBoxUnder;
    QCheckBox* chkBoxItalic;
    QCheckBox* chkBoxBold;

    QRadioButton* rbtnBlack;
    QRadioButton* rbtnRed;
    QRadioButton* rbtnBlue;

    QPlainTextEdit* txtEdit;

    QPushButton* btnOK;
    QPushButton* btnCancel;
    QPushButton* btnClose;
private slots:
    void on_under_box_checked(bool checked);
    void on_italic_box_checked(bool checked);
    void on_bold_box_checked(bool checked);

    void set_text_font_color();
private:
    void setup_UI();
    void init_signal_slots();
};
