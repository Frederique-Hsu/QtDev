/*!
 *  \file       enumerator_decorator.hpp
 *  \brief
 *
 */


#pragma once


#include "data_decorator.hpp"


namespace cm
{
namespace data
{

class CM_LIB_EXPORT EnumeratorDecorator : public DataDecorator
{
    Q_OBJECT

    Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString ui_value_description READ valueDescription NOTIFY valueChanged)
public:
    EnumeratorDecorator(Entity* parent_entity = nullptr,
                        const QString& key = "SomeItemKey",
                        const QString& label = "",
                        int value = 0,
                        const std::map<int, QString>& description_mapper = std::map<int, QString>());
    ~EnumeratorDecorator();

public:
    EnumeratorDecorator& setValue(int value);
    int value() const;
    QString valueDescription() const;

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
