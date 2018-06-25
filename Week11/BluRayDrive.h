#ifndef BLURAYDRIVE_H
#define BLURAYDRIVE_H

#include "DiscDrive.h"

class BluRayDrive : public DiscDrive
{
public:

    /**
     * @brief BluRayDrive default constructor
     */
    BluRayDrive();

    /**
     * @brief BluRayDrive constructor
     * @param name description of part
     * @param readSpeed disc drive read speed
     */
    BluRayDrive(const std::string &name, int readSpeed);

    /**
     * @brief BluRayDrive copy constructor
     * @param discDrive a BluRayDrive object
     */
    BluRayDrive(const BluRayDrive &discDrive);

    /**
     * @brief ~BluRayDrive destructor
     */
    virtual ~BluRayDrive();

    /**
     * @brief getPartInformation constructs the part information for the BluRayDrive class
     * @return returns the part information for the BluRayDrive class as a std::string
     */
    virtual std::string getPartInformation() const;
};

#endif // BLURAYDRIVE_H
