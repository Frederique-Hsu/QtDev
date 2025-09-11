/*!
 *  \file       data_decorator.cpp
 *  \brief
 *
 */


#include "data_decorator.hpp"


class cm::data::DataDecorator::Implementation
{
public:
    Implementation(Entity* parent, const QString& key, const QString& label);

public:
    Entity* m_parent_entity;
    QString m_key;
    QString m_label;
};


cm::data::DataDecorator::Implementation::Implementation(Entity* parent,
                                                        const QString& key,
                                                        const QString& label)
    : m_parent_entity(parent), m_key(key), m_label(label)
{
}


cm::data::DataDecorator::DataDecorator(Entity* parent, const QString& key, const QString& label) : QObject((QObject *)parent)
{
    m_implementor.reset(new Implementation(parent, key, label));
}


cm::data::DataDecorator::~DataDecorator()
{
}

const QString& cm::data::DataDecorator::key() const
{
    return m_implementor->m_key;
}

const QString& cm::data::DataDecorator::label() const
{
    return m_implementor->m_label;
}

cm::data::Entity* cm::data::DataDecorator::parentEntity()
{
    return m_implementor->m_parent_entity;
}
