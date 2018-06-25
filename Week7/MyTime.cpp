#include "MyTime.h"

namespace Week07 {
    Time::Time(int hours, int minutes, int seconds) {
        m_seconds = (hours * 3600) + (minutes * 60) + seconds;
    }

    Time::~Time() {}

    Time::Time(const Time &time) {
        m_seconds = time.m_seconds;
    }

    Time& Time::operator=(const Time &time) {
        if (this != &time) {
            this->m_seconds = time.m_seconds;
        }

        return *this;
    }

    Time Time::operator+(const Time &time) const {
        Time t(*this);
        t.m_seconds += time.m_seconds;
        return t;
    }

    Time Time::operator-(const Time &time) const {
        Time t(*this);
        t.m_seconds -= time.m_seconds;
        return t;
    }

    bool Time::operator==(const Time &time) const {
        return this->m_seconds == time.m_seconds;
    }

    bool Time::operator!=(const Time &time) const {
        return this->m_seconds != time.m_seconds;
    }

    bool Time::operator<(const Time &time) const {
        return this->m_seconds < time.m_seconds;
    }

    bool Time::operator>(const Time &time) const {
        return this->m_seconds > time.m_seconds;
    }

    bool Time::operator<=(const Time &time) const {
        return this->m_seconds <= time.m_seconds;
    }

    bool Time::operator>=(const Time &time) const {
        return this->m_seconds >= time.m_seconds;
    }

    double Time::numberOfHours() const {
        return static_cast<double>(m_seconds) / 3600;
    }

    double Time::numberOfMinutes() const {
        return static_cast<double>(m_seconds) / 60;
    }

    int Time::numberOfSeconds() const {
        return m_seconds;
    }

    std::string Time::getTimeAsString() const {
        char ctimestr[9];

        snprintf(ctimestr, sizeof(ctimestr), "%02d:%02d:%02d",
                 static_cast<int>(m_seconds / 3600),
                 static_cast<int>((m_seconds % 3600) / 60),
                 static_cast<int>(m_seconds % 60));

        return std::string(ctimestr);
    }

    Time::Time() : m_seconds(0) {        
    }

    Time operator+(const Time& lhs, int numberOfSeconds) {
        Time t(lhs);
        t.m_seconds += numberOfSeconds;
        return t;
    }
}
