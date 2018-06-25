#ifndef USERINTERFACE_H
#define USERINTERFACE_H

class UserInterface
{
public:
    static UserInterface& getInstance(int x, int y);
    int getInterfaceWidth();
    int getInterfaceHeight();

private:
    UserInterface(int width, int height);

    int m_width;
    int m_height;
    // Add private methods and member variables here
};

#endif // USERINTERFACE_H
