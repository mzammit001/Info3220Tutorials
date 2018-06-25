#ifndef DATE_H
#define DATE_H

#include <sstream>
#include <string>
#include <cstring>
#include <memory>

namespace Week4
{
class Date
{
public:
    Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}
    ~Date() {}

    int getYear() const {
        return m_year;
    }
    int getMonth() const {
        return m_month;
    }
    int getDay() const {
        return m_day;
    }

    std::string dateAsString() const;
private:
    int m_day;
    int m_month;
    int m_year;
};
} // namespace Week4

#endif
