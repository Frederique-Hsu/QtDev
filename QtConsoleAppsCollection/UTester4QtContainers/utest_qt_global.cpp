/*!
 *  \file       utest_qt_global.cpp
 *  \brief
 *
 */


#include <gtest/gtest.h>
#include <QtGlobal>
#include <QFloat16>

TEST(UTester4QtGlobal, CheckQtGlobalFunctions)
{
    double inf = qInf();
    std::cout << "the infinity is " << inf << std::endl;
    EXPECT_EQ(qIsInf(inf), true);
    EXPECT_EQ(qIsFinite(inf), false);

    bool result = qFuzzyIsNull(0.00010);
    std::cout << "the result is " << result << std::endl;
    EXPECT_EQ(result, false);

    EXPECT_EQ(qRound(3.1415926), 3);
}

TEST(UTester4QDataType, CheckQtDataType)
{
    EXPECT_EQ(sizeof(qint8), 1);
    EXPECT_EQ(sizeof(qint16), 2);
    EXPECT_EQ(sizeof(qint32), 4);
    EXPECT_EQ(sizeof(qint64), 8);

    EXPECT_EQ(sizeof(qreal), 8);
    EXPECT_EQ(sizeof(qfloat16), 2);
}
