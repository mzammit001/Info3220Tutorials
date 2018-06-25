#include "DVDDrive.h"

DVDDrive::DVDDrive()
    : DiscDrive()
{

}

DVDDrive::DVDDrive(const std::string &name, int readSpeed)
    : DiscDrive(name, readSpeed)
{

}

DVDDrive::DVDDrive(const DVDDrive &discDrive)
    : DiscDrive(discDrive.m_name, discDrive.m_readSpeed)
{

}

DVDDrive::~DVDDrive()
{

}

std::string DVDDrive::getPartInformation() const
{
    std::string partInformation = this->DiscDrive::getPartInformation();
    partInformation.replace(0, 12, "DVD Drive: ");
    return partInformation;
}
