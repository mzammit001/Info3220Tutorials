#include "date.h"


namespace Week4 {
std::string Date::dateAsString() const {

    char *buf = static_cast<char *>(alloca(11));
    snprintf(buf, 11, "%02d/%02d/%04d", m_day, m_month, m_year);

   return std::string(buf);
}
}
