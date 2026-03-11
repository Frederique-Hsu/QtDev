/*!
 *  \file       UI_Dialog.hpp
 *  \brief
 *
 */


#pragma once

class QDialog;
class QPushButton;
class QCheckBox;
class QLineEdit;
class QPlainTextEdit;

namespace Ui
{
    class Dialog
    {
    public:
        QPushButton *btn_host_name_ip,
                    *btn_all_addresses,
                    *btn_all_interfaces,
                    *btn_query_dns_ip,
                    *btn_clean_text;
        QCheckBox *chkbox_only_ipv4;
        QLineEdit *edit_website_url;
        QPlainTextEdit *plain_text;
    public:
        void setupUI(QDialog *dialog);
    };
}
