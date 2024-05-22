/*!
 *  \file       user_signal_slot_mechanism.cpp
 *  \brief
 *
 */


#include "user_signal_slot_mechanism.hpp"

#include <iostream>

void Signal::connect(const Callback& callback)
{
    m_callbacks.push_back(callback);
}

void Signal::emit(int value)
{
    for (const auto& callback : m_callbacks)
    {
        callback(value);
    }
}

void SlotFn(int value)
{
    std::cout << "Received the signal with value: " << value << std::endl;
}

void DemoUserSignalSlotMechanism()
{
    Signal signal;
    signal.connect(SlotFn);

    signal.emit(42);
}
