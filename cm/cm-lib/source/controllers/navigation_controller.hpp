/*!
 *  \file       navigation_controller.hpp
 *  \brief
 *
 */


#pragma once

#include <QObject>

#include "cm-lib_global.hpp"
#include "models/client.hpp"

namespace cm
{
    namespace controllers
    {
        class CM_LIB_EXPORT NavigationController : public QObject
        {
            Q_OBJECT
        public:
            explicit NavigationController(QObject* parent = nullptr) : QObject(parent)
            {
            }

        signals:
            void goCreateClientView();
            void goDashboardView();
            void goEditClientView(cm::models::Client* client);
            void goFindClientView();
        };
    }
}