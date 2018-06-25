#ifndef GRAPHICSCARD_H
#define GRAPHICSCARD_H

#include "Part.h"
#include "RequiredPart.h"
#include "VisitablePart.h"
#include <stdlib.h>

class GraphicsCard : public RequiredPart, public VisitablePart
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

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

private:
    int m_speed;
    int m_size;
};

#endif // GRAPHICSCARD_H
