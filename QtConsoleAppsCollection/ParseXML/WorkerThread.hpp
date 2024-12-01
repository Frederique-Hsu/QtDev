/*!
 *  \file       WorkerThread.hpp
 *  \brief
 *
 */



#pragma once


#include <QThread>

class QNetworkAccessManager;
class QNetworkReply;

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject* owner);
private:
    bool m_cancelled;
    QNetworkAccessManager* m_net_manager;
    QNetworkReply* m_reply;
public:
    void run();

    void fetch(const QString& url);
    void cancel();
signals:
    void error(const QString& error);
    void finished(const QMap<QString, QString>& result);
private slots:
    void handleNetworkFinished(QNetworkReply* reply);
};
