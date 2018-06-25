#include "UserInterface.h"

// Add implementation code here

UserInterface & UserInterface::getInstance(int x, int y)
{
    static UserInterface singleton(x, y);
    return singleton;
}

int UserInterface::getInterfaceWidth()
{
    return m_width;
}

int UserInterface::getInterfaceHeight()
{
    return m_height;
}

UserInterface::UserInterface(int width, int height)
    : m_width(width), m_height(height)
{
}
