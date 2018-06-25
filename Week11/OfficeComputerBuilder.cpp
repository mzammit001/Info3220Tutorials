#include "OfficeComputerBuilder.h"

OfficeComputerBuilder::OfficeComputerBuilder() : ComputerBuilder()
{

}

OfficeComputerBuilder::~OfficeComputerBuilder()
{

}

void OfficeComputerBuilder::createComputer()
{
    m_computer = new Computer();
    m_computer->setComputerType("Office Computer");
    this->ComputerBuilder::createComputer();
}

void OfficeComputerBuilder::addCPU()
{
    CPU** cpu = new CPU*[1];
    cpu[0] = new CPU("Intel Celeron G1610 Ivy Bridge Dual-Core", 2.6, "LGA 1155");
    m_computer->setCPUs(cpu, 1);
    delete cpu[0];
    delete[] cpu;
}

void OfficeComputerBuilder::addMotherboard()
{
    Motherboard motherboard("ASUS P8H61-M LE/CSM R2.0", "LGA 1155", 2, 1);
    m_computer->setMotherboard(motherboard);
}

void OfficeComputerBuilder::addRAM()
{
    Ram* ram = new Ram[2];
    ram[0] = Ram("CORSAIR Vengeance", 1600, 4);
    ram[1] = Ram("CORSAIR Vengeance", 1600, 4);
    m_computer->setRAM(ram, 2);
    delete[] ram;
}

void OfficeComputerBuilder::addHardDrive()
{
    HardDrive** hardDrive = new HardDrive*[1];
    hardDrive[0] = new HardDiscDrive("Western Digital Blue WD5000AAKX", 500, 7200);
    m_computer->setHardDrives(hardDrive, 1);
    delete hardDrive[0];
    delete[] hardDrive;
}

void OfficeComputerBuilder::addGraphicsCard()
{
    GraphicsCard* graphicsCard = new GraphicsCard[2];
    graphicsCard[0] = GraphicsCard("On board graphics", 650, 1);
    m_computer->setGraphicsCards(graphicsCard, 1);
    delete[] graphicsCard;
}

void OfficeComputerBuilder::addPowerSupply()
{
    PowerSupply powerSupply ("Be Quiet! Power Zone", 650);
    m_computer->setPowerSupply(powerSupply);
}

void OfficeComputerBuilder::addCase()
{
    Case computerCase ("Corsair Obsidian 750D Black Aluminum", BaseUnit);
    m_computer->setCase(computerCase);
}

void OfficeComputerBuilder::addAdditionalParts()
{
    DVDDrive dvdDrive("ASUS 24X DVD Burner", 24);
    m_computer->setNumberOfAdditionalParts(1);
    m_computer->addAdditionalPart(dvdDrive);
}
