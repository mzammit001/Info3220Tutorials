#ifndef GAMINGCOMPUTERBUILDER_H
#define GAMINGCOMPUTERBUILDER_H

#include "ComputerBuilder.h"

class GamingComputerBuilder : public ComputerBuilder
{
public:

    /**
     * @brief GamingComputerBuilder default constructor
     */
    GamingComputerBuilder();

    /**
     * @brief ~GamingComputerBuilder destructor
     */
    virtual ~GamingComputerBuilder();

    /**
     * @brief createComputer executes the algorithm to assemble a Gaming Computer
     */
    virtual void createComputer();

protected:

    /**
     * @brief addCPU add a CPU to the Gaming Computer
     */
    virtual void addCPU();

    /**
     * @brief addMotherboard add a Motherboard to the Gaming Computer
     */
    virtual void addMotherboard();

    /**
     * @brief addRAM add Ram to the Gaming Computer
     */
    virtual void addRAM();

    /**
     * @brief addHardDrive add Hard Drives to the Gaming Computer
     */
    virtual void addHardDrive();

    /**
     * @brief addGraphicsCard add Graphics Cards to the Gaming Computer
     */
    virtual void addGraphicsCard();

    /**
     * @brief addPowerSupply add a Power Supply Unit to the Gaming Computer
     */
    virtual void addPowerSupply();

    /**
     * @brief addCase add a Case to the Gaming Computer
     */
    virtual void addCase();

    /**
     * @brief addAdditionalParts add any additional parts to the Gaming Computer
     */
    virtual void addAdditionalParts();
};

#endif // GAMINGCOMPUTERBUILDER_H
