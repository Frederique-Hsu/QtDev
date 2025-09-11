/*!
 *  \file       master_controller.cpp
 *  \brief
 *
 */


#include "master_controller.hpp"
#include "navigation_controller.hpp"
#include "command_controller.hpp"

namespace cm
{
    namespace controllers
    {
        class MasterController::Implementation
        {
        public:
            explicit Implementation(MasterController* master_controller);
            ~Implementation();

        public:
            MasterController* m_master_controller;
            NavigationController* m_navigation_controller;
            CommandController* m_command_controller;
            QString m_welcomeMessage;
        };

        MasterController::Implementation::Implementation(MasterController* master_controller)
            : m_master_controller{master_controller},
              m_navigation_controller{nullptr},
              m_welcomeMessage("This is MasterController to Major Tom")
        {
            m_navigation_controller = new NavigationController(m_master_controller);
            m_command_controller = new CommandController(m_master_controller);
        }

        MasterController::Implementation::~Implementation()
        {
            if (m_navigation_controller != nullptr)
            {
                delete m_navigation_controller;
            }
            if (m_command_controller != nullptr)
            {
                delete m_command_controller;
            }
        }

        MasterController::MasterController(QObject *parent) : QObject{parent}
        {
            m_implementor.reset(new Implementation(this));
        }

        MasterController::~MasterController()
        {
        }

        NavigationController* MasterController::navigationController()
        {
            return m_implementor->m_navigation_controller;
        }

        const QString& MasterController::welcomeMessage() const
        {
            return m_implementor->m_welcomeMessage;
        }

        CommandController* MasterController::commandController()
        {
            return m_implementor->m_command_controller;
        }
    }
}
