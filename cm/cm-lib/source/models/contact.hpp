/*!
 *  \file       contact.hpp
 *  \brief      represents a method of contacting a client
 *
 */


#pragma once

#include "data/entity.hpp"
#include "data/enumerator_decorator.hpp"
#include "data/string_decorator.hpp"

namespace cm
{
    namespace models
    {
        class CM_LIB_EXPORT Contact : public cm::data::Entity
        {
            Q_OBJECT

            Q_PROPERTY(cm::data::EnumeratorDecorator *ui_contact_type MEMBER contact_type CONSTANT)
            Q_PROPERTY(cm::data::StringDecorator *ui_address MEMBER address CONSTANT)

        public:
            enum EContactType
            {
                Unknow = 0,
                Telephone,
                Email,
                Fax
            };

        public:
            explicit Contact(QObject *parent = nullptr);
            Contact(QObject *parent, const QJsonObject &json);

        public:
            cm::data::EnumeratorDecorator *contact_type;
            cm::data::StringDecorator *address;

            static std::map<int, QString> contact_type_mapper;
        };
    }
}
