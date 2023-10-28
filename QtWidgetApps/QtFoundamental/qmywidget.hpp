/*!
 *  \file       qmywidget.hpp
 *  \brief
 *
 */



#pragma once

#include <QWidget>

class QPerson;

namespace UI
{
class QMyWidget;
}

class QMyWidget : public QWidget
{
    Q_OBJECT
private:
    QPerson *boy;
    QPerson *girl;
public:
    explicit QMyWidget(QWidget *parent = nullptr);
    ~QMyWidget();
private:
    UI::QMyWidget* ui;
private slots:
    void on_age_changed(int value);
    void on_spin_value_changed(int arg);
    void on_btnClear_clicked();
    void on_btnBoyIncrement_clicked();
    void on_btnGirlIncrement_clicked();
    void on_btnClassInfo_clicked();

};
