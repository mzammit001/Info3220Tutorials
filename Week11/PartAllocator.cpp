#include "PartAllocator.h"

CPUSet PartAllocator::getCPUSet(CPU** cpus, int numberOfCPUs)
{
    return CPUSet(cpus, numberOfCPUs);
}

GraphicsCardSet PartAllocator::getGraphicsCardSet(GraphicsCard* graphicsCards, int numberOfGraphicsCards)
{
    return GraphicsCardSet(graphicsCards, numberOfGraphicsCards);
}

HardDriveSet PartAllocator::getHardDriveSet(HardDrive** hardDrives, int numberOfHardDrives)
{
    return HardDriveSet(hardDrives, numberOfHardDrives);
}

RamSet PartAllocator::getRamSet(Ram* ram, int numberOfRamSticks)
{
    return RamSet(ram, numberOfRamSticks);
}

// The next two methods use dynamic_cast this is a method used to cast from a
// base class down to a derived class. In doing so it check if such a cast is
// valid. If it is not it will return 0. This allows for a check to see if a
// hard drive is either a SolidStateDrive or a HardDiscDrive

HardDrive* PartAllocator::getHardDrive(HardDrive* hardDrive)
{
    if (SolidStateDrive* ssDrive = dynamic_cast<SolidStateDrive*>(hardDrive))
    {
        return new SolidStateDrive(*ssDrive);
    }
    else if (HardDiscDrive* hhDrive = dynamic_cast<HardDiscDrive*>(hardDrive))
    {
        return new HardDiscDrive(*hhDrive);
    }
    return 0;
}

CPU* PartAllocator::getCPU(CPU* cpu)
{
    return new CPU(*cpu);
}

RequiredPart* getPart1(const RequiredPart &p)
{
    if (const Case* computerCase = dynamic_cast<const Case*>(&p))
    {
        return new Case(*computerCase);
    }
    if (const CPU* cpu = dynamic_cast<const CPU*>(&p))
    {
        return new CPU(*cpu);
    }
    if (const HardDiscDrive* hdd = dynamic_cast<const HardDiscDrive*>(&p))
    {
        return new HardDiscDrive(*hdd);
    }
    if (const GraphicsCard* graphicsCard = dynamic_cast<const GraphicsCard*>(&p))
    {
        return new GraphicsCard(*graphicsCard);
    }
    if (const Motherboard* motherboard = dynamic_cast<const Motherboard*>(&p))
    {
        return new Motherboard(*motherboard);
    }
    if (const PowerSupply* psu = dynamic_cast<const PowerSupply*>(&p))
    {
        return new PowerSupply(*psu);
    }
    if (const Ram* ram = dynamic_cast<const Ram*>(&p))
    {
        return new Ram(*ram);
    }
    if (const SolidStateDrive* sdd = dynamic_cast<const SolidStateDrive*>(&p))
    {
        return new SolidStateDrive(*sdd);
    }
    return 0;
}

OptionalPart* PartAllocator::getPart(const Part &p)
{
    if (const BluRayDrive* bluRayDrive = dynamic_cast<const BluRayDrive*>(&p))
    {
        return new BluRayDrive(*bluRayDrive);
    }
    if (const CoolingFan* coolingFan = dynamic_cast<const CoolingFan*>(&p))
    {
        return new CoolingFan(*coolingFan);
    }
    if (const DVDDrive* dvdDrive = dynamic_cast<const DVDDrive*>(&p))
    {
        return new DVDDrive(*dvdDrive);
    }
    if (const WaterCooling* waterCooling = dynamic_cast<const WaterCooling*>(&p))
    {
        return new WaterCooling(*waterCooling);
    }
    return 0;
}
