#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include "Part.h"
#include <stdlib.h>

class Motherboard : public Part
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

private:
    std::string m_socketType;
    int m_numberOfRamSlots;
    int m_numberOfGraphicsCardSlots;

    // Part interface
public:
    Part *clone() const;
};

#endif // MOTHERBOARD_H
