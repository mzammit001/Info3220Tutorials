#include "HardDrive.h"
#include "Visitor.h"
#include <iostream>

HardDrive::HardDrive()
    : Part()
{

}

HardDrive::HardDrive(const std::string &name, int size)
    : Part(name)
    , m_size(size)
{
    m_name = name;
}

HardDrive::HardDrive(const HardDrive &hardDrive)
    : Part(hardDrive.m_name)
    , m_size(hardDrive.m_size)
{
    m_name = hardDrive.m_name;
}

HardDrive::~HardDrive()
{

}

std::string HardDrive::getPartInformation() const
{
    char size[5];
    itoa(m_size, size, 10);

    std::string partInformation(m_name + ", Size: " + size + " GB");

    return partInformation;
}

int HardDrive::getHardDriveSize()
{
    return m_size;
}

void HardDrive::accept(Visitor* visitor)
{
    visitor->visit(this);
}
