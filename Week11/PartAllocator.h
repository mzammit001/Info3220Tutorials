#ifndef PARTALLOCATOR_H
#define PARTALLOCATOR_H

#include "ComputerParts.h"

class PartAllocator
{
public:

    /**
     * @brief getCPUSet creates a CPUSet using an
     * array of CPU pointers and the size of the array
     * @param cpus array of CPU pointers
     * @param numberOfCPUs size of array
     * @return a new CPUSet
     */
    static CPUSet getCPUSet(CPU** cpus, int numberOfCPUs);

    /**
     * @brief getGraphicsCardSet creates a GraphicsCardSet using an
     * array of GraphicsCard and the size of the array
     * @param graphicsCards array of GraphicsCard
     * @param numberOfGraphicsCards size of array
     * @return a new GraphicsCardSet
     */
    static GraphicsCardSet getGraphicsCardSet(GraphicsCard* graphicsCards, int numberOfGraphicsCards);

    /**
     * @brief getHardDriveSet creates a HardDriveSet using an
     * array of HardDrive pointers and the size of the array
     * @param hardDrives array of HardDrive Pointers
     * @param numberOfHardDrives size of array
     * @return a new HardDriveSet
     */
    static HardDriveSet getHardDriveSet(HardDrive** hardDrives, int numberOfHardDrives);

    /**
     * @brief getRamSet creates a RamSet using an
     * array of Ram and the size of the array
     * @param ram array of Ram
     * @param numberOfRamSticks size of array
     * @return a new RamSet
     */
    static RamSet getRamSet(Ram* ram, int numberOfRamSticks);

    /**
     * @brief getCPU performs a deep copy on a CPU pointer
     * @param cpu pointer to a CPU class
     * @return a new dynamically copied CPU pointer
     */
    static CPU* getCPU(CPU* cpu);

    /**
     * @brief getHardDrive performs a deep copy on a HardDrive pointer
     * @param hardDrive pointer to a HardDrive class
     * @return a new dynamically copied HardDrive pointer
     */
    static HardDrive* getHardDrive(HardDrive* hardDrive);

    /**
     * @brief getPart performs a deep copy on a Part object
     * @param p the part which needs to be copied
     * @return a new dynamically copied Part pointer
     */
    static OptionalPart* getPart(const Part &p);

private:
    // Prevent the creation of this class. This class is purely a set of helper methods
    PartAllocator();
    PartAllocator(const PartAllocator& allocator);
    PartAllocator& operator=(const PartAllocator& allocator);
};

#endif // PARTALLOCATOR_H
