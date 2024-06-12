/*!
 *  \file       mainwindow.cpp
 *  \brief
 *
 */


#include "mainwindow.hpp"
#include "resultdialog.hpp"

#include "ui_mainwindow.hpp"

#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          results(nullptr)
{
    ui->setupUi(this);

    QObject::connect(ui->aboutButton, &QPushButton::clicked,
                     this, &MainWindow::OnAboutButtonClicked);
    QObject::connect(this, &MainWindow::computed,
                     this, &MainWindow::ShowResult);
    QObject::connect(ui->plusButton, &QPushButton::clicked,
                     this, &MainWindow::OnPlusButtonClicked);
    QObject::connect(ui->minusButton, &QPushButton::clicked,
                     this, &MainWindow::OnMinusButtonClicked);
    QObject::connect(ui->multiplyButton, &QPushButton::clicked,
                     this, &MainWindow::OnMultiplyButtonClicked);
    QObject::connect(ui->divideButton, &QPushButton::clicked,
                     this, &MainWindow::OnDivideButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;

    if (results != nullptr)
    {
        delete results;
    }
}

void MainWindow::OnAboutButtonClicked()
{
    QMessageBox mesgBox;
    mesgBox.setIconPixmap(QPixmap(":/icon.png"));
    mesgBox.setText(QString("Lorem ipsum."));
    mesgBox.setWindowTitle(QString("About"));
    mesgBox.exec();
}

void MainWindow::ShowResult(float res)
{
    if (results == nullptr)
    {
        results = new ResultDialog(this);
    }
    results->setResult(res);
    results->exec();
}

MainWindow::Arguments MainWindow::arguments()
{
    bool ok1, ok2;
    float num1 = ui->argument1Input->text().toFloat(&ok1);
    float num2 = ui->argument2Input->text().toFloat(&ok2);

    if (ok1 == false || ok2 == false)
    {
        QMessageBox mesgBox;
        mesgBox.setIconPixmap(QPixmap(":/icon.png"));
        mesgBox.setText("One of your entries is not a valid number.");
        mesgBox.setWindowTitle(QString("Error"));
        mesgBox.exec();
    }
    return Arguments(num1, num2);
}

void MainWindow::OnPlusButtonClicked()
{
    Arguments args = arguments();
    emit computed(args.first + args.second);
}

void MainWindow::OnMinusButtonClicked()
{
    Arguments args = arguments();
    emit computed(args.first - args.second);
}

void MainWindow::OnMultiplyButtonClicked()
{
    Arguments args = arguments();
    emit computed(args.first * args.second);
}

void MainWindow::OnDivideButtonClicked()
{
    Arguments args = arguments();
    emit computed(args.first / args.second);
}
