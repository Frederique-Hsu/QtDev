/*!
 *  \file       command_controller.hpp
 *  \brief
 *
 */


#pragma once


#include <QObject>
#include <QtQml/QQmlListProperty>

#include "cm-lib_global.hpp"

#include "framework/command.hpp"


namespace cm
{
    namespace controllers
    {
        class CM_LIB_EXPORT CommandController : public QObject
        {
            Q_OBJECT

            Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommands
                       READ ui_createClientViewContextCommands CONSTANT)
        public:
            explicit CommandController(QObject* parent = nullptr);
            ~CommandController();

        public slots:
            void onCreateClientSaveExecuted();

        private:
            class Implementation;
            QScopedPointer<Implementation> m_implementor;

        public:
            QQmlListProperty<framework::Command> ui_createClientViewContextCommands();
        };
    }
}