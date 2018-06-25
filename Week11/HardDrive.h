#ifndef HARDDRIVE_H
#define HARDDRIVE_H

#include "Part.h"
#include "RequiredPart.h"
#include "VisitablePart.h"
#include <stdlib.h>

class HardDrive : public RequiredPart, public VisitablePart
{
public:

    /**
     * @brief HardDrive default constructor
     */
    HardDrive();

    /**
     * @brief HardDrive constructor
     * @param name description of part
     * @param size hard drive size (GB)
     */
    HardDrive(const std::string &name, int size);

    /**
     * @brief HardDrive copy constructor
     * @param hardDrive a HardDrive object
     */
    HardDrive(const HardDrive &hardDrive);

    /**
     * @brief ~HardDrive destructor
     */
    virtual ~HardDrive();

    /**
     * @brief getPartInformation constructs the part information for the HardDrive class
     * @return returns the part information for the HardDrive class as a std::string
     */
    virtual std::string getPartInformation() const;
    /**
     * @brief getHardDriveSize retrieves the hard drive size
     * @return returns the hard drive size
     */
    virtual int getHardDriveSize();

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

protected:
    int m_size;
};

#endif // HARDDRIVE_H
