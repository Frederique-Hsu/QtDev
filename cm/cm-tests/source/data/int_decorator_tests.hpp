/*!
 *  \file       int_decorator_tests.hpp
 *  \brief
 *
 */


#pragma once


#include "test_suite.hpp"


namespace cm
{
    namespace data
    {
        class IntDecoratorTests : public TestSuite
        {
            Q_OBJECT
        public:
            IntDecoratorTests();

        private slots:
            void constructor_givenNoParameters_setsDefaultProperties();
            void constructor_givenParameters_setProperties();
            void setValue_givenNewValue_updatesValueAndEmitsSignal();
            void setValue_givenSameValue_takesNoAction();
            void jsonValue_whenDefaultValue_returnsJson();
            void jsonValue_whenValueSet_returnsJson();
            void update_whenPresentInJson_updatesValue();
            void update_whenNotPresentInJson_updatesValueToDefault();
        };
    }
}
