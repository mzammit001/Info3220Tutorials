#ifndef DISCDRIVE_H
#define DISCDRIVE_H

#include "Part.h"
#include "OptionalPart.h"
#include "VisitablePart.h"
#include <stdlib.h>

class DiscDrive : public OptionalPart, public VisitablePart
{
public:

    /**
     * @brief DiscDrive default constructor
     */
    DiscDrive();

    /**
     * @brief DiscDrive constructor
     * @param name description of part
     * @param readSpeed disc drive read speed
     */
    DiscDrive(const std::string &name, int readSpeed);

    /**
     * @brief DiscDrive copy constructor
     * @param discDrive a DiscDrive object
     */
    DiscDrive(const DiscDrive &discDrive);

    /**
     * @brief ~DiscDrive destructor
     */
    virtual ~DiscDrive();

    /**
     * @brief getPartInformation constructs the part information for the DiscDrive class
     * @return returns the part information for the DiscDrive class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

protected:
    int m_readSpeed;
};

#endif // DISCDRIVE_H
