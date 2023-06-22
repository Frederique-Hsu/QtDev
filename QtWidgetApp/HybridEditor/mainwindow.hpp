/*!
 *  \file       mainwindow.hpp
 *  \brief      Define the MainWindow UI class.
 *
 */


#pragma once


#include <QMainWindow>

QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class QLabel;
class QProgressBar;
class QSpinBox;
class QFontComboBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel* labelCurrFile;
    QProgressBar* progressBar;
    QSpinBox* spinFontSize;
    QFontComboBox* comboFont;

    void initUI();
    void initSignalSlots();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actFontBold_triggered(bool checked);
    void on_textEdit_copyAvailable(bool b);
    void on_textEdit_selectionChanged();
    void on_spinFontSize_valueChanged(int fontSize);
    void on_comboFont_currentIndexChanged(QString& fontName);
private:
    Ui::MainWindow *ui;
};
