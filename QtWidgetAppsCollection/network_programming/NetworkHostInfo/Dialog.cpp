/*!
 *  \file       Dialog.cpp
 *  \brief
 *
 */


#include "Dialog.hpp"

#include <QPushButton>
#include <QCheckBox>
#include <QPlainTextEdit>
#include <QNetworkInterface>
#include <QLineEdit>

#include "UI_Dialog.hpp"

Dialog::Dialog(QWidget *parent) : QDialog(parent), m_ui(new Ui::Dialog)
{
    m_ui->setupUI(this);

    QObject::connect(m_ui->btn_host_name_ip,   &QPushButton::clicked, this, &Dialog::Slot_onHostNameIpButtonClicked);
    QObject::connect(m_ui->btn_all_addresses,  &QPushButton::clicked, this, &Dialog::Slot_onAllAddressesButtonClicked);
    QObject::connect(m_ui->btn_all_interfaces, &QPushButton::clicked, this, &Dialog::Slot_onAllInterfacesButtonClicked);

    connect(m_ui->btn_query_dns_ip, &QPushButton::clicked, this, &Dialog::Slot_onQueryDnsIpButtonClicked);
    connect(m_ui->btn_clean_text,   &QPushButton::clicked, this, &Dialog::Slot_onClecnTextButtonClicked);
}

Dialog::~Dialog()
{
    if (m_ui)
    {
        delete m_ui;
        m_ui = nullptr;
    }
}

void Dialog::lookupHostInfoBy(const QHostInfo &host_info)
{
    QList<QHostAddress> addr_list = host_info.addresses();
    if (addr_list.empty()) { return; }

    for (unsigned index = 0; index < addr_list.count(); ++index)
    {
        const QHostAddress& host_addr = addr_list.at(index);
        bool is_only_show_ipv4 = m_ui->chkbox_only_ipv4->isChecked();
        if (is_only_show_ipv4)
        {
            is_only_show_ipv4 = (QAbstractSocket::IPv4Protocol == host_addr.protocol());
        }
        else
        {
            is_only_show_ipv4 = true;
        }

        if (is_only_show_ipv4)
        {
            m_ui->plain_text->appendPlainText(QString("协议： ") + protocolName(host_addr.protocol()));
            m_ui->plain_text->appendPlainText("IP地址：" + host_addr.toString() + "\n");
        }
    }
}

QString Dialog::protocolName(const QAbstractSocket::NetworkLayerProtocol &protocol)
{
    switch(protocol)
    {
    case QAbstractSocket::IPv4Protocol:
        return "IPv4 Protocol";
    case QAbstractSocket::IPv6Protocol:
        return "IPv6 Protocol";
    case QAbstractSocket::AnyIPProtocol:
        return "Any IP Protocol";
    default:
        return "Unknown Network Layer Protocol";
    }
}

void Dialog::Slot_onHostNameIpButtonClicked()
{
    QString host_name = QHostInfo::localHostName();
    m_ui->plain_text->appendPlainText("本机主机名：" + host_name);

    QHostInfo host_info = QHostInfo::fromName(host_name);
    QList<QHostAddress> addr_list = host_info.addresses();
    if (addr_list.empty()) { return; }

    for (const QHostAddress &host_addr : addr_list)
    {
        bool is_only_show_ipv4 = m_ui->chkbox_only_ipv4->isChecked();
        if (is_only_show_ipv4)
        {
            is_only_show_ipv4 = (host_addr.protocol() == QAbstractSocket::IPv4Protocol);
        }
        else
        {
            is_only_show_ipv4 = true;
        }

        if (is_only_show_ipv4)
        {
            m_ui->plain_text->appendPlainText("协议：" + protocolName(host_addr.protocol()));
            m_ui->plain_text->appendPlainText("本机IP地址：" + host_addr.toString() + "\n");
        }
    }
}

void Dialog::Slot_onAllAddressesButtonClicked()
{
    QList<QHostAddress> addr_list = QNetworkInterface::allAddresses();
    if (addr_list.isEmpty()) { return; }
    for (const QHostAddress &addr : addr_list)
    {
        bool is_only_show_ipv4 = m_ui->chkbox_only_ipv4->isChecked();
        if (is_only_show_ipv4)
        {
            is_only_show_ipv4 = (addr.protocol() == QAbstractSocket::IPv4Protocol);
        }
        else
        {
            is_only_show_ipv4 = true;
        }

        if (is_only_show_ipv4)
        {
            m_ui->plain_text->appendPlainText("协议：" + protocolName(addr.protocol()));
            m_ui->plain_text->appendPlainText("IP地址：" + addr.toString() + "\n");
        }
    }
}

void Dialog::Slot_onAllInterfacesButtonClicked()
{
    QList<QNetworkInterface> interface_list = QNetworkInterface::allInterfaces();
    for (const QNetworkInterface &interface : interface_list)
    {
        if (!interface.isValid()) { continue; }

        m_ui->plain_text->appendPlainText("设备名称：" + interface.humanReadableName());
        m_ui->plain_text->appendPlainText("硬件地址：" + interface.hardwareAddress());

        QList<QNetworkAddressEntry> addr_entry_list = interface.addressEntries();
        for (const QNetworkAddressEntry &addr_entry : addr_entry_list)
        {
            m_ui->plain_text->appendPlainText("\tIP地址：" + addr_entry.ip().toString());
            m_ui->plain_text->appendPlainText("\t子网掩码：" + addr_entry.netmask().toString());
            m_ui->plain_text->appendPlainText("\t广播地址：" + addr_entry.broadcast().toString() + "\n");
        }
        m_ui->plain_text->appendPlainText("\n");
    }
}

void Dialog::Slot_onQueryDnsIpButtonClicked()
{
    QString website_url = m_ui->edit_website_url->text();
    m_ui->plain_text->appendPlainText("正在查找网站的主机信息：" + website_url);
    QHostInfo::lookupHost(website_url, this, &Dialog::lookupHostInfoBy);
}

void Dialog::Slot_onClecnTextButtonClicked()
{
    m_ui->plain_text->clear();
}
