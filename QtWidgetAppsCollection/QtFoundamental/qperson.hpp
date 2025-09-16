/*!
 *  \file       qperson.hpp
 *  \brief
 *
 */


#pragma once

#include <QObject>

class QPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author", "Frederique Hsu")
    Q_CLASSINFO("company", "BMW")
    Q_CLASSINFO("version", "1.0.1")

    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)
public:
    explicit QPerson(QString fname, QObject* parent = nullptr);
private:
    int m_age;
    QString m_name;
    int m_score;
public:
    int age();
    void setAge(int value);
    void incAge();
signals:        // signals =  public __attribute__((annotate("qt_signal")))
    void ageChanged(int value);
public slots:   // slots = __attribute__((annotate("qt_slot")))
};
