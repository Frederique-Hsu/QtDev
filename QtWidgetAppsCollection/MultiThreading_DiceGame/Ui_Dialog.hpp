/*!
 *  \file       Ui_Dialog.hpp
 *  \brief      
 *  
 */


#pragma once

#include <QDialog>

class QGroupBox;
class QPushButton;
class QPlainTextEdit;
class QLabel;

namespace Ui
{
    class Dialog
    {
    public:
        QPushButton *button_start_thread;
        QPushButton *button_begin_dice;
        QPushButton *button_pause_dice;
        QPushButton *button_terminate_thread;
        QPushButton *button_clean_text;

        QPlainTextEdit *plain_text_edit;
        QLabel *label_dice_picture;
        QLabel *label_bottom_showstatus;

    public:
        void setupUi(QDialog *dialog);
        void retranslateUi(QDialog *dialog);
    
    private:
        QGroupBox *grpbox_thread;
    };
}