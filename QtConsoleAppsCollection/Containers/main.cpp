/*!
 *  \file   main.cpp
 *  \brief  This example adds a list, and list iteration, to the application.
 *
 */


#include <QCoreApplication>
#include <QtCore>

namespace Qt
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    QTextStream cin(stdin, QIODevice::ReadOnly);
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    QString s1("Hello");
    QString s2("Qt");
    QList<QString> list;

    list << s1 << s2;
    // Java and STL-style iteration
    QListIterator<QString> iter(list);

    while (iter.hasNext())
    {
        Qt::cout << iter.next();
        if (iter.hasNext())
        {
            Qt::cout << " ";
        }
    }
    Qt::cout << "!" << Qt::endl;

    return 0;
}
