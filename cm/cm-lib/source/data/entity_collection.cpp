/*!
 *  \file       entity_collection.cpp
 *  \brief
 *
 */


#include "entity_collection.hpp"


namespace cm
{
namespace data
{

EntityCollectionBase::EntityCollectionBase(QObject* parent, const QString& key)
    : EntityCollectionObject(parent), m_key(key)
{
}

EntityCollectionBase::~EntityCollectionBase()
{
}

QString EntityCollectionBase::getKey() const
{
    return m_key;
}

}
}
