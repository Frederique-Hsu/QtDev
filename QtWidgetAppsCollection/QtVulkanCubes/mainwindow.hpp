/*!
 *  \file       mainwindow.hpp
 *  \brief
 *
 */


#pragma once


#include <QWidget>


class VulkanWindow;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(VulkanWindow* vulkan_window);
    ~MainWindow();
private:

};
