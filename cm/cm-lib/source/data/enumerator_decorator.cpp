/*!
 *  \file       enumerator_decorator.cpp
 *  \brief
 *
 */


#include "enumerator_decorator.hpp"


class cm::data::EnumeratorDecorator::Implementation
{
public:
    Implementation(EnumeratorDecorator* parent,
                   int value,
                   const std::map<int, QString>& description_mapper);

public:
    EnumeratorDecorator* m_parent;
    int m_value;
    std::map<int, QString> m_description_mapper;
};


cm::data::EnumeratorDecorator::Implementation::Implementation(cm::data::EnumeratorDecorator* parent,
                                                              int value,
                                                              const std::map<int, QString>& description_mapper)
    : m_parent{parent}, m_value{value}, m_description_mapper{description_mapper}
{
}


cm::data::EnumeratorDecorator::EnumeratorDecorator(Entity* parent_entity,
                                                   const QString& key,
                                                   const QString& label,
                                                   int value,
                                                   const std::map<int, QString>& description_mapper)
    : DataDecorator(parent_entity, key, label)
{
    m_implementor.reset(new Implementation(this, value, description_mapper));
}


cm::data::EnumeratorDecorator::~EnumeratorDecorator()
{
}

cm::data::EnumeratorDecorator& cm::data::EnumeratorDecorator::setValue(int value)
{
    if (value != m_implementor->m_value)
    {
        m_implementor->m_value = value;
        emit valueChanged();
    }
    return *this;
}

int cm::data::EnumeratorDecorator::value() const
{
    return m_implementor->m_value;
}

QString cm::data::EnumeratorDecorator::valueDescription() const
{
    if (m_implementor->m_description_mapper.find(m_implementor->m_value) != m_implementor->m_description_mapper.end())
    {
        return m_implementor->m_description_mapper[m_implementor->m_value];
    }
    else
    {
        return QString();
    }
}

QJsonValue cm::data::EnumeratorDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(m_implementor->m_value));
}

void cm::data::EnumeratorDecorator::update(const QJsonObject& json_object)
{
    if (json_object.contains(key()))
    {
        auto value_from_json = json_object.value(key()).toInt();
        setValue(value_from_json);
    }
    else
    {
        setValue(0);
    }
}
