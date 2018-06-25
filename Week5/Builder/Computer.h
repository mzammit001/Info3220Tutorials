#ifndef COMPUTER_H
#define COMPUTER_H

#include "Case.h"
#include "CPU.h"
#include "GraphicsCard.h"
#include "GraphicsCardSet.h"
#include "Motherboard.h"
#include "Part.h"

#include <vector>
class Computer
{
public:

    /**
     * @brief Computer default constructor
     */
    Computer();

    /**
     * @brief ~Computer destructor
     */
    virtual ~Computer();

    // Getters

    /**
     * @brief getComputerType retrieves the computer's type
     * @return the computer's type as std::string
     */
    virtual const std::string& getComputerType() const {return m_computerType;}

    /**
     * @brief getCPU retrieves the computer's cpu information
     * @return the computer's CPU
     */
    virtual const CPU& getCPU() const;

    /**
     * @brief getMotherboard retrieves the computer's motherboard information
     * @return the computer's Motherboard
     */
    virtual const Motherboard& getMotherboard() const;

    /**
     * @brief getGraphicsCardSet retrieves the computer's graphics card set information
     * @return the computer's GraphicsCardSet
     */
    virtual const GraphicsCardSet& getGraphicsCardSet() const;

   /**
     * @brief getAdditionalPartsList retrieves the computer's optional part information
     * @return the computer's additional part information
     */
    virtual const std::vector<Part*> &getAdditionalPartsList() const;

    /**
     * @brief getNumberOfAdditionalParts retrieves the number of optional parts included in the computer
     * @return the number of additional parts included
     */
    virtual int getNumberOfAdditionalParts() const;

    /**
     * @brief getComputerSpecifications retrieves the computers specification
     * @return as a std::string the computers specifications
     */
    virtual std::string getComputerSpecifications() const;

    // Setters

    /**
     * @brief setComputerType setter method for computerType
     * @param computerType computer's type as std::string
     */
    virtual void setComputerType(const std::string &computerType){m_computerType = computerType;}

    /**
     * @brief setCPU setter method for CPU
     * @param cpu computer's CPU
     */
    virtual void setCPU(const CPU &cpu);

    /**
     * @brief setMotherboard setter method for Motherboard
     * @param motherboard computer's Motherboard
     */
    virtual void setMotherboard(const Motherboard &motherboard);

   /**
     * @brief setGraphicsCards setter method for GraphicsCardSet
     * @param graphicsCard list of GraphicsCard
     * @param numberOfGraphicsCard number of items in GraphicsCard array
     */
    virtual void setGraphicsCards(GraphicsCard* graphicsCards, int numberOfGraphicsCard);

   /**
     * @brief addAdditionalPart adds additional Part to computer
     * @param part additional Part to add to computer
     */
    virtual void addAdditionalPart(const Part &part);

protected:

    enum ComputerPartID
    {
        CPUID,
        MotherboardID,
        GraphicsCardSetID,
    };

    std::string m_computerType;

    Part ** m_requiredParts;
    static int numberOfRequiredParts;

    std::vector<Part*> m_additionalParts;
};

#endif // COMPUTER_H
