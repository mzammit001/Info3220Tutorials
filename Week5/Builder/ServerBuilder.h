#ifndef SERVERBUILDER_H
#define SERVERBUILDER_H

#include "ComputerBuilder.h"

class ServerBuilder : public ComputerBuilder
{
public:

    /**
     * @brief ServerBuilder default constructor
     */
    ServerBuilder();

    /**
     * @brief ~ServerBuilder destructor
     */
    virtual ~ServerBuilder();

    /**
     * @brief createComputer executes the algorithm to assemble a Server
     */
    virtual void createComputer();

protected:

    /**
     * @brief addCPU add a CPU to the server
     */
    virtual void addCPU();

    /**
     * @brief addMotherboard add a Motherboard to the server
     */
    virtual void addMotherboard();

    /**
     * @brief addGraphicsCard add Graphics Cards to the server
     */
    virtual void addGraphicsCard();

    /**
     * @brief addAdditionalParts add any additional parts to the server
     */
    virtual void addAdditionalParts();
};

#endif // SERVERBUILDER_H
