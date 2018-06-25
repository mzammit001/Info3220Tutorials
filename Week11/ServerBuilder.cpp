#include "serverbuilder.h"

ServerBuilder::ServerBuilder() : ComputerBuilder()
{
}

ServerBuilder::~ServerBuilder()
{

}

void ServerBuilder::createComputer()
{
    m_computer = new Computer();
    m_computer->setComputerType("Server");
    this->ComputerBuilder::createComputer();
}

void ServerBuilder::addCPU()
{
    CPU** cpu = new CPU*[2];
    cpu[0] = new CPU("Intel Core i7-4820K Ivy Bridge-E Quad-Core", 3.7, "LGA 1155");
    cpu[1] = new CPU("Intel Core i7-4820K Ivy Bridge-E Quad-Core", 3.7, "LGA 1155");
    m_computer->setCPUs(cpu, 2);
    delete cpu[0];
    delete cpu[1];
    delete[] cpu;
}

void ServerBuilder::addMotherboard()
{
    Motherboard motherboard("Intel S2600CP2 SSI EEB Server Motherboard", "LGA 2011", 16, 1);
    m_computer->setMotherboard(motherboard);
}

void ServerBuilder::addRAM()
{
    Ram* ram = new Ram[16];
    for (int i = 0; i < 16; ++i)
    {
        ram[i] = Ram("Kingston 240-Pin DDR3 Server Memory", 1600, 16);
    }
    m_computer->setRAM(ram, 16);
    delete[] ram;
}

void ServerBuilder::addHardDrive()
{
    HardDrive** hardDrive = new HardDrive*[14];

    for (int i = 0; i < 14; ++i)
    {
         hardDrive[i] = new SolidStateDrive("SAMSUNG PM853T Data Center Series", 960);
    }
    m_computer->setHardDrives(hardDrive, 14);
    for (int i = 0; i < 14; ++i)
    {
         delete hardDrive[i];
    }
    delete[] hardDrive;
}

void ServerBuilder::addGraphicsCard()
{
    GraphicsCard* graphicsCard = new GraphicsCard[2];
    graphicsCard[0] = GraphicsCard("On board graphics", 650, 1);
    m_computer->setGraphicsCards(graphicsCard, 1);
    delete[] graphicsCard;
}

void ServerBuilder::addPowerSupply()
{
    PowerSupply powerSupply ("Athena Power AP-U2ATX70FEP8 20+4Pin", 700);
    m_computer->setPowerSupply(powerSupply);
}

void ServerBuilder::addCase()
{
    Case computerCase ("ARK IPC-4U600 Black 1.2mm SECC Zinc-Coated Steel 4U Rackmount Server Chassis", Cabinet);
    m_computer->setCase(computerCase);
}

void ServerBuilder::addAdditionalParts()
{
    CoolingFan coolingFan ("Server Cooling Fan", 1500);
    m_computer->setNumberOfAdditionalParts(4);
    m_computer->addAdditionalPart(coolingFan);
    m_computer->addAdditionalPart(coolingFan);
    m_computer->addAdditionalPart(coolingFan);
    m_computer->addAdditionalPart(coolingFan);
}
