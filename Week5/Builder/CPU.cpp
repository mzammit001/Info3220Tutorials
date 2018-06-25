#include "CPU.h"
//TODO

CPU::CPU(const std::string & name, double clockSpeed, const std::string & socketType)
    : Part(name), m_clockSpeed(clockSpeed), m_socketType(socketType)
{
}

CPU::CPU(const CPU & cpu)
    : Part(cpu.m_name), m_clockSpeed(cpu.m_clockSpeed), m_socketType(cpu.m_socketType)
{
}

std::string CPU::getPartInformation() const
{
    std::stringstream s;
    s << "CPU: " << m_name << ", Clock Speed: " << std::setprecision(2) << m_clockSpeed << " Ghz, Socket: " << m_socketType;
    return s.str();
}

Part * CPU::clone() const
{
    return new CPU(*this);
}
