/*!
 *  \file       UI_Dialog.cpp
 *  \brief
 *
 */


#include "UI_Dialog.hpp"

#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QGridLayout>
#include <QPlainTextEdit>

void Ui::Dialog::setupUI(QDialog *dialog)
{
    if (dialog->objectName().isEmpty())
    {
        dialog->setObjectName(QString::fromUtf8("dialog"));
    }

    btn_host_name_ip = new QPushButton(dialog);
    btn_host_name_ip->setObjectName(QString::fromUtf8("btn_host_name_ip"));
    btn_host_name_ip->setText(QObject::tr("QHostInfo获取本机主机名和IP地址"));

    btn_all_addresses = new QPushButton(dialog);
    btn_all_addresses->setObjectName(QString::fromUtf8("btn_all_addresses"));
    btn_all_addresses->setText(QObject::tr("QNetworkInterface::allAddresses()"));

    chkbox_only_ipv4 = new QCheckBox(dialog);
    chkbox_only_ipv4->setObjectName(QString::fromUtf8("chkbox_only_ipv4"));
    chkbox_only_ipv4->setText(QObject::tr("只显示IPv4协议地址"));
    chkbox_only_ipv4->setChecked(true);

    btn_all_interfaces = new QPushButton(dialog);
    btn_all_interfaces->setObjectName(QString::fromUtf8("btn_all_interfaces"));
    btn_all_interfaces->setText(QObject::tr("QNetworkInterface::allInterfaces()"));

    btn_query_dns_ip = new QPushButton(dialog);
    btn_query_dns_ip->setObjectName(QString::fromUtf8("btn_query_dns_ip"));
    btn_query_dns_ip->setText(QObject::tr("QHostInfo查找域名的IP地址"));

    edit_website_url = new QLineEdit(dialog);
    edit_website_url->setObjectName(QString::fromUtf8("edit_website_url"));
    edit_website_url->setText(QApplication::translate("dialog", "www.163.com", nullptr));

    btn_clean_text = new QPushButton(dialog);
    btn_clean_text->setObjectName(QString::fromUtf8("btn_clean_text"));
    btn_clean_text->setText(QObject::tr("清空文本框"));

    QGridLayout *grid_layout = new QGridLayout(dialog);
    grid_layout->setSpacing(6);
    grid_layout->setContentsMargins(12, 12, 12, 12);
    grid_layout->addWidget(btn_host_name_ip, 0, 0, 1, 1);
    grid_layout->addWidget(btn_all_addresses, 0, 1, 1, 1);
    grid_layout->addWidget(chkbox_only_ipv4, 1, 0, 1, 1);
    grid_layout->addWidget(btn_all_interfaces, 1, 1, 1, 1);
    grid_layout->addWidget(btn_query_dns_ip, 2, 0, 1, 1);
    grid_layout->addWidget(edit_website_url, 2, 1, 1, 1);
    grid_layout->addWidget(btn_clean_text, 3, 1, 1, 1);

    plain_text = new QPlainTextEdit(dialog);
    plain_text->setObjectName(QString::fromUtf8("plain_ttext"));
    plain_text->setReadOnly(true);

    grid_layout->addWidget(plain_text, 4, 0, 4, 2);
}
