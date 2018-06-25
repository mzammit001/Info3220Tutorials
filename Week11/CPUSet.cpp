#include "CPUSet.h"
#include "PartAllocator.h"

CPUSet::CPUSet()
    : Part("CPU Set")
    , m_cpus(0)
    , m_numberOfCPUs(-1)
{

}

CPUSet::CPUSet(CPU** cpuSet, int numberOfCPUs)
    : Part("CPU Set")
    , m_cpus(new CPU*[numberOfCPUs])
    , m_numberOfCPUs(numberOfCPUs)
{
    for (int i = 0; i < m_numberOfCPUs; ++i)
    {
        m_cpus[i] = PartAllocator::getCPU(cpuSet[i]);
    }
}

CPUSet::CPUSet(const CPUSet& cpuSet)
    : Part("CPU Set")
    , m_cpus(new CPU*[cpuSet.getNumberOfCPUs()])
    , m_numberOfCPUs(cpuSet.getNumberOfCPUs())
{
    for (int i = 0; i < m_numberOfCPUs; ++i)
    {
        m_cpus[i] = PartAllocator::getCPU(cpuSet.m_cpus[i]);
    }
}

CPUSet::~CPUSet()
{
    if (0 != m_cpus && -1 != m_numberOfCPUs)
    {
        for (int i = 0; i < m_numberOfCPUs; ++i)
        {
            delete m_cpus[i];
        }
        delete[] m_cpus;
    }
    m_cpus = 0;
    m_numberOfCPUs = -1;
}

std::string CPUSet::getPartInformation() const
{
    std::string partInformation("CPU: Number Of CPUs: ");

    char numberOfCPUs[5];
    itoa(m_numberOfCPUs, numberOfCPUs, 10);

    partInformation += numberOfCPUs;

    for (int i = 0; i < m_numberOfCPUs; ++i)
    {
        char index[5];
        itoa(i + 1, index, 10);
        partInformation += "\nSlot " + std::string(index) + ": " + m_cpus[i]->getPartInformation();
    }

    return partInformation;
}

CPU** CPUSet::getCPUs() const
{
    return m_cpus;
}

unsigned int CPUSet::getNumberOfCPUs() const
{
    return m_numberOfCPUs;
}

void CPUSet::accept(Visitor* visitor)
{
    for (int i = 0; i < m_numberOfCPUs; ++i) {
        m_cpus[i]->accept(visitor);
    }
}

