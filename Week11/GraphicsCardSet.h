#ifndef GRAPHICSCARDSET_H
#define GRAPHICSCARDSET_H

#include "GraphicsCard.h"
#include <stdlib.h>

class GraphicsCardSet : public RequiredPart, public VisitablePart
{
public:

    /**
     * @brief GraphicsCardSet default constructor
     */
    GraphicsCardSet();

    /**
     * @brief GraphicsCardSet constructor
     * @param graphicsCards array of GraphicsCard
     * @param numberOfGraphicsCards number of elements in array of GraphicsCard
     */
    GraphicsCardSet(GraphicsCard* graphicsCards, int numberOfGraphicsCards);

    /**
     * @brief GraphicsCardSet copy constructor
     * @param graphicsCards instance of the GraphicsCardSet to perform a deep copy on
     */
    GraphicsCardSet(const GraphicsCardSet &graphicsCards);

    /**
     * @brief ~GraphicsCardSet destructor
     */
    virtual ~GraphicsCardSet();

    /**
     * @brief getPartInformation constructs the part information for the GraphicsCardSet class
     * @return returns the part information for the GraphicsCardSet class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief getGraphicsCards retrieves an array of GraphicsCard
     * @return an array of GraphicsCard
     */
    GraphicsCard* getGraphicsCards() const;

    /**
     * @brief getNumberOfGraphicsCards retrieves number of elements in array of GraphicsCard
     * @return the number of elements in the GraphicsCard array
     */
    int getNumberOfGraphicsCards() const;

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

private:
    GraphicsCard* m_graphicsCards;
    int m_numberOfGraphicsCards;
};

#endif // GRAPHICSCARDSET_H
