/*!
 *  \file       entity_collection.hpp
 *  \brief
 *
 */


#pragma once

#include "../cm-lib_global.hpp"

#include <QObject>
#include <QString>
#include <QJsonArray>
#include <QList>
#include <QJsonValue>
#include <QJsonObject>

#include <vector>

namespace cm
{
namespace data
{

/*====================================================================================================================*/
/*!
 *  \ingroup    Prototype
 */
class Entity;

class CM_LIB_EXPORT EntityCollectionObject : public QObject
{
    Q_OBJECT

public:
    EntityCollectionObject(QObject *parent = nullptr) : QObject{parent}
    {
    }
    ~EntityCollectionObject()
    {
    }

signals:
    void collectionChanged();
};

/*================================================================================================*/

#define interface   class

interface EntityCollectionBase : public EntityCollectionObject
{
public:
    EntityCollectionBase(QObject* parent = nullptr, const QString& key = "SomeCollectionKey");
    virtual ~EntityCollectionBase();

public:
    QString getKey() const;

    virtual void clear() = 0;
    virtual void update(const QJsonArray& json) = 0;
    virtual std::vector<Entity*> baseEntities() = 0;

    template<typename T> QList<T*>& derivedEntities();
    template<typename T> T* addEntity(T* entity);

private:
    QString m_key;
};

/*================================================================================================*/

template<typename T>
class EntityCollection : public EntityCollectionBase
{
public:
    EntityCollection(QObject* parent = nullptr, const QString& key = "SomeCollectionKey");
    ~EntityCollection();

public:
    void clear() override;
    void update(const QJsonArray& json_array) override;
    std::vector<Entity*> baseEntities() override;


    QList<T*>& derivedEntities();
    T* addEntity(T* entity);

private:
    QList<T*> m_collection;     // the collection of T* entity
};

/*====================================================================================================================*/
/*!
 *  \ingroup    Template Implementation
 */

template<typename T>
QList<T*>& EntityCollectionBase::derivedEntities()
{
    return dynamic_cast<const EntityCollection<T> *>(this)->derivedEntities();
}

template<typename T>
T* EntityCollectionBase::addEntity(T* entity)
{
    return dynamic_cast<const EntityCollection<T> *>(this)->addEntity(entity);
}

template<typename T>
EntityCollection<T>::EntityCollection(QObject* parent, const QString& key) : EntityCollectionBase(parent, key)
{
}

template<typename T>
EntityCollection<T>::~EntityCollection()
{
}

template<typename T>
void EntityCollection<T>::clear()
{
    for (T* entity : m_collection)
    {
        entity->deleteLater();
    }
    m_collection.clear();
}

template<typename T>
void EntityCollection<T>::update(const QJsonArray& json_array)
{
    clear();

    for (const QJsonValue& json_value : json_array)
    {
        addEntity(new T(this, json_value.toObject()));
    }
}

template<typename T>
std::vector<Entity*> EntityCollection<T>::baseEntities()
{
    std::vector<Entity*> entities;
    for (T* entity : m_collection)
    {
        entities.push_back(entity);
    }
    return entities;
}

template<typename T>
QList<T*>& EntityCollection<T>::derivedEntities()
{
    return m_collection;
}

template<typename T>
T* EntityCollection<T>::addEntity(T* entity)
{
    if (!m_collection.contains(entity))
    {
        m_collection.append(entity);
        EntityCollectionObject::collectionChanged();
    }
    return entity;
}

/*====================================================================================================================*/

}   // end namespace data
}   // end namespace cm
