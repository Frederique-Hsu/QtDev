/*!
 *  \file       MyThread.hpp
 *  \brief
 *
 */


#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QObject* parent = nullptr);
public:
    void run() override;
};
