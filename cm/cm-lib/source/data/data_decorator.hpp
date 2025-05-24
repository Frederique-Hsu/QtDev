/*!
 *  \file       data_decorator.hpp
 *  \brief      Base class to house the features shared across all of our data items.
 *
 */


#pragma once


#include "../cm-lib_global.hpp"

#include <QObject>
#include <QJsonValue>
#include <QJsonObject>


namespace cm
{
namespace data
{

class Entity;

class CM_LIB_EXPORT DataDecorator : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString ui_label READ label CONSTANT)
public:
    DataDecorator(Entity* parent = nullptr,
                  const QString& key = "SomeItemKey",
                  const QString& label = "");
    virtual ~DataDecorator();

public:
    const QString& key() const;
    const QString& label() const;
    Entity* parentEntity();

    virtual QJsonValue jsonValue() const = 0;
    virtual void update(const QJsonObject& json_object) = 0;

private:
    class Implementation;
    QScopedPointer<Implementation> m_implementor;
};

}   // end namespace data
}   // end namespace cm
