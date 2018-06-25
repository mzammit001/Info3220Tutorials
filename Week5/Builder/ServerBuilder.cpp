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
    CPU cpu ("Intel Core i7-4820K Ivy Bridge-E Quad-Core", 3.7, "LGA 1155");
    m_computer->setCPU(cpu);
}

void ServerBuilder::addMotherboard()
{
    Motherboard motherboard("Intel S2600CP2 SSI EEB Server Motherboard", "LGA 2011", 16, 1);
    m_computer->setMotherboard(motherboard);
}

void ServerBuilder::addGraphicsCard()
{
    GraphicsCard* graphicsCard = new GraphicsCard[2];
    graphicsCard[0] = GraphicsCard("On board graphics", 650, 1);
    m_computer->setGraphicsCards(graphicsCard, 1);
    delete[] graphicsCard;
}

void ServerBuilder::addAdditionalParts()
{
    CPU cpu ("Intel Core i7-4820K Ivy Bridge-E Quad-Core", 3.7, "LGA 1155");
    m_computer->addAdditionalPart(cpu);
	
}
