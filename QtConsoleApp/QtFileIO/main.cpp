/*!
 *  \file       main.cpp
 *  \brief
 *
 */



#include <QtCore>

QTextStream cout(stdout, QIODevice::WriteOnly);

int main(int argc, char* argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    QList<QStringList> data;

    QFile file(":/sample.csv");
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        forever     // loop forever macro
        {
            QString line = stream.readLine();
            if (line.isNull())      // test for null string 'QString()'
            {
                break;
            }
            if (line.isEmpty())     // test for empty string 'QString("")'
            {
                continue;
            }

            QStringList row;
            foreach (const QString& cell, line.split(","))
            {
                row.append(cell.trimmed());
            }
            data.append(row);
        }
    }
    file.close();

    for (QStringList& row : data)
    {
        for (QString& cell : row)
        {
            cout << cell << "\t";
        }
        cout << Qt::endl;
    }

    return 0;
}
