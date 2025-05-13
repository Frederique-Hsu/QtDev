/*!
 *  \file       command.cpp
 *  \brief
 *
 */


#include "command.hpp"


class cm::framework::Command::Implementation
{
public:
    Implementation(const QString& icon_character,
                   const QString& description,
                   std::function<bool()> can_execute);
    ~Implementation() = default;
public:
    QString m_icon_character;
    QString m_description;
    std::function<bool()> m_can_execute;
};

cm::framework::Command::Implementation::Implementation(const QString& icon_character,
                                                       const QString& description,
                                                       std::function<bool()> can_execute)
    : m_icon_character{icon_character}, m_description{description}, m_can_execute{can_execute}
{
}


cm::framework::Command::Command(QObject* parent,
                                const QString& icon_character,
                                const QString& description,
                                std::function<bool()> can_exec) : QObject(parent)
{
    m_implementor.reset(new Implementation(icon_character, description, can_exec));
}

cm::framework::Command::~Command()
{
}

const QString& cm::framework::Command::iconCharacter() const
{
    return m_implementor->m_icon_character;
}

const QString& cm::framework::Command::description() const
{
    return m_implementor->m_description;
}

bool cm::framework::Command::canExecute() const
{
    return m_implementor->m_can_execute();
}