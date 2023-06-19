/*!
 *  \file       main.cpp
 *  \brief      Study the Containers of Qt
 *
 */



#include <QtCore>

QTextStream cout(stdout, QIODevice::WriteOnly);

int main(int argc, char* argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv);

    QString s1("Hello");
    QString s2("Qt");

#if 0
    QList<QString> list;
    list << s1 << s2;        // stream into containers.

    /* Java and STL like iterators */
    QListIterator<QString> iter(list);
    while (iter.hasNext())
    {
        cout << iter.next();
        if (iter.hasNext())
        {
            cout << " ";
        }
    }
    cout << "!" << Qt::endl;
#else
    QStringList list;
    list << s1 << s2;
    QString s = list.join(" ") + "!";
    cout << s << Qt::endl;
#endif
    return 0;
}
