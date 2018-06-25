#ifndef RAM_H
#define RAM_H

#include "Part.h"
#include "RequiredPart.h"
#include "VisitablePart.h"
#include <stdlib.h>

class Ram : public RequiredPart, public VisitablePart
{
public:

    /**
     * @brief Ram default constructor
     */
    Ram();

    /**
     * @brief Ram constructor
     * @param name description of part
     * @param speed frequency of the RAM in Megahertz
     * @param size storage capacity of the RAM
     */
    Ram(const std::string &name, int speed, int size);

    /**
     * @brief Ram copy constructor
     * @param ram a Ram object
     */
    Ram(const Ram &ram);

    /**
     * @brief ~Ram destructor
     */
    virtual ~Ram();

    /**
     * @brief getPartInformation constructs the part information for the Ram class
     * @return returns the part information for the Ram class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief getRamSpeed retrieves the ram speed
     * @return returns the ram speed
     */
    virtual int getRamSpeed() const;

    /**
     * @brief getRamSize retrieves the ram size
     * @return returns the ram size
     */
    virtual int getRamSize() const;

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

private:
    int m_speed;
    int m_size;
};

#endif // RAM_H
