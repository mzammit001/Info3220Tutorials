#ifndef OPTIONALPART_H
#define OPTIONALPART_H

#include "Part.h"

class OptionalPart : virtual public Part
{
public:

    /**
     * @brief OptionalPart default constructor
     */
    OptionalPart();

    /**
     * @brief OptionalPart constructor
     * @param name description of part
     */
    OptionalPart(const std::string &name);

    /**
     * @brief OptionalPart copy constructor
     * @param part a OptionalPart object
     */
    OptionalPart(const OptionalPart &part);

    /**
     * @brief ~OptionalPart destructor
     */
    virtual ~OptionalPart();

    /**
     * @brief getPartInformation constructs the part information for the OptionalPart class
     * @return returns the part information for the OptionalPart class as a std::string
     */
    virtual std::string getPartInformation() const = 0;
};

#endif // OPTIONALPART_H
