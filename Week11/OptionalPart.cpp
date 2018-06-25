#include "OptionalPart.h"

OptionalPart::OptionalPart() : Part(std::string())
{

}

OptionalPart::OptionalPart(const std::string &name) : Part(name)
{

}

OptionalPart::OptionalPart(const OptionalPart &part) : Part(part)
{

}

OptionalPart::~OptionalPart()
{

}
