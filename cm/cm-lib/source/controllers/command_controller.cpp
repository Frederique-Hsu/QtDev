/*!
 *  \file       command_controller.cpp
 *  \brief
 *
 */


#include "command_controller.hpp"

#include <QDebug>
#include <QList>


namespace cm
{
    namespace controllers
    {
        class CommandController::Implementation
        {
        public:
            Implementation(CommandController* cmd_ctrler);
            ~Implementation();

        public:
            CommandController* m_command_controller;
            QList<framework::Command*> m_create_client_view_context_commands;
        };

        /*================================================================================================*/

        CommandController::Implementation::Implementation(CommandController* cmd_ctrler)
            : m_command_controller{cmd_ctrler}
        {
            using namespace cm::framework;

            Command* create_client_save_command = new Command(m_command_controller,
                                                              QChar(0xF0C7),    // save icon
                                                              QString("Save")); // save label
            QObject::connect(create_client_save_command,
                             &Command::executed,
                             m_command_controller,
                             &CommandController::onCreateClientSaveExecuted);

            m_create_client_view_context_commands.append(create_client_save_command);
        }

        CommandController::Implementation::~Implementation()
        {
            for (framework::Command* command : m_create_client_view_context_commands)
            {
                if (command != nullptr)
                {
                    delete command;
                }
            }
        }

        /*================================================================================================*/

        CommandController::CommandController(QObject* parent) : QObject(parent)
        {
            m_implementor.reset(new Implementation(this));
        }

        CommandController::~CommandController()
        {
        }

        QQmlListProperty<framework::Command> CommandController::ui_createClientViewContextCommands()
        {
            return QQmlListProperty<cm::framework::Command>(
                this, &(m_implementor->m_create_client_view_context_commands));
        }

        void CommandController::onCreateClientSaveExecuted()
        {
            qDebug() << "You executed the Save command!" << Qt::endl;
        }

    }   // namespace controllers
}   // namespace cm
