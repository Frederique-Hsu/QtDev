/*!
 *  \file       command.hpp
 *  \brief
 *
 */


#pragma once


#include <functional>

#include <QObject>

#include "cm-lib_global.hpp"


namespace cm
{
    namespace framework
    {
        class CM_LIB_EXPORT Command : public QObject
        {
            Q_OBJECT

            Q_PROPERTY(QString ui_iconCharacter READ iconCharacter CONSTANT)
            Q_PROPERTY(QString ui_description READ description CONSTANT)
            Q_PROPERTY(bool ui_canExecute READ canExecute NOTIFY canExecuteChanged)
        public:
            explicit Command(QObject* parent = nullptr,
                             const QString& icon_character = "",
                             const QString& description = "",
                             std::function<bool()> can_exec = []() { return true; });
            ~Command();
        public:
            const QString& iconCharacter() const;
            const QString& description() const;
            bool canExecute() const;

        signals:
            void canExecuteChanged();
            void executed();

        private:
            class Implementation;
            QScopedPointer<Implementation> m_implementor;
        };
    }
}