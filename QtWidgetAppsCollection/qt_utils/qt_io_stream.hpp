/*!
 *  \file       qt_io_stream.hpp
 *  \brief
 *
 */


#pragma once


#include <QTextStream>


namespace Qt
{
    QTextStream cout(stdout, QIODevice::WriteOnly);
    QTextStream cin(stdin, QIODevice::ReadOnly);
}