/*!
 *  \file       client.hpp
 *  \brief
 *
 */


#pragma once


#include "data/entity.hpp"
#include "data/string_decorator.hpp"
#include "data/entity_collection.hpp"

#include "address.hpp"
#include "appointment.hpp"
#include "contact.hpp"

#include <QtQml/QQmlListProperty>

namespace cm
{
    namespace models
    {
        class CM_LIB_EXPORT Client : public cm::data::Entity
        {
            Q_OBJECT

            Q_PROPERTY(cm::data::StringDecorator *ui_reference MEMBER reference CONSTANT)
            Q_PROPERTY(cm::data::StringDecorator *ui_name MEMBER name CONSTANT)
            Q_PROPERTY(cm::models::Address *ui_supply_address MEMBER supply_address CONSTANT)
            Q_PROPERTY(cm::models::Address *ui_billing_address MEMBER billing_address CONSTANT)
            Q_PROPERTY(QQmlListProperty<cm::models::Appointment> ui_appointments
                       READ ui_appointments
                       NOTIFY appointmentsChanged)
            Q_PROPERTY(QQmlListProperty<cm::models::Contact> ui_contacts
                       READ ui_contacts
                       NOTIFY contactsChanged)

        public:
            explicit Client(QObject *parent = nullptr);
            Client(QObject *parent, const QJsonObject &json);

        public:
            cm::data::StringDecorator *reference{nullptr};
            cm::data::StringDecorator *name{nullptr};
            Address *supply_address{nullptr};
            Address *billing_address{nullptr};
            cm::data::EntityCollection<Appointment> *appointments{nullptr};
            cm::data::EntityCollection<Contact> *contacts{nullptr};

        public:
            QQmlListProperty<Appointment> ui_appointments();
            QQmlListProperty<Contact> ui_contacts();

        signals:
            void appointmentsChanged();
            void contactsChanged();
        };
    }
}
