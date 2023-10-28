/*!
 *  \file       qmyclass.hpp
 *  \brief
 *
 */


#pragma once

#include <QObject>

class QMyClass : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author", "Frederique Hsu")
    Q_CLASSINFO("company", "BMW")
    Q_CLASSINFO("version ", "3.0.1")
public:
    QMyClass(QObject* parent = nullptr);
};
