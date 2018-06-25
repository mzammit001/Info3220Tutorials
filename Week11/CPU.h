#ifndef CPU_H
#define CPU_H

#include "Part.h"
#include "RequiredPart.h"
#include "VisitablePart.h"

class CPU : public RequiredPart, public VisitablePart
{
public:

    /**
     * @brief CPU default constructor
     */
    CPU();

    /**
     * @brief CPU constructor
     * @param name description of part
     * @param clockSpeed CPU's clock speed (floating point)
     * @param socketType CPU's motherboard socket type
     */
    CPU(const std::string &name, double clockSpeed, const std::string &socketType);

    /**
     * @brief CPU copy constructor
     * @param cpu a CPU object
     */
    CPU(const CPU& cpu);

    /**
     * @brief ~CPU destructor
     */
    virtual ~CPU();

    /**
     * @brief getPartInformation constructs the part information for the CPU class
     * @return returns the part information for the CPU class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

private:
    double m_clockSpeed;
    std::string m_socketType;
};

#endif // CPU_H
