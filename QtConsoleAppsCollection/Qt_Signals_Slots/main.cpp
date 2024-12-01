/*!
 *  \file       main.cpp
 *  \brief      This file implements the main() portal for current project.
 *
 */


#include "Test_QCounter.hpp"
#include "user_signal_slot_mechanism.hpp"
#include "user_moc.hpp"

#include <QApplication>
#include <QMetaObject>
#include <QObject>

#include <iostream>

int main(int argc, char* argv[])
{
    for (int index = 0; index < argc; ++index)
    {
        std::cout << "argv[" << index << "] = " << argv[index] << std::endl;
    }

    QApplication app(argc, argv);

    testHowSignalSlotMechanismWorks();
    DemoUserSignalSlotMechanism();
    DemoUserMOC();

    return app.exec();
}
