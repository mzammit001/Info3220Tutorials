#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include <string>
#include <ctime>

namespace Week4
{
class Person
{
public:
    Person(std::string firstName,
        std::string surname,
        Date dateOfBirth)
        : m_firstName(firstName), m_surname(surname), m_dateOfBirth(dateOfBirth) {}

    virtual ~Person() {}

    void changeFirstName(std::string firstName) {
        m_firstName = firstName;
    }
    std::string getFirstName() {
        return m_firstName;
    }

    void changeSurname(std::string surname) {
        m_surname = surname;
    }
    std::string getSurname() {
        return m_surname;
    }

    int getYearOfBirth() {
        return m_dateOfBirth.getYear();
    }
    int getCurrentAge() {
        time_t now = time(nullptr);
        tm *local = localtime(&now);
        auto year = local->tm_year + 1900;
        return year - m_dateOfBirth.getYear();
    }

    virtual std::string getRecord() const = 0;

protected:
    std::string m_firstName;
    std::string m_surname;
    Date m_dateOfBirth;
};

} // namespace  Week4
#endif
