#ifndef GRAPHICSCARD_H
#define GRAPHICSCARD_H

#include "Part.h"
#include <stdlib.h>

class GraphicsCard : public Part
{
public:

    /**
     * @brief GraphicsCard default constructor
     */
    GraphicsCard();

    /**
     * @brief GraphicsCard constructor
     * @param name description of part
     * @param speed frequency of the graphics card in Megahertz
     * @param size storage capacity of the graphics card
     */
    GraphicsCard(const std::string &name, int speed, int size);

    /**
     * @brief GraphicsCard copy constructor
     * @param graphicsCard a GraphicsCard object
     */
    GraphicsCard(const GraphicsCard &graphicsCard);

    /**
     * @brief ~GraphicsCard destructor
     */
    virtual ~GraphicsCard();

    /**
     * @brief getPartInformation constructs the part information for the GraphicsCard class
     * @return returns the part information for the GraphicsCard class as a std::string
     */
    virtual std::string getPartInformation() const;

private:
    int m_speed;
    int m_size;

    // Part interface
public:
    Part *clone() const;
};

#endif // GRAPHICSCARD_H
