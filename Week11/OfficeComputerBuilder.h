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
     * @brief addRAM add Ram to the Office Computer
     */
    virtual void addRAM();

    /**
     * @brief addHardDrive add Hard Drives to the Office Computer
     */
    virtual void addHardDrive();

    /**
     * @brief addGraphicsCard add Graphics Cards to the Office Computer
     */
    virtual void addGraphicsCard();

    /**
     * @brief addPowerSupply add a Power Supply Unit to the Office Computer
     */
    virtual void addPowerSupply();

    /**
     * @brief addCase add a Case to the Office Computer
     */
    virtual void addCase();

    /**
     * @brief addAdditionalParts add any additional parts to the Office Computer
     */
    virtual void addAdditionalParts();
};

#endif // OFFICECOMPUTERBUILDER_H
