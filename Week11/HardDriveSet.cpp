#include "HardDriveSet.h"
#include "PartAllocator.h"

HardDriveSet::HardDriveSet()
    : Part("Hard Drive Set")
    , m_hardDrives(0)
    , m_numberOfHardDrives(-1)
{

}

HardDriveSet::HardDriveSet(HardDrive** hardDrives, int numberOfHardDrives)
    : Part("Hard Drive Set")
    , m_hardDrives(new HardDrive*[numberOfHardDrives])
    , m_numberOfHardDrives(numberOfHardDrives)
{
    for (int i = 0; i < m_numberOfHardDrives; ++i)
    {
        m_hardDrives[i] = PartAllocator::getHardDrive(hardDrives[i]);
    }
}

HardDriveSet::HardDriveSet(const HardDriveSet& hardDriveSet)
    : Part("Hard Drive Set")
    , m_hardDrives(new HardDrive*[hardDriveSet.getNumberOfHardDrives()])
    , m_numberOfHardDrives(hardDriveSet.getNumberOfHardDrives())
{
    for (int i = 0; i < m_numberOfHardDrives; ++i)
    {
        m_hardDrives[i] = PartAllocator::getHardDrive(hardDriveSet.m_hardDrives[i]);
    }
}

HardDriveSet::~HardDriveSet()
{
    if (0 != m_hardDrives && -1 != m_numberOfHardDrives)
    {
        for (int i = 0; i < m_numberOfHardDrives; ++i)
        {
            delete m_hardDrives[i];
        }
        delete[] m_hardDrives;
    }
    m_hardDrives = 0;
    m_numberOfHardDrives = -1;
}

std::string HardDriveSet::getPartInformation() const
{
    std::string partInformation("Hard Drives: Number Of Drives: ");

    char numberOfHardDrives[5];
    itoa(m_numberOfHardDrives, numberOfHardDrives, 10);

    partInformation += numberOfHardDrives;

    for (int i = 0; i < m_numberOfHardDrives; ++i)
    {
        char index[5];
        itoa(i + 1, index, 10);
        partInformation += "\nDrive " + std::string(index) + ": " + m_hardDrives[i]->getPartInformation();
    }

    return partInformation;
}

HardDrive** HardDriveSet::getHardDrives() const
{
    return m_hardDrives;
}

int HardDriveSet::getNumberOfHardDrives() const
{
    return m_numberOfHardDrives;
}

void HardDriveSet::accept(Visitor* visitor)
{
    for (int i = 0; i < m_numberOfHardDrives; ++i)
    {
        m_hardDrives[i]->HardDrive::accept(visitor);
    }
}
