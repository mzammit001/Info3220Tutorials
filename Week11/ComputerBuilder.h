#ifndef COMPUTERBUILDER_H
#define COMPUTERBUILDER_H

#include "Computer.h"

class ComputerBuilder
{
public:

    /**
     * @brief ComputerBuilder default constructor
     */
    ComputerBuilder();

    /**
     * @brief ~ComputerBuilder destructor
     */
    virtual ~ComputerBuilder();

    /**
     * @brief createComputer executes the algorithm to assemble a computer
     */
    virtual void createComputer();

    /**
     * @brief getResult retrieves the constructed computer
     * this should only be called after running createComputer()
     * @return the constructed computer
     */
    virtual Computer* getResult() const;

protected:

    /**
     * @brief addCPU add a CPU to the computer
     */
    virtual void addCPU() = 0;

    /**
     * @brief addMotherboard add a Motherboard to the computer
     */
    virtual void addMotherboard() = 0;

    /**
     * @brief addRAM add Ram to the computer
     */
    virtual void addRAM() = 0;

    /**
     * @brief addHardDrive add Hard Drives to the computer
     */
    virtual void addHardDrive() = 0;

    /**
     * @brief addGraphicsCard add Graphics Cards to the computer
     */
    virtual void addGraphicsCard() = 0;

    /**
     * @brief addPowerSupply add a Power Supply Unit to the computer
     */
    virtual void addPowerSupply() = 0;

    /**
     * @brief addCase add a Case to the computer
     */
    virtual void addCase() = 0;

    /**
     * @brief addAdditionalParts add any additional parts to the computer
     */
    virtual void addAdditionalParts() = 0;

    Computer* m_computer;
};

#endif // COMPUTERBUILDER_H
