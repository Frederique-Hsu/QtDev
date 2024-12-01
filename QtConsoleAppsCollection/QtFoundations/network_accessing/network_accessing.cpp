/*!
 *  \file       network_accessing.cpp
 *  \brief
 *
 */


#include "network_accessing.hpp"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

bool openNetworkConnection()
{
    return bool{};
}

void performHttpRequests()
{
    QNetworkAccessManager* netManager = new QNetworkAccessManager();

    QUrl url;
    QNetworkReply* reply = netManager->get(QNetworkRequest(QUrl(url)));
}
