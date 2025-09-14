/*!
 *  \file       appointment.cpp
 *  \brief
 *
 */


#include "appointment.hpp"


namespace cm
{
    namespace models
    {
        Appointment::Appointment(QObject *parent) : cm::data::Entity(parent, "address"),
                                                    start_at{nullptr},
                                                    end_at{nullptr},
                                                    notes{nullptr}
        {
            using namespace cm::data;
            start_at    = static_cast<DateTimeDecorator*>(addDataItem(new DateTimeDecorator(this, "start_at", "Start")));
            end_at      = static_cast<DateTimeDecorator*>(addDataItem(new DateTimeDecorator(this, "end_at", "End")));
            notes       = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this, "notes", "Notes")));
        }

        Appointment::Appointment(QObject *parent, const QJsonObject &json) : Appointment(parent)
        {
            update(json);
        }
    }
}
