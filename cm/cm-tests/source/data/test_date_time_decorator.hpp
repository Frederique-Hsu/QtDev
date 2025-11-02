/*!
 *  \file       test_date_time_decorator.hpp
 *  \brief
 *
 */


#pragma once

#include "test_suite.hpp"

#include <QDateTime>

namespace cm
{
    namespace data
    {
        class TestDateTimeDecorator : public TestSuite
        {
            Q_OBJECT
        public:
            TestDateTimeDecorator();
            ~TestDateTimeDecorator();

        private slots:
            void constructor_givenNoParameters_setsDefaultProperties();
            void constructor_givenParameters_setsProperties();

            void setValue_givenNewValue_updatesValueAndEmitsSignal();
            void setValue_giveSameValue_takesNoAction();

            void jsonValue_whenDefaultValue_returnsJson();
            void jsonValue_whenValueSet_returnsJson();

            void update_whenPresentInJson_updatesValue();
            void update_whenNotPresentInJson_updatesValueToDefault();

            void toIso8601String_whenDefaultValue_returnsString();
            void toIso8601String_whenValueSet_returnsString();

        private:
            QDateTime testDate;
        };
    }
}
