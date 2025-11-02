/*!
 *  \file       main.cpp
 *  \brief
 *
 */


#include "test_suite.hpp"

#include <QDebug>
#include <QtTest/QtTest>


int main(int argc, char* argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    qDebug() << "Starting test suite...";
    qDebug() << "Accessing tests from " << cm::TestSuite::testList();
    qDebug() << cm::TestSuite::testList().size() << " test suites detected." << Qt::endl;

    int failed_tests_count = 0;
    for (cm::TestSuite* test_suite_ptr : cm::TestSuite::testList())
    {
        qDebug() << "Executing test " << test_suite_ptr->testName();
        QString filename(test_suite_ptr->testName() + ".xml");
        int result = QTest::qExec(test_suite_ptr,
                                  QStringList() << " " << "-o" << filename << "-junitxml");
        qDebug() << "Test result: " << (result == 0 ? "PASS" : "FAIL") << Qt::endl;
        if (result != 0)
        {
            failed_tests_count++;
        }
    }
    qDebug() << "All test suites completed - " << QString::number(failed_tests_count) << " failures detected." << Qt::endl;

    return failed_tests_count;
}
