#ifndef DVDDRIVE_H
#define DVDDRIVE_H

#include "DiscDrive.h"

class DVDDrive : public DiscDrive
{
public:

    /**
     * @brief DVDDrive default constructor
     */
    DVDDrive();

    /**
     * @brief DVDDrive constructor
     * @param name description of part
     * @param readSpeed disc drive read speed
     */
    DVDDrive(const std::string &name, int readSpeed);

    /**
     * @brief DVDDrive copy constructor
     * @param discDrive a DVDDrive object
     */
    DVDDrive(const DVDDrive &discDrive);

    /**
     * @brief ~DVDDrive destructor
     */
    virtual ~DVDDrive();

    /**
     * @brief getPartInformation constructs the part information for the DVDDrive class
     * @return returns the part information for the DVDDrive class as a std::string
     */
    virtual std::string getPartInformation() const;
};

#endif // DVDDRIVE_H
