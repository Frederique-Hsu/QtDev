/*!
 *  \file       main.cpp
 *  \brief      Create a user executable application "MathFunctionsTest" to link against user
 *              library "libMathFunctions.a" to verify.
 */


#include <QCoreApplication>

#include "mathfunctions.h"

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Current C++ standard no. is " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << std::endl;

    for (int index = 0; index < argc; ++index)
    {
        std::cout << "argv[" << index << "] = " << argv[index] << std::endl;
    }
    std::cout << std::endl;

    QCoreApplication a(argc, argv);

    // qDebug("6! = %lu", MathFunctions::factorial(6));

    int values[] = {6, 7, 8};
    for (unsigned int i = 0; i < sizeof(values)/sizeof(values[0]); ++i)
    {
        qDebug() << values[i] << " != " << MathFunctions::factorial(values[i]);
    }

    return a.exec();
}
