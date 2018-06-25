#include "Motherboard.h"
#include <sstream>
#include <string>

Motherboard::Motherboard()
{

}

Motherboard::Motherboard(const std::string &name, const std::string &socketType, int numberOfRamSlots, int numberOfGraphicsCardSlots)
    : Part(name), m_socketType(socketType), m_numberOfRamSlots(numberOfRamSlots), m_numberOfGraphicsCardSlots(numberOfGraphicsCardSlots)
{
}

Motherboard::Motherboard(const Motherboard &motherboard)
    : Part(motherboard.m_name), m_socketType(motherboard.m_socketType),
      m_numberOfRamSlots(motherboard.m_numberOfRamSlots),
      m_numberOfGraphicsCardSlots(motherboard.m_numberOfGraphicsCardSlots)
{

}

Motherboard::~Motherboard()
{

}

std::string Motherboard::getPartInformation() const
{
    std::stringstream partInformation;
    partInformation << "Motherboard: " << m_name + ", Socket: " << m_socketType << "\n";
    partInformation << "No. of Ram Slots: " << m_numberOfRamSlots << ", No. of Graphics Cards Permitted: " << m_numberOfGraphicsCardSlots;
    return partInformation.str();
}

Part *Motherboard::clone() const
{
    return new Motherboard(*this);
}
