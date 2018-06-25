#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include "Part.h"
#include "RequiredPart.h"
#include "VisitablePart.h"
#include <stdlib.h>

class Motherboard : public RequiredPart, public VisitablePart
{
public:

    /**
     * @brief Motherboard default constructor
     */
    Motherboard();

    /**
     * @brief Motherboard constructor
     * @param name description of part
     * @param socketType CPU's motherboard socket type
     * @param numberOfRamSlots number of slots for RAM
     * @param numberOfGraphicsCardSlots number of slots for Graphics Cards
     */
    Motherboard(const std::string &name, const std::string &socketType, int numberOfRamSlots, int numberOfGraphicsCardSlots);

    /**
     * @brief Motherboard copy constructor
     * @param motherboards a Motherboard object
     */
    Motherboard(const Motherboard &motherboards);

    /**
     * @brief ~Motherboard destructor
     */
    virtual ~Motherboard();

    /**
     * @brief getPartInformation constructs the part information for the Motherboard class
     * @return returns the part information for the Motherboard class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

private:
    std::string m_socketType;
    int m_numberOfRamSlots;
    int m_numberOfGraphicsCardSlots;
};

#endif // MOTHERBOARD_H
