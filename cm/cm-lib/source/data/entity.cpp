/*!
 *  \file       entity.cpp
 *  \brief
 *
 */


#include "entity.hpp"
#include "data_decorator.hpp"

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
    std::map<QString, Entity *> m_child_entities;
    std::map<QString, DataDecorator*> m_data_decorators;
};

Entity::Implementation::Implementation(Entity* parent_entity, const QString& key) : m_parent{parent_entity}, m_key{key}
{
}

Entity::Entity(QObject* parent, const QString& key) : QObject{parent}
{
    m_implementor.reset(new Implementation(this, key));
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
    for (auto& data_decorator_pair : m_implementor->m_data_decorators)
    {
        data_decorator_pair.second->update(json_object);
    }

    for (auto& [key, entity_ptr] : m_implementor->m_child_entities)
    {
        entity_ptr->update(json_object.value(key).toObject());
    }
}

QJsonObject Entity::toJson() const
{
    QJsonObject ret_json_obj;
    for (auto [key, data_decorator_ptr] : m_implementor->m_data_decorators)
    {
        ret_json_obj.insert(key, data_decorator_ptr->jsonValue());
    }

    for (auto [key, entity_ptr] : m_implementor->m_child_entities)
    {
        ret_json_obj.insert(key, entity_ptr->toJson());
    }
    return ret_json_obj;
}

}   // end namespace data
}   // end namespace cm
