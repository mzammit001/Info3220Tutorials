#ifndef VISITABLEPART_H
#define VISITABLEPART_H

#include "Part.h"
class Visitor;

class VisitablePart : virtual public Part
{
public:
    /**
     * @brief VisitablePart default constructor
     */
    VisitablePart();

    /**
     * @brief VisitablePart constructor
     * @param name description of part
     */
    VisitablePart(const std::string &name);

    /**
     * @brief VisitablePart copy constructor
     * @param part a VisitablePart object
     */
    VisitablePart(const VisitablePart &part);

    /**
     * @brief ~VisitablePart destructor
     */
    virtual ~VisitablePart();

    /**
     * @brief getPartInformation constructs the part information for the VisitablePart class
     * @return returns the part information for the VisitablePart class as a std::string
     */
    virtual std::string getPartInformation() const = 0;

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor) = 0;
};

#endif // VISITABLEPART_H
