#include "BluRayDrive.h"

BluRayDrive::BluRayDrive()
    : DiscDrive()
{

}

BluRayDrive::BluRayDrive(const std::string &name, int readSpeed)
    : DiscDrive(name, readSpeed)
{

}

BluRayDrive::BluRayDrive(const BluRayDrive &discDrive)
    : DiscDrive(discDrive.m_name, discDrive.m_readSpeed)
{

}

BluRayDrive::~BluRayDrive()
{

}

std::string BluRayDrive::getPartInformation() const
{
    std::string partInformation = this->DiscDrive::getPartInformation();
    partInformation.replace(0, 12, "Blu-ray Drive: ");
    return partInformation;
}
