/*!
 *  \file       test_suite.hpp
 *  \brief
 *
 */


#pragma once

#include <QObject>
#include <QString>


namespace cm
{
    class TestSuite : public QObject
    {
        Q_OBJECT
    public:
        explicit TestSuite(const QString &test_name = "");
        virtual ~TestSuite();

    private:
        QString m_test_name;

    public:
        static std::vector<TestSuite *>& testList();
        QString testName() const;
    };
}
