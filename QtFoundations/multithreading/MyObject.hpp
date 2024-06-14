/*!
 *  \file       MyObject.hpp
 *  \brief
 *
 */


#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
public:
    MyObject(QObject* parent = nullptr);
public:
    void startWorkInAThread();
};
