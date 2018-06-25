#include "GraphicsCard.h"
#include <string>

GraphicsCard::GraphicsCard()
{

}

GraphicsCard::GraphicsCard(const std::string &name, int speed, int size) : Part(name), m_speed(speed), m_size(size)
{

}

GraphicsCard::GraphicsCard(const GraphicsCard &graphicsCard) : Part(graphicsCard.m_name), m_speed(graphicsCard.m_speed), m_size(graphicsCard.m_size)
{

}

GraphicsCard::~GraphicsCard()
{

}

std::string GraphicsCard::getPartInformation() const
{
    return std::string(m_name + ", Frequency: " + std::to_string(m_speed) + " Mhz, Size: " + std::to_string(m_size) + " GB");;
}

Part *GraphicsCard::clone() const
{
    return new GraphicsCard(*this);
}
