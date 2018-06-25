#ifndef CPU_H
#define CPU_H

#include "Part.h"

class CPU : public Part
{
public:

    /**
     * @brief CPU default constructor
     */
    CPU(){}

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
    virtual ~CPU(){}

    /**
     * @brief getPartInformation constructs the part information for the CPU class
     * @return returns the part information for the CPU class as a std::string
     */
    virtual std::string getPartInformation() const;

private:
    double m_clockSpeed;
    std::string m_socketType;

    // Part interface
public:
    Part *clone() const;
};

#endif // CPU_H
