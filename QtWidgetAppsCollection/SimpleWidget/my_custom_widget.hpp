/*!
 *  \file       my_custom_widget.hpp
 *  \brief
 *
 */


#pragma once

#include <QWidget>

class QListWidget;
class QLineEdit;
class QPushButton;
class QListWidgetItem;

class MyCustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyCustomWidget(QWidget* parent = nullptr);
private:
    QListWidget* m_widget;
    QLineEdit* m_edit;
    QPushButton* m_button;
private slots:
    void itemClicked(QListWidgetItem* item);
    void updateItem();
};
