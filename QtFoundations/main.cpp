/*!
 *  \file       main.cpp
 *  \brief      This file implements the main() portal for current project.
 *
 */


#include <QCoreApplication>

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
#if false
    QCoreApplication a(argc, argv);

    return a.exec();
#else
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif
}
