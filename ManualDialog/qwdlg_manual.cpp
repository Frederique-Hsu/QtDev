/*!
 *  \file       qwdlg_manual.cpp
 *  \brief
 *
 */


#include "qwdlg_manual.hpp"

#include <QPlainTextEdit>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QPushButton>

QWDlgManual::QWDlgManual(QWidget* parent) : QWidget(parent)
{
    setup_UI();
    init_signal_slots();
    setWindowTitle("Manual Dialog");
}

QWDlgManual::~QWDlgManual()
{
}

void QWDlgManual::on_under_box_checked(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_italic_box_checked(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_bold_box_checked(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::setup_UI()
{
    chkBoxUnder = new QCheckBox(tr("Underline"));
    chkBoxItalic = new QCheckBox(tr("Italic"));
    chkBoxBold = new QCheckBox(tr("Bold"));

    QHBoxLayout* hlayout = new QHBoxLayout;
    hlayout->addWidget(chkBoxUnder);
    hlayout->addWidget(chkBoxItalic);
    hlayout->addWidget(chkBoxBold);

    rbtnBlack = new QRadioButton(tr("Black"));
    rbtnRed = new QRadioButton(tr("Red"));
    rbtnBlue = new QRadioButton(tr("Blue"));

    QHBoxLayout* hlayout4RadioButtons = new QHBoxLayout;
    hlayout4RadioButtons->addWidget(rbtnBlack);
    hlayout4RadioButtons->addWidget(rbtnRed);
    hlayout4RadioButtons->addWidget(rbtnBlue);

    btnOK = new QPushButton(tr("确定"));
    btnCancel = new QPushButton(tr("取消"));
    btnClose = new QPushButton(tr("退出"));

    QHBoxLayout* hlayout4Buttons = new QHBoxLayout;
    hlayout4Buttons->addStretch();
    hlayout4Buttons->addWidget(btnOK);
    hlayout4Buttons->addWidget(btnCancel);
    hlayout4Buttons->addStretch();
    hlayout4Buttons->addWidget(btnClose);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello world\n\nIt is my demo.");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    QVBoxLayout* vlayout = new QVBoxLayout;
    vlayout->addLayout(hlayout);
    vlayout->addLayout(hlayout4RadioButtons);
    vlayout->addWidget(txtEdit);
    vlayout->addLayout(hlayout4Buttons);

    setLayout(vlayout);
}

void QWDlgManual::init_signal_slots()
{
    QObject::connect(rbtnBlack, SIGNAL(clicked()), this, SLOT(set_text_font_color()));
    QObject::connect(rbtnRed, &QRadioButton::clicked, this, &QWDlgManual::set_text_font_color);
    QObject::connect(rbtnBlue, SIGNAL(clicked()), this, SLOT(set_text_font_color()));

    connect(chkBoxUnder, SIGNAL(clicked(bool)), this, SLOT(on_under_box_checked(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(on_italic_box_checked(bool)));
    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(on_bold_box_checked(bool)));

    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

void QWDlgManual::set_text_font_color()
{
    QPalette palette = txtEdit->palette();
    if (rbtnBlue->isChecked())
    {
        palette.setColor(QPalette::Text, Qt::blue);
    }
    else if (rbtnRed->isChecked())
    {
        palette.setColor(QPalette::Text, Qt::red);
    }
    else if (rbtnBlack->isChecked())
    {
        palette.setColor(QPalette::Text, Qt::black);
    }
    else
    {
        palette.setColor(QPalette::Text, Qt::black);
    }
    txtEdit->setPalette(palette);
}
