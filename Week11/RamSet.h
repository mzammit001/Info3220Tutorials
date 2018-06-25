#ifndef RAMSET_H
#define RAMSET_H

#include "Ram.h"
#include <stdlib.h>

class RamSet : public RequiredPart, public VisitablePart
{
public:

    /**
     * @brief RamSet default constructor
     */
    RamSet();

    /**
     * @brief RamSet constructor
     * @param ram array of Ram
     * @param numberOfRamSticks number of elements in array of Ram
     */
    RamSet(Ram* ram, int numberOfRamSticks);

    /**
     * @brief RamSet copy constructor
     * @param ramSet instance of the RamSet to perform a deep copy on
     */
    RamSet(const RamSet &ramSet);

    /**
     * @brief ~RamSet destructor
     */
    virtual ~RamSet();

    /**
     * @brief getPartInformation constructs the part information for the RamSet class
     * @return returns the part information for the RamSet class as a std::string
     */
    virtual std::string getPartInformation() const;

    /**
     * @brief getRamSticks retrieves an array of Ram
     * @return an array of Ram
     */
    Ram* getRamSticks() const;

    /**
     * @brief getNumberOfRamSticks retrieves number of elements in array of Ram
     * @return the number of elements in the Ram array
     */
    int getNumberOfRamSticks() const;

    /**
     * @brief accept this method permits a visitor to access to this class
     * and any classes which may inherit from it.
     * @param visitor the visitor instance which is permitted to access to this class
     */
    virtual void accept(Visitor* visitor);

private:
    Ram* m_ramSticks;
    int m_numberOfRamSticks;
};

#endif // RAMSET_H
