/*!
 *  \file       string_decorator.cpp
 *  \brief
 *
 */


#include "string_decorator.hpp"


namespace cm
{
namespace data
{

class StringDecorator::Implementation
{
public:
    Implementation(StringDecorator* string_decorator, const QString& value);

public:
    StringDecorator* m_string_decorator;
    QString m_value;
};

StringDecorator::Implementation::Implementation(StringDecorator* string_decorator, const QString& value)
    : m_string_decorator(string_decorator), m_value(value)
{
}

/*====================================================================================================================*/

StringDecorator::StringDecorator(Entity* parent_entity,
                                 const QString& key,
                                 const QString& label,
                                 const QString& value) : DataDecorator(parent_entity, key, label)
{
    m_implementor.reset(new Implementation(this, value));
}

StringDecorator::~StringDecorator()
{
}

StringDecorator& StringDecorator::setValue(const QString& value)
{
    if (value != m_implementor->m_value)
    {
        /*!
         *  \todo   validation here if required...
         */
        m_implementor->m_value = value;
        emit valueChanged();
    }
    return *this;
}

const QString& StringDecorator::value() const
{
    return m_implementor->m_value;
}

QJsonValue StringDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(m_implementor->m_value));
}

void StringDecorator::update(const QJsonObject& json_object)
{
    if (json_object.contains(key()))
    {
        setValue(json_object.value(key()).toString());
    }
    else
    {
        setValue("");
    }
}

}   // end namespace data
}   // end namespace cm
