/*!
 *  \file       master_controller.hpp
 *  \brief
 *
 */


#pragma once


#include <QObject>
#include <QString>
#include <QScopedPointer>

#include "cm-lib_global.hpp"

#include "navigation_controller.hpp"
#include "command_controller.hpp"

namespace cm
{
    namespace controllers
    {
        class CM_LIB_EXPORT MasterController : public QObject
        {
            Q_OBJECT
            Q_PROPERTY(QString ui_welcomeMessage READ welcomeMessage CONSTANT)
            Q_PROPERTY(cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT)
            Q_PROPERTY(cm::controllers::CommandController* ui_commandController READ commandController CONSTANT)
        public:
            explicit MasterController(QObject *parent = nullptr);
            ~MasterController();

        public:
            NavigationController* navigationController();
            const QString& welcomeMessage() const;
            CommandController* commandController();

        private:
            class Implementation;
            QScopedPointer<Implementation> m_implementor;;

        signals:
        };
    }
}
