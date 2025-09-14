/*!
 *  \file       client.cpp
 *  \brief
 *
 */


#include "client.hpp"


namespace cm
{
    namespace models
    {
        Client::Client(QObject *parent) : cm::data::Entity(parent, "client")
        {
            using namespace cm::data;

            reference = static_cast<StringDecorator*>(addDataItem(
                new StringDecorator(this, "reference", "Client Ref")));

            name = static_cast<StringDecorator*>(addDataItem(
                new StringDecorator(this, "name", "Name")));

            supply_address = static_cast<Address*>(addChild(new Address(this), "supply_address"));
            billing_address = static_cast<Address*>(addChild(new Address(this), "billing_address"));

            appointments = static_cast<EntityCollection<Appointment>*>(addChildCollection(
                new EntityCollection<Appointment>(this, "appointments")));

            contacts = static_cast<EntityCollection<Contact>*>(addChildCollection(
                new EntityCollection<Contact>(this, "contacts")));
        }

        Client::Client(QObject *parent, const QJsonObject &json) : Client(parent)
        {
            update(json);
        }

        QQmlListProperty<Appointment> Client::ui_appointments()
        {
            return QQmlListProperty<Appointment>(this, &(appointments->derivedEntities()));
        }

        QQmlListProperty<Contact> Client::ui_contacts()
        {
            return QQmlListProperty<Contact>(this, &(contacts->derivedEntities()));
        }
    }
}
