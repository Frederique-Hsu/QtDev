/*!
 *  \file       main.cpp
 *  \brief      This example demonstrates how you could add 2 constant strings.
 *  \author     Frederique Hsu
 *  \date       Thu.    28 Nov. 2024
 *
 */


/*!
 *  \include    module or class headers
 */
#include <QtCore>


/*!
 *  \brief  text stream is text codec aware
 */
namespace Qt
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    QTextStream cin(stdin, QIODevice::ReadOnly);
}


int main(int argc, char* argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    Qt::cout << "Current C++ standard no. is " << __cplusplus << Qt::endl;
    Qt::cout << "Current program is " << sizeof(void*) * 8 << "-bits.\n" << Qt::endl;

    QString s1("Paris");
    QString s2("London");
    // String concatenation
    QString s = s1 + ", " + s2 + " are international cities.";
    Qt::cout << s << Qt::endl;

    return 0;
}