/*!
 *  \file       test_suite.cpp
 *  \brief
 *
 */


#include "test_suite.hpp"

#include <QDebug>

namespace cm
{
    TestSuite::TestSuite(const QString &test_name) : QObject(), m_test_name(test_name)
    {
        qDebug() << "Creating test suite " << test_name;
        testList().push_back(this);
        qDebug() << testList().size() << " test suites recorded" << Qt::endl;
    }

    TestSuite::~TestSuite()
    {
        qDebug() << "Destroying test" << m_test_name << Qt::endl;
    }

    std::vector<TestSuite *>& TestSuite::testList()
    {
        static std::vector<TestSuite *> instance = std::vector<TestSuite *>();
        return instance;
    }

    QString TestSuite::testName() const
    {
        return m_test_name;
    }
}
