/*!
 *  \file       main.cpp
 *  \brief      Read a CSV file from local directory and loop over the rows to extract the cells
 *
 */

#include <QtCore>

namespace Qt
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    QTextStream cin(stdin, QIODevice::ReadOnly);
}

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    QList<QStringList> data;
    QFile file(":/sample.csv");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);

        forever {
            QString line = stream.readLine();
            if (line.isNull()) {
                break;
            }
            if (line.isEmpty()) {
                continue;
            }
            QStringList row;
            foreach (const QString &cell, line.split(",")) {
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
            Qt::cout << cell << "\t";
        }
        Qt::cout << Qt::endl;
    }

    return 0;
}
