#include "Computer.h"
#include "PartAllocator.h"


int Computer::numberOfRequiredParts = 7;

Computer::Computer()
    : m_requiredParts(new RequiredPart*[numberOfRequiredParts]),
      m_additionalParts(0),
      m_numberOfAdditionalParts(-1),
      m_numberOfAssignedAdditionalParts(-1)
{
    for (int i = 0; i < numberOfRequiredParts; ++i)
    {
        m_requiredParts[i] = 0;
    }
}

Computer::~Computer()
{
    for (int i = 0; i < m_numberOfAssignedAdditionalParts; ++i)
    {
        delete m_additionalParts[i];
    }
    if (0 != m_additionalParts)
    {
        delete[] m_additionalParts;
    }
    if (0 != m_requiredParts)
    {
        for (int i = 0; i < numberOfRequiredParts; ++i)
        {
            if (0 != m_requiredParts[i])
            {
                delete m_requiredParts[i];
            }
        }
        delete[] m_requiredParts;
    }
    m_additionalParts = 0;
    m_requiredParts = 0;
    m_numberOfAdditionalParts = -1;
}

const std::string& Computer::getComputerType() const
{
    return m_computerType;
}

const CPUSet& Computer::getCPUSet() const
{
    return *dynamic_cast<CPUSet*>(m_requiredParts[CPUID]);
}

const Motherboard& Computer::getMotherboard() const
{
    return *dynamic_cast<Motherboard*>(m_requiredParts[MotherboardID]);
}

const RamSet& Computer::getRamSet() const
{
    return *dynamic_cast<RamSet*>(m_requiredParts[RamSetID]);
}

const HardDriveSet& Computer::getHardDriveSet() const
{
    return *dynamic_cast<HardDriveSet*>(m_requiredParts[HardDriveSetID]);
}

const GraphicsCardSet& Computer::getGraphicsCardSet() const
{
    return *dynamic_cast<GraphicsCardSet*>(m_requiredParts[GraphicsCardSetID]);
}

const PowerSupply& Computer::getPowerSupply() const
{
    return *dynamic_cast<PowerSupply*>(m_requiredParts[PowerSupplyID]);
}

const Case& Computer::getCase() const
{
    return *dynamic_cast<Case*>(m_requiredParts[CaseID]);
}

Part** Computer::getAllComputerParts() const
{
    Part** parts = new Part*[numberOfRequiredParts + m_numberOfAssignedAdditionalParts];

    for (int i = 0; i < numberOfRequiredParts; ++i)
    {
        parts[i] = m_requiredParts[i];
    }
    for (int i = numberOfRequiredParts; i < numberOfRequiredParts + m_numberOfAssignedAdditionalParts; ++i)
    {
        parts[i] = m_additionalParts[i-numberOfRequiredParts];
    }

    return parts;
}

VisitablePart** Computer::getVisitableParts() const
{
    VisitablePart** parts = new VisitablePart*[numberOfRequiredParts + m_numberOfAssignedAdditionalParts] {0};

    int parts_ctr = 0;
    for (int i = 0; i < numberOfRequiredParts; ++i) {
        if (VisitablePart *vp = dynamic_cast<VisitablePart *>(m_requiredParts[i])) {
            parts[parts_ctr++] = vp;
        }
    }

    for (int i = 0; i < m_numberOfAssignedAdditionalParts; ++i) {
        if (VisitablePart *vp = dynamic_cast<VisitablePart *>(m_additionalParts[i])) {
            parts[parts_ctr++] = vp;
        }
    }

    return parts;
}

RequiredPart** Computer::getRequiredPartsList() const
{
    return m_requiredParts;
}

VisitablePart** Computer::getVisitableRequiredParts() const
{
    VisitablePart** parts = new VisitablePart*[numberOfRequiredParts] {0};

    int parts_ctr = 0;
    for (int i = 0; i < numberOfRequiredParts; ++i) {
        if (VisitablePart *vp = dynamic_cast<VisitablePart *>(m_requiredParts[i])) {
            parts[parts_ctr++] = vp;
        }
    }

    return parts;
}

OptionalPart** Computer::getAdditionalPartsList() const
{
    return m_additionalParts;
}

VisitablePart** Computer::getVisitableAdditionalParts() const
{
    VisitablePart** parts = new VisitablePart*[m_numberOfAssignedAdditionalParts] {0};
    
    int parts_ctr = 0;
    for (int i = 0; i < m_numberOfAssignedAdditionalParts; ++i) {
        if (VisitablePart *vp = dynamic_cast<VisitablePart *>(m_additionalParts[i])) {
            parts[parts_ctr++] = vp;
        }
    }

    return parts;
}

int Computer::getNumberOfAdditionalParts() const
{
    return m_numberOfAdditionalParts;
}

void Computer::setComputerType(const std::string &computerType)
{
    m_computerType = computerType;
}

void Computer::setCPUs(CPU** cpu, int numberOfCPUs)
{
    m_requiredParts[CPUID] = new CPUSet(PartAllocator::getCPUSet(cpu, numberOfCPUs));
}

void Computer::setMotherboard(const Motherboard &motherboard)
{
    m_requiredParts[MotherboardID] = new Motherboard(motherboard);
}

void Computer::setRAM(Ram* ram, int numberOfRamSticks)
{
    m_requiredParts[RamSetID] = new RamSet(PartAllocator::getRamSet(ram, numberOfRamSticks));
}

void Computer::setHardDrives(HardDrive** hardDrive, int numberOfHardDrives)
{
    m_requiredParts[HardDriveSetID] = new HardDriveSet(PartAllocator::getHardDriveSet(hardDrive, numberOfHardDrives));
}

void Computer::setGraphicsCards(GraphicsCard* graphicsCard, int numberOfGraphicsCard)
{
    m_requiredParts[GraphicsCardSetID] = new GraphicsCardSet(PartAllocator::getGraphicsCardSet(graphicsCard, numberOfGraphicsCard));
}

void Computer::setPowerSupply(const PowerSupply &powerSupply)
{
    m_requiredParts[PowerSupplyID] = new PowerSupply(powerSupply);
}

void Computer::setCase(const Case &computerCase)
{
    m_requiredParts[CaseID] = new Case(computerCase);
}

void Computer::setNumberOfAdditionalParts(int numberOfAdditionalParts)
{
    m_numberOfAdditionalParts = numberOfAdditionalParts;
    m_additionalParts = new OptionalPart*[m_numberOfAdditionalParts];

    for (int i = 0; i < m_numberOfAdditionalParts; ++i)
    {
        m_additionalParts[i] = 0;
    }

    m_numberOfAssignedAdditionalParts = 0;
}

void Computer::addAdditionalPart(const Part &part)
{
    if (m_numberOfAdditionalParts < m_numberOfAssignedAdditionalParts)
    {
        return;
    }
    m_additionalParts[m_numberOfAssignedAdditionalParts++] = PartAllocator::getPart(part);
    return;
}

std::string Computer::getComputerSpecifications() const
{
    std::string computerSpecifications = m_computerType;

    for (int i = 0; i < numberOfRequiredParts; ++i)
    {
        computerSpecifications += "\n" + m_requiredParts[i]->getPartInformation();
    }

    computerSpecifications += "\nAdditional Parts";

    for (int i = 0; i < m_numberOfAssignedAdditionalParts; ++i)
    {
        computerSpecifications += "\n" + m_additionalParts[i]->getPartInformation();
    }

    return computerSpecifications;
}
