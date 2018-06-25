#include "CoolingFan.h"
#include "Visitor.h"

CoolingFan::CoolingFan()
    : Part()
{

}

CoolingFan::CoolingFan(const std::string &name, int fanSpeed)
    : Part(name)
    , m_fanSpeed(fanSpeed)
{

}

CoolingFan::CoolingFan(const CoolingFan &coolingFan)
    : Part(coolingFan.m_name)
    , m_fanSpeed(coolingFan.m_fanSpeed)
{

}

CoolingFan::~CoolingFan()
{

}

std::string CoolingFan::getPartInformation() const
{
    char speed[5];
    itoa(m_fanSpeed, speed, 10);

    std::string partInformation("Cooling Fan: " + m_name + ", Speed: " + speed + " RPM");

    return partInformation;
}

void CoolingFan::accept(Visitor* visitor)
{
    visitor->visit(this);
}
