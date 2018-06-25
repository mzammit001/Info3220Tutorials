#ifndef COUNTINGVISITOR_H
#define COUNTINGVISITOR_H

#include "Visitor.h"

class BluRayDrive;
class DVDDrive;

class CountingVisitor : public Visitor
{
public:

    /**
     * @brief CountingVisitor default constructor
     */
    CountingVisitor();

    /**
     * @brief ~CountingVisitor destructor
     */
    virtual ~CountingVisitor();

    // visitors

    /**
     * @brief visit process part using CountingVisitor class
     * @param part the part to process
     */
    virtual void visit(VisitablePart* part);

    /**
     * @brief visit process Case using CountingVisitor class
     * @param computerCase the Case to process
     */
    virtual void visit(Case* computerCase);

    /**
     * @brief visit process CoolingFan using CountingVisitor class
     * @param coolingFan the CoolingFan to process
     */
    virtual void visit(CoolingFan* coolingFan);

    /**
     * @brief visit process CPU using CountingVisitor class
     * @param cpu the CPU to process
     */
    virtual void visit(CPU* cpu);

    /**
     * @brief visit process DiscDrive using CountingVisitor class
     * @param discDrive the DiscDrive to process
     */
    virtual void visit(DiscDrive* discDrive);

    /**
     * @brief visit process HardDrive using CountingVisitor class
     * @param hardDrive the HardDrive to process
     */
    virtual void visit(HardDrive* hardDrive);

    /**
     * @brief visit process GraphicsCard using CountingVisitor class
     * @param graphicsCard the GraphicsCard to process
     */
    virtual void visit(GraphicsCard* graphicsCard);

    /**
     * @brief visit process Motherboard using CountingVisitor class
     * @param motherboard the Motherboard to process
     */
    virtual void visit(Motherboard* motherboard);

    /**
     * @brief visit process PowerSupply using CountingVisitor class
     * @param powerSupply the PowerSupply to process
     */
    virtual void visit(PowerSupply* powerSupply);

    /**
     * @brief visit process Ram using CountingVisitor class
     * @param ram the Ram to process
     */
    virtual void visit(Ram* ram);

    /**
     * @brief visit process WaterCooling using CountingVisitor class
     * @param waterCooling the WaterCooling to process
     */
    virtual void visit(WaterCooling* waterCooling);

    // getters

    /**
     * @brief numberOfBluRayDrive retrive the number of blu-ray drives visited
     * @return the number of blu-ray drives visited
     */
    virtual unsigned int numberOfBluRayDrive() const;

    /**
     * @brief numberOfCoolingFans retrive the number of cooling fans visited
     * @return the number of cooling fans visited
     */
    virtual unsigned int numberOfCoolingFans() const;

    /**
     * @brief numberOfCases retrive the number of cases visited
     * @return the number of cases visited
     */
    virtual unsigned int numberOfCases() const;

    /**
     * @brief numberOfCPUs retrive the number of cpus visited
     * @return the number of cpus visited
     */
    virtual unsigned int numberOfCPUs() const;

    /**
     * @brief numberOfDVDDrives retrive the number of dvd drives visited
     * @return the number of dvd drives visited
     */
    virtual unsigned int numberOfDVDDrives() const;

    /**
     * @brief numberOfHardDrives retrive the number of hard drives visited
     * @return the number of hard drives visited
     */
    virtual unsigned int numberOfHardDrives() const;

    /**
     * @brief numberOfGraphicsCards retrive the number of graphics cards visited
     * @return the number of graphics cards visited
     */
    virtual unsigned int numberOfGraphicsCards() const;

    /**
     * @brief numberOfMotherboards retrive the number of motherboards visited
     * @return the number of motherboards visited
     */
    virtual unsigned int numberOfMotherboards() const;

    /**
     * @brief numberOfPowerSupplies retrive the number of power supply units visited
     * @return the number of power supply units visited
     */
    virtual unsigned int numberOfPowerSupplies() const;

    /**
     * @brief numberOfRamSticks retrive the number of ram sticks visited
     * @return the number of ram sticks visited
     */
    virtual unsigned int numberOfRamSticks() const;

    /**
     * @brief numberOfWaterCoolingUnits retrive the number of water cooling units visited
     * @return the number of water cooling units visited
     */
    virtual unsigned int numberOfWaterCoolingUnits() const;

protected:

    unsigned int m_numberOfBluRayDrives;
    unsigned int m_numberOfCoolingFans;
    unsigned int m_numberOfCases;
    unsigned int m_numberOfCPUs;
    unsigned int m_numberOfDVDDrives;
    unsigned int m_numberOfHardDrives;
    unsigned int m_numberOfGraphicsCards;
    unsigned int m_numberOfMotherboards;
    unsigned int m_numberOfPowerSupplies;
    unsigned int m_numberOfRamSticks;
    unsigned int m_numberOfWaterCoolingUnits;
};

#endif // COUNTINGVISITOR_H
