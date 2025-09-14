/*!
 *  \file       appointment.hpp
 *  \brief      represents an appointment with a client
 *
 */


#pragma once

#include "data/entity.hpp"
#include "data/date_time_decorator.hpp"
#include "data/string_decorator.hpp"

namespace cm
{
    namespace models
    {
        class CM_LIB_EXPORT Appointment : public cm::data::Entity
        {
            Q_OBJECT

            Q_PROPERTY(cm::data::DateTimeDecorator *ui_start_at MEMBER start_at CONSTANT)
            Q_PROPERTY(cm::data::DateTimeDecorator *ui_end_at MEMBER end_at CONSTANT)
            Q_PROPERTY(cm::data::StringDecorator *ui_notes MEMBER notes CONSTANT)

        public:
            explicit Appointment(QObject *parent = nullptr);
            Appointment(QObject *parent, const QJsonObject &json);

        public:
            cm::data::DateTimeDecorator *start_at;
            cm::data::DateTimeDecorator *end_at;
            cm::data::StringDecorator *notes;
        };
    }
}
