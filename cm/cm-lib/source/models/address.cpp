/*!
 *  \file       address.cpp
 *  \brief
 *
 */


#include "address.hpp"


cm::models::Address::Address(QObject* parent) : cm::data::Entity(parent, "address"),
                                                building{nullptr},
                                                street{nullptr},
                                                city{nullptr},
                                                postcode{nullptr}
{
    using namespace cm::data;

    building    = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this, "building", "Building")));
    street      = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this, "street", "Street")));
    city        = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this, "city", "City")));
    postcode    = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this, "postcode", "Post Code")));
}

QString cm::models::Address::fullAddress() const
{
    return building->value() + " " + street->value() + "\n" + city->value() + "\n" + postcode->value();
}

/*!
 *  \brief  this overloaded constructor can be used to construct an address-object from a QJsonObject.
 */
cm::models::Address::Address(QObject* parent, const QJsonObject& json) : cm::models::Address(parent)
{
    update(json);
}
