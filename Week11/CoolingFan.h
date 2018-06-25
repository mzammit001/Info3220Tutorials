#ifndef COOLINGFAN_H
#define COOLINGFAN_H

#include "Part.h"
#include "OptionalPart.h"
#include "VisitablePart.h"
#include <stdlib.h>

class CoolingFan : public OptionalPart, public VisitablePart
{
public:

    /**
     * @brief CoolingFan default constructor
     */
    CoolingFan();

    /**
     * @brief CoolingFan constructor
     * @param name description of part
     * @param fanSpeed the Cooling Fan's speed in RPM
     */
    CoolingFan(const std::string &name, int fanSpeed);

    /**
     * @brief CoolingFan copy constructor
     * @param coolingFan a CoolingFan object
     */
    CoolingFan(const CoolingFan &coolingFan);

    /**
     * @brief ~CoolingFan destructor
     */
    virtual ~CoolingFan();

    /**
     * @brief getPartInformation constructs the part information for the CoolingFan class
     * @return returns the part information for the CoolingFan class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

private:
    int m_fanSpeed;
};

#endif // COOLINGFAN_H
