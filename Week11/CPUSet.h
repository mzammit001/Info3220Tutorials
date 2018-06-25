#ifndef CPUSET_H
#define CPUSET_H

#include "CPU.h"
#include <stdlib.h>

class CPUSet : public RequiredPart, public VisitablePart
{
public:

    /**
     * @brief CPUSet default constructor
     */
    CPUSet();

    /**
     * @brief CPUSet constructor
     * @param cpuSet array of CPU pointers
     * @param numberOfCPUs number of elements in array of CPUs pointers
     */
    CPUSet(CPU** cpuSet, int numberOfCPUs);

    /**
     * @brief CPUSet copy constructor
     * @param cpuSet instance of the CPUSet to perform a deep copy on
     */
    CPUSet(const CPUSet& cpuSet);

    /**
     * @brief ~CPUSet destructor
     */
    virtual ~CPUSet();

    /**
     * @brief getPartInformation constructs the part information for the HardDriveSet class
     * @return returns the part information for the HardDriveSet class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief getCPUs get array of CPU pointers
     * @return an array of CPU pointers
     */
    CPU** getCPUs() const;

    /**
     * @brief getNumberOfCPUs retrive the number of CPUs stored in the CPUSet
     * @return the number of CPUs stored in the CPUSet
     */
    unsigned int getNumberOfCPUs() const;

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

private:
    CPU** m_cpus;
    int m_numberOfCPUs;
};

#endif // CPUSET_H
