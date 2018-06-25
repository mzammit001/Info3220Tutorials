#include "StringStackQueue.h"

StringStackQueue::StringStackQueue(const StringStackQueue & other) : StringStack(), StringQueue(), m_data(other.m_data)
{
}

bool StringStackQueue::empty() const
{
    return m_data.empty();
}

size_t StringStackQueue::size() const
{
    return m_data.size();
}

const std::string & StringStackQueue::peek() const
{
    return m_data[0];
}

void StringStackQueue::push(const std::string & string)
{
    m_data.insert(m_data.begin(), string);
}

std::string StringStackQueue::pop()
{
    if (m_data.size() == 0) {
        return std::string();
    }

    std::string s = m_data.front();
    m_data.pop_front();

    return s;
}

const std::string & StringStackQueue::front() const
{
    return m_data.front();
}

void StringStackQueue::enqueue(const std::string & string)
{
    m_data.insert(m_data.end(), string);
}

std::string StringStackQueue::deqeue()
{
    if (m_data.size() == 0)
        return std::string();
    
    std::string s = m_data.front();
    m_data.pop_front();
    return s;
}

StringStack & StringStackQueue::operator=(const StringStack & stack)
{
    const StringStackQueue &ssqueue = static_cast<const StringStackQueue &>(stack);
    for (size_t i = 0; i < ssqueue.size(); ++i) {
        m_data.push_back(ssqueue[i]);
    }
    return static_cast<StringStack&>(*this);
}

StringStackQueue & StringStackQueue::operator=(const StringStackQueue & ssqueue)
{
    for (size_t i = 0; i < ssqueue.size(); ++i) {
        m_data.push_back(ssqueue[i]);
    }
    return *this;
}

StringQueue & StringStackQueue::operator=(const StringQueue & queue)
{
    const StringStackQueue &ssqueue = static_cast<const StringStackQueue &>(queue);
    for (size_t i = 0; i < ssqueue.size(); ++i) {
        m_data.push_back(ssqueue[i]);
    }
    return static_cast<StringQueue&>(*this);
}

std::string & StringStackQueue::operator[](std::size_t idx)
{
    return m_data[idx];
}

const std::string & StringStackQueue::operator[](std::size_t idx) const
{
    return m_data[idx];
}
