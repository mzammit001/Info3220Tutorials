#include "DiscDrive.h"
#include "Visitor.h"

DiscDrive::DiscDrive()
    : Part()
{

}

DiscDrive::DiscDrive(const std::string &name, int readSpeed)
    : Part(name)
    , m_readSpeed(readSpeed)
{
    m_name = name;
}

DiscDrive::DiscDrive(const DiscDrive &discDrive)
    : Part(discDrive.m_name)
    , m_readSpeed(discDrive.m_readSpeed)
{
    m_name = discDrive.m_name;
}


DiscDrive::~DiscDrive()
{

}

std::string DiscDrive::getPartInformation() const
{
    char speed[5];
    itoa(m_readSpeed, speed, 10);

    std::string partInformation("Disc Drive: " + m_name + ", Read Speed: " + speed + "X");

    return partInformation;
}

void DiscDrive::accept(Visitor* visitor)
{
    visitor->visit(this);
}


