#ifndef MYTIME_H
#define MYTIME_H

#include <string>
#include <cstring>

namespace Week07 {
    class Time
    {
    public:
        Time(int hours, int minutes, int seconds);
        ~Time();

        Time(const Time &time);
        Time& operator=(const Time &time);
        Time operator+(const Time &time) const;
        Time operator-(const Time &time) const;
        bool operator==(const Time &time) const;
        bool operator!=(const Time &time) const;
        bool operator<(const Time &time) const;
        bool operator>(const Time &time) const;
        bool operator<=(const Time &time) const;
        bool operator>=(const Time &time) const;

        friend Time operator+(const Time& lhs, int numberOfSeconds);
        
        double numberOfHours() const;
        double numberOfMinutes() const;
        int numberOfSeconds() const;

        std::string getTimeAsString() const;

    private:
        Time();
        int m_seconds;
    };

    Time operator+(const Time& lhs, int numberOfSeconds);
}

#endif