/*!
 *  \file       date_time_decorator.hpp
 *  \brief
 *
 */


#pragma once


#include "data_decorator.hpp"

#include <QDateTime>

namespace cm
{
namespace data
{

class CM_LIB_EXPORT DateTimeDecorator : public DataDecorator
{
    Q_OBJECT

    Q_PROPERTY(QString ui_iso8601String READ toIso8601String NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyDateString READ toPrettyDateString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyTimeString READ toPrettyTimeString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyString READ toPrettyString NOTIFY valueChanged)
    Q_PROPERTY(QDateTime ui_value READ value WRITE setValue NOTIFY valueChanged)
public:
    DateTimeDecorator(Entity* parent_entity,
                      const QString& key = "SomeItemKey",
                      const QString& label = "",
                      const QDateTime& value = QDateTime());
    ~DateTimeDecorator();

public:
    const QDateTime& value() const;
    DateTimeDecorator& setValue(const QDateTime& value);

    QString toIso8601String() const;
    QString toPrettyDateString() const;
    QString toPrettyTimeString() const;
    QString toPrettyString() const;

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
