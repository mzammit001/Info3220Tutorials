#include "VisitablePart.h"

VisitablePart::VisitablePart()
    : Part()
{

}

VisitablePart::VisitablePart(const std::string &name)
    : Part(name)
{

}

VisitablePart::VisitablePart(const VisitablePart &part)
    : Part(part)
{

}

VisitablePart::~VisitablePart()
{

}
