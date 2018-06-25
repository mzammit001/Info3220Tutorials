#ifndef POWERSUPPLY_H
#define POWERSUPPLY_H

#include "Part.h"
#include "RequiredPart.h"
#include "VisitablePart.h"
#include <stdlib.h>

class PowerSupply : public RequiredPart, public VisitablePart
{
public:

    /**
     * @brief PowerSupply default constructor
     */
    PowerSupply();

    /**
     * @brief PowerSupply constructor
     * @param name description of part
     * @param watts max power output (watts)
     */
    PowerSupply(const std::string &name, int watts);

    /**
     * @brief PowerSupply copy constructor
     * @param powerSupply a PowerSupply object
     */
    PowerSupply(const PowerSupply &powerSupply);

    /**
     * @brief ~PowerSupply destructor
     */
    virtual ~PowerSupply();

    /**
     * @brief getPartInformation constructs the part information for the PowerSupply class
     * @return returns the part information for the PowerSupply class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

private:
    int m_watts;
};

#endif // POWERSUPPLY_H
