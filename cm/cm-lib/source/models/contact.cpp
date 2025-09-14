/*!
 *  \file       contact.cpp
 *  \brief
 *
 */


#include "contact.hpp"

namespace cm
{
    namespace models
    {
        std::map<int, QString> Contact::contact_type_mapper{
            {Contact::EContactType::Unknow, ""},
            {Contact::EContactType::Telephone, "Telephone"},
            {Contact::EContactType::Email, "Email"},
            {Contact::EContactType::Fax, "Fax"}
        };

        Contact::Contact(QObject *parent) : cm::data::Entity(parent, "contact"),
                                            contact_type{nullptr},
                                            address{nullptr}
        {
            using namespace cm::data;
            contact_type = static_cast<EnumeratorDecorator*>(addDataItem(
                new EnumeratorDecorator(this, "contact_type", "Contact Type", 0, contact_type_mapper)));
            address = static_cast<StringDecorator*>(addDataItem(
                new StringDecorator(this, "address", "Address")));
        }

        Contact::Contact(QObject *parent, const QJsonObject &json) : Contact(parent)
        {
            update(json);
        }
    }
}
