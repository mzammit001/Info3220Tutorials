#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

namespace Week4
{
class Student : public Person
{
public:
    Student(const std::string &givenName, const std::string &surname,
            const Date &date, const std::string &degree) : Person(givenName, surname, date) {
        m_degree = new std::string(degree);
    }

    virtual ~Student() {
        delete m_degree;
    }

    virtual std::string getRecord() const {
        std::stringstream str;
        str << "Name: " << m_firstName << " " << m_surname << std::endl;
        str << "Date Of Birth: " << m_dateOfBirth.dateAsString() << std::endl;
        str << "Degree: " << *m_degree;

        m_recordAccessed++;
        return str.str();
    }

private:
    std::string* m_degree;
    mutable int m_recordAccessed;
};
} // namespace Week4

#endif
