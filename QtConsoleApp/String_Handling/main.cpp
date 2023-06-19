/*!
 *  \file   main.cpp
 *  \brief  Create a Qt console application
 *
 */



#include <QtCore>       // module or class includes

// text stream is text-codec aware
QTextStream cout(stdout, QIODevice::WriteOnly);


int main(int argc, char* argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);     // to avoid compiler warnings

    QString s1("Pairs");
    QString s2("London");

    // string concatenation
    QString s = s1 + " and " + s2 + "!";
    cout << s << Qt::endl;
    return 0;
}
