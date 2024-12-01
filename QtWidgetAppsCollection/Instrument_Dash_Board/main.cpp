/*!
 *  \file       main.cpp
 *  \brief
 *
 */

#include "instrument_dash_board.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    InstrumentDashBoard dash_board;
    dash_board.show();

    return app.exec();
}
