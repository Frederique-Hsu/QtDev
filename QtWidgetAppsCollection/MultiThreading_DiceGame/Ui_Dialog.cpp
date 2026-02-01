/*!
 *  \file       Ui_Dialog.cpp
 *  \brief      
 *  
 */


#include "Ui_Dialog.hpp"

#include <QApplication>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QLabel>


namespace Ui
{
    void Dialog::setupUi(QDialog *dialog)
    {
        if (dialog->objectName().isEmpty())
        {
            dialog->setObjectName(QString::fromUtf8("dialog"));
        }

        grpbox_thread = new QGroupBox(dialog);
        grpbox_thread->setObjectName(QString::fromUtf8("grpbox_thread"));

        QVBoxLayout *vlayout = new QVBoxLayout(grpbox_thread);
        vlayout->setObjectName(QString::fromUtf8("vlayout"));
        vlayout->setSpacing(6);
        vlayout->setContentsMargins(12, 12, 12, 12);

        auto plotButtonsUI = [this](QVBoxLayout *vlayout) 
        {
            QHBoxLayout *hlayout_buttons = new QHBoxLayout();
            hlayout_buttons->setObjectName(QString::fromUtf8("hlayout_buttons"));
            hlayout_buttons->setSpacing(6);

            button_start_thread = new QPushButton(grpbox_thread);
            button_start_thread->setObjectName(QString::fromUtf8("button_start_thread"));
            hlayout_buttons->addWidget(button_start_thread);

            button_begin_dice = new QPushButton(grpbox_thread);
            button_begin_dice->setObjectName(QString::fromUtf8("button_begin_dice"));
            hlayout_buttons->addWidget(button_begin_dice);

            button_pause_dice = new QPushButton(grpbox_thread);
            button_pause_dice->setObjectName(QString::fromUtf8("button_pause_dice"));
            hlayout_buttons->addWidget(button_pause_dice);

            button_terminate_thread = new QPushButton(grpbox_thread);
            button_terminate_thread->setObjectName(QString::fromUtf8("button_terminate_thread"));
            hlayout_buttons->addWidget(button_terminate_thread);

            button_clean_text = new QPushButton(grpbox_thread);
            button_clean_text->setObjectName(QString::fromUtf8("button_clean_text"));
            hlayout_buttons->addWidget(button_clean_text);

            vlayout->addLayout(hlayout_buttons);
        };
        plotButtonsUI(vlayout);

        auto plotDiceUI = [this, &vlayout]() 
        {
            plain_text_edit = new QPlainTextEdit(grpbox_thread);
            plain_text_edit->setObjectName(QString::fromUtf8("plaint_text_edit"));

            label_dice_picture = new QLabel(grpbox_thread);
            label_dice_picture->setObjectName(QString::fromUtf8("label_dice_picture"));
            label_dice_picture->setMinimumSize(QSize(150, 0));
            label_dice_picture->setPixmap(QString::fromUtf8(":/dice/images/d0.jpg"));

            QHBoxLayout *hlayout = new QHBoxLayout();
            hlayout->setSpacing(6);
            hlayout->addWidget(plain_text_edit);
            hlayout->addWidget(label_dice_picture);

            vlayout->addLayout(hlayout);
        };
        plotDiceUI();

        auto plotBottomUI = [this, &vlayout]() 
        {
            label_bottom_showstatus = new QLabel(grpbox_thread);
            label_bottom_showstatus->setObjectName(QString::fromUtf8("label_bottom_showstatus"));
            vlayout->addWidget(label_bottom_showstatus);
        };
        plotBottomUI();

        auto plotCentralWindow = [this](QDialog *dialog)
        {
            QVBoxLayout *vlayout_central_window = new QVBoxLayout(dialog);
            vlayout_central_window->setObjectName(QString::fromUtf8("vlayout_central_window"));
            vlayout_central_window->setSpacing(6);
            vlayout_central_window->setContentsMargins(3, 3, 3, 3);
            vlayout_central_window->addWidget(grpbox_thread);
        };
        plotCentralWindow(dialog);

        retranslateUi(dialog);
    }

    void Dialog::retranslateUi(QDialog *dialog)
    {
        dialog->setWindowTitle(QApplication::translate("dialog",
                                                       QObject::tr("多线程，使用信号跟主线程通信").toStdString().c_str(),
                                                       nullptr));
        grpbox_thread->setTitle(QApplication::translate("dialog",
                                                        QObject::tr("线程").toStdString().c_str(),
                                                        nullptr));
        button_start_thread->setText(QApplication::translate("dialog",
                                                             QObject::tr("启动线程").toStdString().c_str(),
                                                             nullptr));
        button_begin_dice->setText(QApplication::translate("dialog",
                                                           QObject::tr("开始").toStdString().c_str(),
                                                           nullptr));
        button_pause_dice->setText(QApplication::translate("dialog",
                                                           QObject::tr("暂停").toStdString().c_str(),
                                                           nullptr));
        button_terminate_thread->setText(QApplication::translate("dialog",
                                                                 QObject::tr("结束线程").toStdString().c_str(),
                                                                 nullptr));
        button_clean_text->setText(QApplication::translate("dialog",
                                                           QObject::tr("清空文本").toStdString().c_str(),
                                                           nullptr));
        label_dice_picture->setText(QString());
        label_bottom_showstatus->setText(QApplication::translate("dialog",
                                                                 QObject::tr("Thread Status: ").toStdString().c_str(),
                                                                 nullptr));
    }
}
