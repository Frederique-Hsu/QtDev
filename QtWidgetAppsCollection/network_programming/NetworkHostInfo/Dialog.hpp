/*!
 *  \file       Dialog.hpp
 *  \brief
 *
 */


#pragma once

#include <QDialog>
#include <QHostInfo>

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *m_ui;

private:
    void lookupHostInfoBy(const QHostInfo &host_info);
    QString protocolName(const QAbstractSocket::NetworkLayerProtocol &protocol);

private slots:
    void Slot_onHostNameIpButtonClicked();
    void Slot_onAllAddressesButtonClicked();
    void Slot_onAllInterfacesButtonClicked();
    void Slot_onQueryDnsIpButtonClicked();
    void Slot_onClecnTextButtonClicked();
};
