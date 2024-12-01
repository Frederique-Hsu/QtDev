/*!
 *  \file       main.cpp
 *  \brief      This project parses the JSON-format file.
 *
 */



#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    QFile contact_json_file(":/contact.json");
    if (contact_json_file.open(QIODevice::ReadOnly | QIODevice::Text) == false)
    {
        qDebug() << "Failed to open the JSON file. Error: " << contact_json_file.errorString();
        contact_json_file.close();
    }
    QByteArray content_byte_array = contact_json_file.readAll();
    contact_json_file.close();

#if false
    QString json_str(content_byte_array.data());
    qDebug() << json_str;
#endif

    QJsonDocument json_doc = QJsonDocument::fromJson(content_byte_array);
    QJsonObject obj = json_doc.object();
    QVariantMap map = obj.toVariantMap();
    qDebug() << map["firstName"].toString();

    // QJsonValue value = obj.value(QString("phoneNumbers"));
    // QJsonArray array = value.toArray();
    // for (int index = 0; index < array.size(); ++index)
    // {
    //     QJsonValue item_value = array.at(index);
    //     auto item_array = item_value.toArray();
    //     for (int j = 0; j < item_array.size(); ++j)
    //     {
    //         qDebug() << item_array.at(j).toString();
    //     }
    // }

    return 0;
}
