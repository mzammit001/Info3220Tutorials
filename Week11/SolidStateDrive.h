#ifndef SOLIDSTATEDRIVE_H
#define SOLIDSTATEDRIVE_H

#include "HardDrive.h"

class SolidStateDrive : public HardDrive
{
public:

    /**
     * @brief SolidStateDrive default constructor
     */
    SolidStateDrive();

    /**
     * @brief SolidStateDrive constructor
     * @param name description of part
     * @param size hard drive size (GB)
     */
    SolidStateDrive(const std::string &name, int size);

    /**
     * @brief SolidStateDrive copy constructor
     * @param hardDrive a SolidStateDrive object
     */
    SolidStateDrive(const SolidStateDrive &hardDrive);

    /**
     * @brief ~SolidStateDrive destructor
     */
    virtual ~SolidStateDrive();
};

#endif // SOLIDSTATEDRIVE_H
