/*!
 *  \file       mainwindow.cpp
 *  \brief      Implement the MainWindow UI class.
 *
 */


#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    initSignalSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    /* 状态栏添加组件 */
    labelCurrFile = new QLabel;
    labelCurrFile->setMinimumWidth(150);
    labelCurrFile->setText(tr("当前文件: "));
    ui->statusbar->addWidget(labelCurrFile);

    progressBar = new QProgressBar;
    progressBar->setMaximumWidth(200);
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar);

    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->textEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);
    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinFontSize);

    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(new QLabel("字体"));
    comboFont = new QFontComboBox;
    comboFont->setMinimumWidth(150);
    ui->toolBar->addWidget(comboFont);

    setCentralWidget(ui->textEdit);
}


void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat format = ui->textEdit->currentCharFormat();
    if (checked)
    {
        format.setFontWeight(QFont::Bold);
    }
    else
    {
        format.setFontWeight(QFont::Normal);
    }
    ui->textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->textEdit->canPaste());
}

void MainWindow::on_textEdit_selectionChanged()
{
    QTextCharFormat format = ui->textEdit->currentCharFormat();
    ui->actFontItalic->setChecked(format.fontItalic());
    ui->actFontBold->setChecked(format.font().bold());
    ui->actFontUnderline->setChecked(format.fontUnderline());
}

void MainWindow::initSignalSlots()
{
    QObject::connect(spinFontSize,
                     SIGNAL(valueChanged(int)),
                     this,
                     SLOT(on_spinFontSize_valueChanged(int)));
    QObject::connect(comboFont,
                     SIGNAL(currentIndexChanged(QString&)),
                     this,
                     SLOT(on_comboFont_currentIndexChanged(QString&)));
}

void MainWindow::on_spinFontSize_valueChanged(int fontSize)
{
    QTextCharFormat format;
    format.setFontPointSize(fontSize);
    ui->textEdit->mergeCurrentCharFormat(format);
    progressBar->setValue(fontSize);
}

void MainWindow::on_comboFont_currentIndexChanged(QString& fontName)
{
    QTextCharFormat format;
    format.setFontFamily(fontName);
    ui->textEdit->mergeCurrentCharFormat(format);
}
