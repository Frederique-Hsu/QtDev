/*!
 *  \file       test_qt_filesystem.c++
 *  \brief
 *
 */


#include <gtest/gtest.h>

#include <QDir>
#include <QStandardPaths>
#include <QDebug>

TEST(UTest4QtFileSystem, CheckQtFileSystem)
{
    auto path = QStandardPaths::StandardLocation();
    qDebug() << path;

    auto home = QStandardPaths::HomeLocation;
    qDebug() << home;

    QFile file(":/my_test_file.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    while (!file.atEnd())
    {
        QByteArray line = file.readLine();
        std::cout << line.data() << std::endl;
    }
    file.close();

    EXPECT_EQ(file.isOpen(), false);
}
