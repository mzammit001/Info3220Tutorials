#ifndef OFFICECOMPUTERBUILDER_H
#define OFFICECOMPUTERBUILDER_H

#include "ComputerBuilder.h"

class OfficeComputerBuilder : public ComputerBuilder
{
public:

    /**
     * @brief OfficeComputerBuilder default constructor
     */
    OfficeComputerBuilder();

    /**
     * @brief ~OfficeComputerBuilder destructor
     */
    virtual ~OfficeComputerBuilder();

    /**
     * @brief createComputer executes the algorithm to assemble an Office Computer
     */
    virtual void createComputer();

protected:

    /**
     * @brief addCPU add a CPU to the Office Computer
     */
    virtual void addCPU();

    /**
     * @brief addMotherboard add a Motherboard to the Office Computer
     */
    virtual void addMotherboard();

    /**
     * @brief addGraphicsCard add Graphics Cards to the Office Computer
     */
    virtual void addGraphicsCard();

    /**
     * @brief addAdditionalParts add any additional parts to the Office Computer
     */
    virtual void addAdditionalParts();
};

#endif // OFFICECOMPUTERBUILDER_H
