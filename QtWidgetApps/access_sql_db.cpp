/*!
 *  \file       access_sql_db.cpp
 *  \brief
 *
 */


#include "access_sql_db.hpp"

#include <QSqlDatabase>
#include <QSqlTableModel>

AccessSqlDatabase::AccessSqlDatabase(QWidget* parent) : QWidget(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("cities.db");
    if (!db.open())
    {
        qFatal("unable to open database");
    }

    m_model = new QSqlTableModel(this);
    m_model->setTable("city");
    m_model->setHeaderData(0, Qt::Horizontal, "City");
    m_model->setHeaderData(1, Qt::Horizontal, "Country");


}
