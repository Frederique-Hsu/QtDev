/*!
 *  \file       entity.hpp
 *  \brief
 *
 */


#pragma once


#include "cm-lib_global.hpp"

#include <QObject>
#include <QJsonObject>


namespace cm
{
namespace data
{

class DataDecorator;

class CM_LIB_EXPORT Entity : public QObject
{
    Q_OBJECT
public:
    Entity(QObject* parent = nullptr, const QString& key = "SomeItemKey");
    Entity(QObject* parent, const QString& key, const QJsonObject& json_object);
    virtual ~Entity();

protected:
    class Implementation;
    QScopedPointer<Implementation> m_implementor;

public:
    const QString& key() const;
    void update(const QJsonObject& json_object);
    QJsonObject toJson() const;

signals:
    void childEntitiesChanged();
    void dataDecoratorsChanged();

protected:
    Entity* addChild(Entity* entity, const QString& key);
    DataDecorator* addDataItem(DataDecorator* data_decorator);
};

}   // end namespace data
}   // end namespace cm
