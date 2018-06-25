#include "RequiredPart.h"

RequiredPart::RequiredPart()
    : Part(std::string())
{

}

RequiredPart::RequiredPart(const std::string &name)
    : Part(name)
{

}

RequiredPart::RequiredPart(const RequiredPart &part)
    : Part(part.m_name)
{

}

RequiredPart::~RequiredPart()
{

}

