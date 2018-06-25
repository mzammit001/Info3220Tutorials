#ifndef CASE_H
#define CASE_H

#include "Part.h"

/**
 * @brief The CaseType enum all types of Case's permitted in current implementation
 */
enum CaseType
{
    Chassis,
    Tower,
    SystemUnit,
    Cabinet,
    BaseUnit
};

class Case : public Part
{
public:

    /**
     * @brief Case deafult constructor
     */
    Case();

    /**
     * @brief Case constructor
     * @param name description of part
     * @param caseType the case type
     */
    Case(const std::string &name, CaseType caseType);

    /**
     * @brief Case copy constructor
     * @param computerCase a Case object
     */
    Case(const Case &computerCase);

    /**
     * @brief ~Case destructor
     */
    virtual ~Case();

    /**
     * @brief getPartInformation constructs the part information for the Case class
     * @return returns the part information for the Case class as a std::string
     */
    virtual std::string getPartInformation() const;

private:
    CaseType m_caseType;

    // Part interface
public:
    Part *clone() const;
};

#endif // CASE_H
