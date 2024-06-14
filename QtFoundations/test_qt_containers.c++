/*!
 *  \file       test_qt_container.c++
 *  \brief
 *
 */


#include <gtest/gtest.h>

#include <cstring>
#include <cwchar>

#include <QMap>
#include <QStringList>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QChar>

TEST(UTest4QMap, CheckQMapContainer)
{
    QMap<QString, int> map;
    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;

    EXPECT_EQ(map.size(), 3);

    QList<int> value_list = map.values();
    for (auto& value : value_list)
    {
        std::cout << value << std::endl;
    }

    QStringList keys = map.keys();
    foreach (QString key, keys)
    {
        std::cout << key.toStdString() << std::endl;
    }

    auto obj = map.remove(QString("four"));
    qDebug() << obj;

    EXPECT_EQ(map.size(), 3);
}

TEST(UTest4QList, CheckQListContainer)
{
    QList<QString> months;
    months.append("January");
    months.append("February");
    months.append("March");
    months.append("April");
    months.append("May");
    months.append("June");
    months.append("July");
    months.append("August");
    months.append("September");
    months.append("October");
    months.append("November");
    months.append("December");

    EXPECT_EQ(months.size(), 12);

    for (QList<QString>::ConstIterator iter = months.begin(); iter != months.end(); ++iter)
    {
        qDebug() << *iter;
    }
}

TEST(UTest4QtCopyOnWrite, CheckQtCopyOnWrite)
{
    /*!
     *  \remark     Qt Copy-on-Write mechanism
     *
     *  \details    See the below objects, \a oneFish and \a twoFish point to the same data under
     *              the hood, and only when you begin to change the value of \a twoFish through
     *              its method, does it get its own memory buffer.
     *
     *  \note       This is an important way in which these classes differ from the STL classes
     *              and are key to Qt's better memory performance on low-memory platforms such
     *              as mobile devices.
     */
    QString oneFish = "red fish";
    QString twoFish = oneFish;

    EXPECT_EQ(oneFish.data_ptr().isSharedWith(twoFish.data_ptr()), true);

    twoFish[4] = 'F';
    EXPECT_NE(oneFish, twoFish) << "oneFish = " << oneFish.toStdString()
                                << ", twoFish = " << twoFish.toStdString();

    EXPECT_EQ(oneFish.data_ptr().isSharedWith(twoFish.data_ptr()), false);
}

TEST(UTest4QByteArray, CheckQByteArray)
{
    char english_love[] = "I love you";
    wchar_t chinese_love[] = L"我爱你";


    EXPECT_EQ(sizeof(wchar_t), 4);
    EXPECT_EQ(sizeof(char), 1);

    std::cout << "strlen(english_love) = " << std::strlen(english_love) << std::endl;
    std::cout << "wcslen(chinese_love) = " << std::wcslen(chinese_love) << std::endl;
    std::cout << "sizeof(english_love) = " << sizeof(english_love) << std::endl;
    std::cout << "sizeof(chinese_love) = " << sizeof(chinese_love) << std::endl;
    EXPECT_EQ(sizeof(english_love)/sizeof(english_love[0]), 11);
    EXPECT_EQ(sizeof(chinese_love)/sizeof(chinese_love[0]), 4);

    std::cout << "english_love = " << english_love << std::endl;
    std::wcout << "chinese_love = " << chinese_love << std::endl;

    QByteArray english_love_bytes(english_love);
    EXPECT_EQ(english_love_bytes.length(), 10);
}
