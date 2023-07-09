/*!
 *  \file       ui_main_window.hpp
 *  \brief      Write the code to design the UI of main window.
 *
 */


#pragma once

#include <QtCore/QVariant>

class QAction;
class QMainWindow;
class QMenuBar;
class QToolBar;
class QStatusBar;
class QMenu;

namespace my_ui_design
{
    class Ui_MainWindow
    {
    public:
        QAction *actOpen, *actNew, *actClose;
        QAction *actCut, *actCopy, *actPaste, *actClear;
        QAction *actFontBold, *actFontItalic, *actFontUnderline, *actToolbarLabel;

        QWidget* centralwidget;
        QMenuBar* menubar;
        QToolBar* toolBar;
        QStatusBar* statusbar;

        QMenu *menuFile, *menuEdit, *menuFormat;
    public:
        void setupUi(QMainWindow* MainWindow);
        void retranslateUi(QMainWindow* MainWindow);
    };

    namespace Ui
    {
        class MainWindow : public Ui_MainWindow
        {
        };
    }
}
