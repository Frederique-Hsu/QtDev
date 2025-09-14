/*!
 *  \file       address.hpp
 *  \brief      represents a supply or billing address
 *
 */


#pragma once


#include "cm-lib_global.hpp"
#include "data/string_decorator.hpp"
#include "data/entity.hpp"

#include <QObject>
#include <QJsonObject>


namespace cm
{
    namespace models
    {

        class CM_LIB_EXPORT Address : public cm::data::Entity
        {
            Q_OBJECT

            Q_PROPERTY(cm::data::StringDecorator* ui_building MEMBER building CONSTANT)
            Q_PROPERTY(cm::data::StringDecorator* ui_street MEMBER street CONSTANT)
            Q_PROPERTY(cm::data::StringDecorator* ui_city MEMBER city CONSTANT)
            Q_PROPERTY(cm::data::StringDecorator* ui_postcode MEMBER postcode CONSTANT)
            Q_PROPERTY(QString ui_fullAddress READ fullAddress CONSTANT)
        public:
            explicit Address(QObject* parent = nullptr);
            Address(QObject* parent, const QJsonObject& json);

        public:
            cm::data::StringDecorator* building;
            cm::data::StringDecorator* street;
            cm::data::StringDecorator* city;
            cm::data::StringDecorator* postcode;

        public:
            QString fullAddress() const;
        };

    }   // end namespace models
}   // end namespace cm
