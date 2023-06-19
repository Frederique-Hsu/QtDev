/*!
 *  \file       access_sql_db.hpp
 *  \brief
 *
 */


#pragma once

#include <QWidget>

class QSqlTableModel;

class AccessSqlDatabase : public QWidget
{
    Q_OBJECT
public:
    AccessSqlDatabase(QWidget* parent = nullptr);
private:
    QSqlTableModel* m_model;
};
