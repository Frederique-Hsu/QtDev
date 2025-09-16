/*!
 *  \file       qt_io_stream.hpp
 *  \brief
 *
 */


#pragma once


#include <QTextStream>
#include <QIODevice>


namespace Qt
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    QTextStream cin(stdin, QIODevice::ReadOnly);
}
