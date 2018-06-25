#include "Computer.h"
#include <sstream>

int Computer::numberOfRequiredParts = 3;

//TODO

Computer::Computer()
    : m_requiredParts(new Part *[numberOfRequiredParts] {nullptr})
{
}

Computer::~Computer()
{
    for (int i = 0; i < numberOfRequiredParts; ++i)
        delete m_requiredParts[i];

    delete[] m_requiredParts;

    for (auto p : m_additionalParts) {
        delete p;
    }
}

const CPU & Computer::getCPU() const
{
    return *static_cast<CPU *>(m_requiredParts[0]);
}

const Motherboard & Computer::getMotherboard() const
{
    return *static_cast<Motherboard *>(m_requiredParts[1]);
}

const GraphicsCardSet & Computer::getGraphicsCardSet() const
{
    return *static_cast<GraphicsCardSet *>(m_requiredParts[2]);
}

const std::vector<Part*>& Computer::getAdditionalPartsList() const
{
    return m_additionalParts;
}

int Computer::getNumberOfAdditionalParts() const
{
    return m_additionalParts.size();
}

std::string Computer::getComputerSpecifications() const
{
    std::stringstream s;
    s << m_computerType << std::endl;
    s << m_requiredParts[0]->getPartInformation() << std::endl;
    s << m_requiredParts[1]->getPartInformation() << std::endl;
    s << m_requiredParts[2]->getPartInformation() << std::endl;
    s << "Additional Parts" << std::endl;

    for (Part *p : m_additionalParts) {
        s << p->getPartInformation() << std::endl;
    }

    return s.str();
}

void Computer::setCPU(const CPU & cpu)
{
    m_requiredParts[0] = new CPU(cpu);
}

void Computer::setMotherboard(const Motherboard & motherboard)
{
    m_requiredParts[1] = new Motherboard(motherboard);
}

void Computer::setGraphicsCards(GraphicsCard * graphicsCards, int numberOfGraphicsCard)
{
    m_requiredParts[2] = new GraphicsCardSet(graphicsCards, numberOfGraphicsCard);
}

void Computer::addAdditionalPart(const Part & part)
{
    m_additionalParts.push_back(part.clone());
}
