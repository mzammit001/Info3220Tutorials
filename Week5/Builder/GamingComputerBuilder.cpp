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
    CPU cpu("Intel i9 7980X 18-Core", 2.6, "LGA 2066");
    m_computer->setCPU(cpu);
}

void GamingComputerBuilder::addMotherboard()
{
    Motherboard motherboard("ASUS ROG Rampage VI Extreme", "LGA 2066", 8, 4);
    m_computer->setMotherboard(motherboard);
}

void GamingComputerBuilder::addGraphicsCard()
{
    GraphicsCard* graphicsCard = new GraphicsCard[4];
    for (int i = 0; i < 3; ++i) {
        graphicsCard[i] = GraphicsCard("NVIDIA GeForce GTX 1080 Ti", 1620, 2);
    }
    m_computer->setGraphicsCards(graphicsCard, 3);
    delete[] graphicsCard;
}

void GamingComputerBuilder::addAdditionalParts()
{
    m_computer->addAdditionalPart(Case("Corsair Obsidian 750D Black Aluminum", BaseUnit));
    m_computer->addAdditionalPart(GraphicsCard("NVIDIA GeForce GTX 1080 Ti", 1620, 2));
}
