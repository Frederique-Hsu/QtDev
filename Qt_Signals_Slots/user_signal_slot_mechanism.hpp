/*!
 *  \file       user_signal_slot_mechanism.hpp
 *  \brief      define and simulate the signal-slot mechanism
 *
 */


#pragma once

#include <functional>

typedef std::function<void(int)> Callback;

class Signal
{
public:
    void connect(const Callback& callback);
    void emit(int value);
private:
    std::vector<Callback> m_callbacks;
};

void SlotFn(int value);

void DemoUserSignalSlotMechanism();
