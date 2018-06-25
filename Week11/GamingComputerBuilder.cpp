#include "GamingComputerBuilder.h"

GamingComputerBuilder::GamingComputerBuilder() : ComputerBuilder()
{
}

GamingComputerBuilder::~GamingComputerBuilder()
{

}

void GamingComputerBuilder::createComputer()
{
    m_computer = new Computer();
    m_computer->setComputerType("Gaming Computer");
    this->ComputerBuilder::createComputer();
}

void GamingComputerBuilder::addCPU()
{
    CPU** cpu = new CPU*[1];
    cpu[0] = new CPU("Intel Core i7-4820K Ivy Bridge-E Quad-Core", 3.7, "LGA 1155");
    m_computer->setCPUs(cpu, 1);
    delete cpu[0];
    delete[] cpu;
}

void GamingComputerBuilder::addMotherboard()
{
    Motherboard motherboard("ASUS Maximus V EXTREME", "LGA 1155", 4, 2);
    m_computer->setMotherboard(motherboard);
}

void GamingComputerBuilder::addRAM()
{
    Ram* ram = new Ram[4];
    ram[0] = Ram("HyperX FURY", 1866, 8);
    ram[1] = Ram("HyperX FURY", 1866, 8);
    ram[2] = Ram("HyperX FURY", 1866, 8);
    ram[3] = Ram("HyperX FURY", 1866, 8);
    m_computer->setRAM(ram, 4);
    delete[] ram;
}

void GamingComputerBuilder::addHardDrive()
{
    HardDrive** hardDrives = new HardDrive*[3];

    hardDrives[0] = new SolidStateDrive("SAMSUNG 850 EVO-Series MZ-75E1T0B/AM", 1000);
    hardDrives[1] = new HardDiscDrive("WD BLACK SERIES WD2003FZEX", 2000, 7200);
    hardDrives[2] = new HardDiscDrive("WD BLACK SERIES WD2003FZEX", 2000, 7200);
    m_computer->setHardDrives(hardDrives, 3);

    for (int i = 0; i < 3; ++i)
    {
        delete hardDrives[i];
    }
    delete[] hardDrives;
}

void GamingComputerBuilder::addGraphicsCard()
{
    GraphicsCard* graphicsCards = new GraphicsCard[2];
    graphicsCards[0] = GraphicsCard("GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti", 1033, 2);
    graphicsCards[1] = GraphicsCard("GIGABYTE GV-N75TOC-2GI G-SYNC Support GeForce GTX 750 Ti", 1033, 2);
    m_computer->setGraphicsCards(graphicsCards, 2);
    delete[] graphicsCards;
}

void GamingComputerBuilder::addPowerSupply()
{
    PowerSupply powerSupply ("Cougar CMX1000 V3", 1000);
    m_computer->setPowerSupply(powerSupply);
}

void GamingComputerBuilder::addCase()
{
    Case computerCase ("NZXT Phantom 240", Tower);
    m_computer->setCase(computerCase);
}

void GamingComputerBuilder::addAdditionalParts()
{
    BluRayDrive blueRay ("LG Black 12X BD-ROM", 12);
    m_computer->setNumberOfAdditionalParts(1);
    m_computer->addAdditionalPart(blueRay);
}
