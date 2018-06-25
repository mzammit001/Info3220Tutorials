#ifndef HARDDISCDRIVE_H
#define HARDDISCDRIVE_H

#include "HardDrive.h"

class HardDiscDrive : public HardDrive
{
public:

    /**
     * @brief HardDiscDrive default constructor
     */
    HardDiscDrive();

    /**
     * @brief HardDiscDrive constructor
     * @param name description of part
     * @param size of the hard drive (GB)
     * @param spinSpeed hard disc spin rate (RPM)
     */
    HardDiscDrive(const std::string &name, int size, int spinSpeed);

    /**
     * @brief HardDiscDrive copy constructor
     * @param hardDrive a HardDiscDrive object
     */
    HardDiscDrive(const HardDiscDrive &hardDrive);

    /**
     * @brief ~HardDiscDrive destructor
     */
    virtual ~HardDiscDrive();

    /**
     * @brief getPartInformation constructs the part information for the HardDiscDrive class
     * @return returns the part information for the HardDiscDrive class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief getSpinSpeed
     * @return
     */
    int getSpinSpeed() const;

private:
    int m_spinSpeed;
};

#endif // HARDDISCDRIVE_H
