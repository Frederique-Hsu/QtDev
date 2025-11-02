/*!
 *  \file       test_date_time_decorator.cpp
 *  \brief
 *
 */


#include "test_date_time_decorator.hpp"

#include "data/date_time_decorator.hpp"
#include "data/entity.hpp"

#include <QtTest/QtTest>

namespace cm
{
    namespace data
    {
        static TestDateTimeDecorator instance;
    }
}

cm::data::TestDateTimeDecorator::TestDateTimeDecorator()
    : cm::TestSuite("TestDateTimeDecorator"), testDate{QDate(2017, 9, 24), QTime(20, 45, 10)}
{
}

cm::data::TestDateTimeDecorator::~TestDateTimeDecorator()
{
    // qDebug() << "Destruct TestDateTimeDecorator object" << Qt::endl;
}

void cm::data::TestDateTimeDecorator::constructor_givenNoParameters_setsDefaultProperties()
{
    DateTimeDecorator decorator;

    QCOMPARE(decorator.parentEntity(), nullptr);
    QCOMPARE(decorator.key(), QString("SomeItemKey"));
    QCOMPARE(decorator.label(), QString(""));
    QCOMPARE(decorator.value(), QDateTime());
}


void cm::data::TestDateTimeDecorator::constructor_givenParameters_setsProperties()
{
    cm::data::Entity parentEntity;
    DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", testDate);

    QCOMPARE(decorator.parentEntity(), &parentEntity);
    QCOMPARE(decorator.key(), QString("Test Key"));
    QCOMPARE(decorator.label(), QString("Test Label"));
    QCOMPARE(decorator.value(), testDate);
}

void cm::data::TestDateTimeDecorator::setValue_givenNewValue_updatesValueAndEmitsSignal()
{
    DateTimeDecorator decorator;
    QSignalSpy valueChangedSpy(&decorator, &DateTimeDecorator::valueChanged);

    QCOMPARE(decorator.value(), QDateTime());
    decorator.setValue(testDate);
    QCOMPARE(decorator.value(), testDate);
    QCOMPARE(valueChangedSpy.count(), 1);
}

void cm::data::TestDateTimeDecorator::setValue_giveSameValue_takesNoAction()
{
    QSKIP(__FUNCTION__, __FILE__, __LINENO__);

    Entity parentEntity;
    DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", testDate);

    bool isValueChanged = false;
    QObject::connect(&decorator,
                     &DateTimeDecorator::valueChanged,
                     [&isValueChanged]()
                     {
                         isValueChanged = true;
                     });

    QCOMPARE(decorator.value(), testDate);

    decorator.setValue(testDate);
    QCOMPARE(decorator.value(), testDate);
    QCOMPARE(isValueChanged, false);
}

void cm::data::TestDateTimeDecorator::jsonValue_whenDefaultValue_returnsJson()
{
    DateTimeDecorator decorator;
    QCOMPARE(decorator.jsonValue(), QJsonValue(QDateTime().toString(Qt::ISODate)));
}

void cm::data::TestDateTimeDecorator::jsonValue_whenValueSet_returnsJson()
{
    DateTimeDecorator decorator;
    decorator.setValue(testDate);
    QCOMPARE(decorator.jsonValue(), QJsonValue(testDate.toString(Qt::ISODate)));
}

void cm::data::TestDateTimeDecorator::update_whenPresentInJson_updatesValue()
{
    Entity parentEntity;
    DateTimeDecorator decorator(&parentEntity, "Test Key", "Test label", testDate);
    QSignalSpy valueChangedSpy(&decorator, &DateTimeDecorator::valueChanged);

    QCOMPARE(decorator.value(), testDate);

    QJsonObject jsonObj;
    jsonObj.insert("Key 1", "Value 1");
    jsonObj.insert("Test Key",
                   QDateTime(QDate(2016, 4, 18), QTime(10, 37, 14)).toString(Qt::ISODate));
    jsonObj.insert("Key 3", 3);

    decorator.update(jsonObj);
    QCOMPARE(decorator.value(), QDateTime(QDate(2016, 4, 18), QTime(10, 37, 14)));
    QCOMPARE(valueChangedSpy.count(), 1);
}

void cm::data::TestDateTimeDecorator::update_whenNotPresentInJson_updatesValueToDefault()
{
    Entity parentEntity;
    DateTimeDecorator decorator(&parentEntity, "Test Key", "Test Label", testDate);

    bool isValueChanged = false;
    QObject::connect(&decorator,
                     &DateTimeDecorator::valueChanged,
                     [&isValueChanged]()
                     {
                         isValueChanged = true;
                     });
    QCOMPARE(decorator.value(), testDate);

    QJsonObject jsonObj;
    jsonObj.insert("Key 1", "Value 1");
    jsonObj.insert("Key 2", QDateTime(QDate(2016, 4, 18), QTime(10, 37, 14)).toString(Qt::ISODate));
    jsonObj.insert("Key 3", 3);

    decorator.update(jsonObj);
    QCOMPARE(decorator.value(), QDateTime());
    QCOMPARE(isValueChanged, true);
}

void cm::data::TestDateTimeDecorator::toIso8601String_whenDefaultValue_returnsString()
{
    DateTimeDecorator decorator;
    QCOMPARE(decorator.toIso8601String(), QString(""));
}

void cm::data::TestDateTimeDecorator::toIso8601String_whenValueSet_returnsString()
{
    DateTimeDecorator decorator;
    decorator.setValue(testDate);

    QCOMPARE(decorator.toIso8601String(), QString("2017-09-24T20:45:10"));
}


