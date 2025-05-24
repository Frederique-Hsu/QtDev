/*!
 *  \file       date_time_decorator.cpp
 *  \brief
 *
 */


#include "date_time_decorator.hpp"


namespace cm
{
namespace data
{

class DateTimeDecorator::Implementation
{
public:
    Implementation(DateTimeDecorator* parent, const QDateTime& value) : m_parent{parent}, m_value{value}
    {
    }

public:
    DateTimeDecorator* m_parent;
    QDateTime m_value;
};

DateTimeDecorator::DateTimeDecorator(Entity* parent_entity,
                                     const QString& key,
                                     const QString& label,
                                     const QDateTime& value) : DataDecorator(parent_entity, key, label)
{
    m_implementor.reset(new Implementation(this, value));
}

DateTimeDecorator::~DateTimeDecorator()
{
}

const QDateTime& DateTimeDecorator::value() const
{
    return m_implementor->m_value;
}

QJsonValue DateTimeDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(m_implementor->m_value.toString(Qt::ISODate)));
}

void DateTimeDecorator::update(const QJsonObject& json_object)
{
    if (json_object.contains(key()))
    {
        auto value_as_string = json_object.value(key()).toString();
        auto value_as_date = QDateTime::fromString(value_as_string, Qt::ISODate);
        setValue(value_as_date);
    }
    else
    {
        setValue(QDateTime());
    }
}

DateTimeDecorator& DateTimeDecorator::setValue(const QDateTime& value)
{
    if (value != m_implementor->m_value)
    {
        m_implementor->m_value = value;
        emit valueChanged();
    }
    return *this;
}

QString DateTimeDecorator::toIso8601String() const
{
    if (m_implementor->m_value.isNull())
    {
        return QString("");
    }
    else
    {
        return m_implementor->m_value.toString(Qt::ISODate);
    }
}

QString DateTimeDecorator::toPrettyString() const
{
    if (m_implementor->m_value.isNull())
    {
        return "Not set";
    }
    else
    {
        return m_implementor->m_value.toString("ddd d MMM yyy @ HH:mm:ss");
    }
}

QString DateTimeDecorator::toPrettyDateString() const
{
    if (m_implementor->m_value.isNull())
    {
        return "Not set";
    }
    else
    {
        return m_implementor->m_value.toString("d MMM yyyy");
    }
}

QString DateTimeDecorator::toPrettyTimeString() const
{
    if (m_implementor->m_value.isNull())
    {
        return "Not set";
    }
    else
    {
        return m_implementor->m_value.toString("HH:mm:ss");
    }
}

}   // end namespace data
}   // end namespace cm
