/*!
 *  \file       entity.cpp
 *  \brief
 *
 */


#include "entity.hpp"
#include "data_decorator.hpp"
#include "entity_collection.hpp"

#include <map>


namespace cm
{
namespace data
{

class Entity::Implementation
{
public:
    Implementation(Entity* parent_entity, const QString& key);

public:
    Entity* m_parent;
    QString m_key;
    std::map<QString, Entity*> m_child_entities;   // representing individual children
    std::map<QString, DataDecorator*> m_data_decorators;    // representing the properties of model

    std::map<QString, EntityCollectionBase*> m_child_collections;
};

Entity::Implementation::Implementation(Entity* parent_entity, const QString& key)
    : m_parent{parent_entity}, m_key{key}
{
}

Entity::Entity(QObject* parent, const QString& key) : QObject{parent}
{
    m_implementor.reset(new Implementation(this, key));
}

Entity::Entity(QObject* parent, const QString& key, const QJsonObject& json_object) : Entity(parent, key)
{
    update(json_object);
}

Entity::~Entity()
{
}

const QString& Entity::key() const
{
    return m_implementor->m_key;
}

Entity* Entity::addChild(Entity* entity, const QString& key)
{
    if (m_implementor->m_child_entities.find(key) == m_implementor->m_child_entities.end())
    {
        m_implementor->m_child_entities[key] = entity;
        emit childEntitiesChanged();
    }
    return entity;
}

DataDecorator* Entity::addDataItem(DataDecorator* data_decorator)
{
    if (m_implementor->m_data_decorators.find(data_decorator->key()) == m_implementor->m_data_decorators.end())
    {
        m_implementor->m_data_decorators.insert({data_decorator->key(), data_decorator});
        emit dataDecoratorsChanged();
    }
    return data_decorator;
}

void Entity::update(const QJsonObject& json_object)
{
    // update data decorators
    for (auto& data_decorator_pair : m_implementor->m_data_decorators)
    {
        data_decorator_pair.second->update(json_object);
    }
    // Update child entities
    for (auto& [key, entity_ptr] : m_implementor->m_child_entities)
    {
        // recursively call Entity::update() on each of child entities
        entity_ptr->update(json_object.value(key).toObject());
    }
    // Update child collections
    for (std::pair<QString, EntityCollectionBase*> child_collection_pair : m_implementor->m_child_collections)
    {
        child_collection_pair.second->update(json_object.value(child_collection_pair.first).toArray());
    }
}

QJsonObject Entity::toJson() const
{
    QJsonObject ret_json_obj;

    // Add data decorators
    for (auto& [key, data_decorator_ptr] : m_implementor->m_data_decorators)
    {
        ret_json_obj.insert(key, data_decorator_ptr->jsonValue());
    }
    // Add child entities
    for (auto& [key, entity_ptr] : m_implementor->m_child_entities)
    {
        // recursively call Entity::toJson() on each of the children,
        // and this cascades down the hierarchy tree
        ret_json_obj.insert(key, entity_ptr->toJson());
    }
    // Add child collections
    for (auto& [key, child_collection_ptr] : m_implementor->m_child_collections)
    {
        QJsonArray entity_array;
        for (Entity* entity_ptr : child_collection_ptr->baseEntities())
        {
            entity_array.append(entity_ptr->toJson());
        }
        ret_json_obj.insert(key, entity_array);
    }
    return ret_json_obj;
}

EntityCollectionBase* Entity::addChildCollection(EntityCollectionBase* entity_collection)
{
    if (m_implementor->m_child_collections.find(entity_collection->getKey()) == std::end(m_implementor->m_child_collections))
    {
        m_implementor->m_child_collections[entity_collection->getKey()] = entity_collection;

        emit childCollectionsChanged(entity_collection->getKey());
    }
    return entity_collection;
}

}   // end namespace data
}   // end namespace cm
