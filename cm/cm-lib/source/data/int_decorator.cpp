/*!
 *  \file       int_decorator.cpp
 *  \brief
 *
 */


#include "int_decorator.hpp"


namespace cm
{
namespace data
{

class IntDecorator::Implementation
{
public:
    Implementation(IntDecorator* parent_decorator, int value);

public:
    IntDecorator* m_parent_decorator;
    int m_value;
};

IntDecorator::Implementation::Implementation(IntDecorator* parent_decorator, int value)
    : m_parent_decorator{parent_decorator}, m_value{value}
{
}

IntDecorator::IntDecorator(Entity* parent_entity, const QString& key, const QString& label, int value)
    : DataDecorator(parent_entity, key, label)
{
    m_implementor.reset(new Implementation(this, value));
}

IntDecorator::~IntDecorator()
{
}

int IntDecorator::value() const
{
    return m_implementor->m_value;
}

IntDecorator& IntDecorator::setValue(int value)
{
    if (value != m_implementor->m_value)
    {
        m_implementor->m_value = value;
        emit valueChanged();
    }
    return *this;
}

QJsonValue IntDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(m_implementor->m_value));
}

void IntDecorator::update(const QJsonObject& json_object)
{
    if (json_object.contains(key()))
    {
        auto lvalue = json_object.value(key()).toInt();
        setValue(lvalue);
    }
    else
    {
        setValue(0);
    }
}

}   // end namespace data
}   // end namespace cm
