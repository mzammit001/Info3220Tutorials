#include "Part.h"

Part::Part() : m_name(std::string())
{

}

Part::Part(const std::string &name) : m_name(name)
{

}

Part::Part(const Part &part) : m_name(part.m_name)
{

}

Part::~Part()
{

}

const std::string& Part::getPartName() const
{
    return m_name;
}
