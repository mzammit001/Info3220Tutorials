#ifndef COMPUTERPLAN_H
#define COMPUTERPLAN_H

#include "ComputerParts.h"

class ComputerPlan
{
public:

    /**
     * @brief setComputerType setter method for computerType
     * @param computerType computer's type as std::string
     */
    virtual void setComputerType(const std::string &computerType) = 0;

    /**
     * @brief setCPUs setter method for CPUSet
     * @param cpu list of CPU pointers
     * @param numberOfCPUs number of iterms in the CPU pointer array
     */
    virtual void setCPUs(CPU** cpu, int numberOfCPUs) = 0;

    /**
     * @brief setMotherboard setter method for Motherboard
     * @param motherboard computer's Motherboard
     */
    virtual void setMotherboard(const Motherboard &motherboard) = 0;

    /**
     * @brief setRAM setter method for RamSet
     * @param ram list of Ram
     * @param numberOfRamSticks number of items in Ram array
     */
    virtual void setRAM(Ram* ram, int numberOfRamSticks) = 0;

    /**
     * @brief setHardDrives setter method for HardDriveSet
     * @param hardDrive list of HardDrive pointers
     * @param numberOfHardDrives number of items in HardDrive pointer array
     */
    virtual void setHardDrives(HardDrive** hardDrive, int numberOfHardDrives) = 0;

    /**
     * @brief setGraphicsCards setter method for GraphicsCardSet
     * @param graphicsCard list of GraphicsCard
     * @param numberOfGraphicsCard number of items in GraphicsCard array
     */
    virtual void setGraphicsCards(GraphicsCard* graphicsCard, int numberOfGraphicsCard) = 0;

    /**
     * @brief setPowerSupply setter method for PowerSupply
     * @param powerSupply computer's PowerSupply
     */
    virtual void setPowerSupply(const PowerSupply &powerSupply) = 0;

    /**
     * @brief setCase setter method for Case
     * @param computerCase computer's Case
     */
    virtual void setCase(const Case &computerCase) = 0;

    /**
     * @brief setNumberOfAdditionalParts sets the number of additional parts permitted for computer
     * @param numberOfAdditionalParts the number of additional parts permitted for computer
     */
    virtual void setNumberOfAdditionalParts(int numberOfAdditionalParts ) = 0;

    /**
     * @brief addAdditionalPart adds one new additional Part to computer
     * @param part additional Part to add to computer
     */
    virtual void addAdditionalPart(const Part &part) = 0;
};

#endif // COMPUTERPLAN_H
