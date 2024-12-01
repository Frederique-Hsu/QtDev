/*!
 *  \file       test_qt_multithreading.c++
 *  \brief
 *
 */


#include <gtest/gtest.h>

#include <QThread>
#include <QSemaphore>
#include <QMutex>

TEST(UTest4QSemaphore, CheckQSemaphore)
{
    const int bufferSize = 10;
    QSemaphore sem(bufferSize);

    EXPECT_EQ(sem.available(), 10);

    sem.acquire(6);
    EXPECT_EQ(sem.available(), 4);
    sem.acquire(4);
    EXPECT_EQ(sem.available(), 0);

    sem.release(7);
    EXPECT_EQ(sem.available(), 7);
    sem.release(3);
    EXPECT_EQ(sem.available(), 10);

    sem.tryAcquire(2);
    EXPECT_EQ(sem.available() == 8, true);
    EXPECT_EQ(sem.tryAcquire(540), false);

    EXPECT_EQ(sem.available(), 8);
    sem.release(10);
}
