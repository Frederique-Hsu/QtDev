/*!
 *  \file       Test_QCounter.cpp
 *  \brief
 *
 */


#include "Test_QCounter.hpp"

#include <iostream>

#include "QCounter.hpp"

void testHowSignalSlotMechanismWorks()
{
    QCounter a, b;
    QObject::connect(&a, &QCounter::valueChanged,
                     &b, &QCounter::setValue);

    std::cout << "Set the value of object a to 12, then:" << std::endl;
    a.setValue(12);
    std::cout << "a.getValue() = " << a.getValue() << std::endl;
    std::cout << "b.getValue() = " << b.getValue() << "\n" << std::endl;

    std::cout << "Set the value of object b to 48, then:" << std::endl;
    b.setValue(48);
    std::cout << "a.getValue() = " << a.getValue() << std::endl;
    std::cout << "b.getValue() = " << b.getValue() << std::endl;
}
