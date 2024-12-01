/*!
 *  \file       WorkerThread.cpp
 *  \brief
 *
 */


#include "WorkerThread.hpp"

#include <QNetworkAccessManager>
#include <QXmlStreamReader>
#include <QNetworkReply>
#include <QDebug>
#include <QMap>

WorkerThread::WorkerThread(QObject* owner)
{
    this->setParent(owner);

    m_net_manager = new QNetworkAccessManager(this);
    QObject::connect(m_net_manager, &QNetworkAccessManager::finished,
                     this, &WorkerThread::handleNetworkFinished);
}

void WorkerThread::run()
{
    QXmlStreamReader xml;
    bool gotValue = false;
    QString value;
    QString field_name;
    QMap<QString, QString> result;

    xml.setDevice(m_reply);
    while (!xml.atEnd())
    {
        if (m_cancelled)
        {
            break;
        }
        QXmlStreamReader::TokenType type = xml.readNext();
        bool gotEntry = false;
        switch (type)
        {
        case QXmlStreamReader::StartElement:
        {
            QString tag = xml.name().toString().toLower();
            QString file_name = tag;
            gotValue = false;
            qDebug() << "tag = " << tag;
            break;
        }
        case QXmlStreamReader::Characters:
            if (!gotValue)
            {
                value = xml.text().toString().simplified();
                if (!value.isEmpty())
                {
                    gotValue = true;
                    qDebug() << "value = " << value;
                }
            }
            break;
        case QXmlStreamReader::EndElement:
            if (gotValue && gotEntry)
            {
                result[field_name] = value;
            }
            gotEntry = false;
            gotValue = false;
            break;
        default:
            break;
        }
    }
    bool successful = xml.hasError() ? false : true;
    if (!m_cancelled && successful)
    {
        emit finished(result);
    }
    else if (!m_cancelled)
    {
        emit error(tr("Could not interpret the server's response"));
    }
}

void WorkerThread::fetch(const QString& url)
{
    if (isRunning())
    {
        this->cancel();
    }
    QNetworkReply* reply = m_net_manager->get(QNetworkRequest(QUrl(url)));
    if (reply == nullptr)
    {
        emit error(tr("Could not contact the server."));
    }
}

void WorkerThread::cancel()
{
    m_cancelled = true;
    wait();
}

void WorkerThread::handleNetworkFinished(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NetworkError::NoError)
    {
        if (isRunning() == false)
        {
            m_reply = reply;
            start();
        }
    }
    else
    {
        emit error(tr("A network error occurred."));
        qDebug() << QString("network error %1").arg(reply->error());
    }
}
