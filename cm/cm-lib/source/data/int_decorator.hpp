/*!
 *  \file       int_decorator.hpp
 *  \brief
 *
 */


#pragma once


#include "data_decorator.hpp"

namespace cm
{
namespace data
{

class CM_LIB_EXPORT IntDecorator : public DataDecorator
{
    Q_OBJECT

    Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)
public:
    IntDecorator(Entity* parent_entity = nullptr,
                 const QString& key = "SomeItemKey",
                 const QString& label = "",
                 int value = 0);
    ~IntDecorator();

public:
    IntDecorator& setValue(int value);
    int value() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject& json_object) override;

signals:
    void valueChanged();

private:
    class Implementation;
    QScopedPointer<Implementation> m_implementor;
};

}   // end namespace data
}   // end namespace cm
