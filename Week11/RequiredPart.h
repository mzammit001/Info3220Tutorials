#ifndef REQUIREDPART_H
#define REQUIREDPART_H

#include "Part.h"

class RequiredPart : virtual public Part
{
public:

    /**
     * @brief RequiredPart default constructor
     */
    RequiredPart();

    /**
     * @brief RequiredPart constructor
     * @param name description of part
     */
    RequiredPart(const std::string &name);

    /**
     * @brief RequiredPart copy constructor
     * @param part a RequiredPart object
     */
    RequiredPart(const RequiredPart &part);

    /**
     * @brief ~RequiredPart destructor
     */
    virtual ~RequiredPart();

    /**
     * @brief getPartInformation constructs the part information for the RequiredPart class
     * @return returns the part information for the RequiredPart class as a std::string
     */
    virtual std::string getPartInformation() const = 0;
};

#endif // REQUIREDPART_H
