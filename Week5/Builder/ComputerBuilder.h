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
     * @brief getResult retrives the constructed computer
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
     * @brief addGraphicsCard add Graphics Cards to the computer
     */
    virtual void addGraphicsCard() = 0;

    /**
     * @brief addAdditionalParts add any additional parts to the computer
     */
    virtual void addAdditionalParts() = 0;

    Computer* m_computer;
};

#endif // COMPUTERBUILDER_H
