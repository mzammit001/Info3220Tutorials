#ifndef VISITOR_H
#define VISITOR_H

// Predeclaring of Part Classes
class Case;
class CPU;
class CoolingFan;
class DiscDrive;
class GraphicsCard;
class HardDrive;
class Motherboard;
class PowerSupply;
class Ram;
class WaterCooling;

class VisitablePart;

class Visitor
{
public:

    /**
     * @brief Visitor default constructor
     */
    Visitor();

    /**
     * @brief ~Visitor destructor
     */
    virtual ~Visitor();

    /**
     * @brief visit process part using Visitor class
     * @param part the part to process
     */
    virtual void visit(VisitablePart* part) = 0;

    /**
     * @brief visit process Case using Visitor class
     * @param computerCase the Case to process
     */
    virtual void visit(Case* computerCase) = 0;

    /**
     * @brief visit process CoolingFan using Visitor class
     * @param coolingFan the CoolingFan to process
     */
    virtual void visit(CoolingFan* coolingFan) = 0;

    /**
     * @brief visit process CPU using Visitor class
     * @param cpu the CPU to process
     */
    virtual void visit(CPU* cpu) = 0;

    /**
     * @brief visit process DiscDrive using Visitor class
     * @param discDrive the DiscDrive to process
     */
    virtual void visit(DiscDrive* discDrive) = 0;

    /**
     * @brief visit process HardDrive using Visitor class
     * @param hardDrive the HardDrive to process
     */
    virtual void visit(HardDrive* hardDrive) = 0;

    /**
     * @brief visit process GraphicsCard using Visitor class
     * @param graphicsCard the GraphicsCard to process
     */
    virtual void visit(GraphicsCard* graphicsCard) = 0;

    /**
     * @brief visit process Motherboard using Visitor class
     * @param motherboard the Motherboard to process
     */
    virtual void visit(Motherboard* motherboard) = 0;

    /**
     * @brief visit process PowerSupply using Visitor class
     * @param powerSupply the PowerSupply to process
     */
    virtual void visit(PowerSupply* powerSupply) = 0;

    /**
     * @brief visit process Ram using Visitor class
     * @param ram the Ram to process
     */
    virtual void visit(Ram* ram) = 0;

    /**
     * @brief visit process WaterCooling using Visitor class
     * @param waterCooling the WaterCooling to process
     */
    virtual void visit(WaterCooling* waterCooling) = 0;

protected:
};

#endif // VISITOR_H
