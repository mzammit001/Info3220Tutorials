
#include <iostream>
#include "StringStackQueue.h"

bool constructionTest()
{
    StringStackQueue s;
    return s.empty() && 0 == s.size();
}

bool addAsIfStackTest()
{
    StringStackQueue s;
    s.push("World");
    s.push("Hello");
    return !s.empty() && 2 == s.size();
}

bool peekTest()
{
    StringStackQueue s;
    s.push("World");
    s.push("Hello");

    return "Hello" == s.peek() && 2 == s.size();
}

bool popTest()
{
    StringStackQueue s;
    s.push("World");
    s.push("Hello");

    std::string first = s.pop();
    std::string second = s.pop();

    return "Hello" == first && "World" == second;
}

bool popAllTest()
{
    StringStackQueue s;
    s.push("World");
    s.push("Hello");

    std::string first = s.pop();
    std::string second = s.pop();
    std::string third =  s.pop();

    return "Hello" == first && "World" == second && third.empty();
}

bool addAsIfQueueTest()
{
    StringStackQueue s;
    s.enqueue("Hello");
    s.enqueue("World");
    return !s.empty() && 2 == s.size();
}

bool frontTest()
{
    StringStackQueue s;
    s.enqueue("Hello");
    s.enqueue("World");

    std::string first = s.front();

    return "Hello" == first && 2 == s.size();
}

bool dequeTest()
{
    StringStackQueue s;
    s.enqueue("Hello");
    s.enqueue("World");

    std::string first = s.deqeue();
    std::string second = s.deqeue();

    return "Hello" == first && "World" == second;
}

bool dequeAllTest()
{
    StringStackQueue s;
    s.enqueue("Hello");
    s.enqueue("World");

    std::string first = s.deqeue();
    std::string second = s.deqeue();
    std::string third = s.deqeue();

    return "Hello" == first && "World" == second && third.empty();
}

bool assignmentOperatorTest()
{
    StringQueue *queue = new StringStackQueue();
    queue->enqueue("Hello");
    queue->enqueue("World");

    StringStack *stack = new StringStackQueue();
    stack->push("World");
    stack->push("Hello");

    StringStackQueue both;
    both = *queue;

    if (2 == both.size() && "Hello" == both.deqeue() && "World" == both.deqeue() && both.empty())
    {
        both = *stack;
        if (2 == both.size() && "Hello" == both.pop() && "World" == both.pop() && both.empty())
        {
            return (2 == queue->size() && 2 == stack->size());
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main(int argc, char *argv[])
{
    int numberOfTestsFailed = 0;
    if (!constructionTest())
    {
        numberOfTestsFailed++;
    }
    if (!addAsIfStackTest())
    {
        numberOfTestsFailed++;
    }
    if (!peekTest())
    {
        numberOfTestsFailed++;
    }
    if (!popTest())
    {
        numberOfTestsFailed++;
    }
    if (!popAllTest())
    {
        numberOfTestsFailed++;
    }
    if (!addAsIfQueueTest())
    {
        numberOfTestsFailed++;
    }
    if (!frontTest())
    {
        numberOfTestsFailed++;
    }
    if (!dequeTest())
    {
        numberOfTestsFailed++;
    }
    if (!dequeAllTest())
    {
        numberOfTestsFailed++;
    }
    if (!assignmentOperatorTest())
    {
        numberOfTestsFailed++;
    }
    if (0 == numberOfTestsFailed)
    {
        std::cout << "All Tests Passed!" << std::endl;
    }
    else
    {
        std::cout << numberOfTestsFailed << " Tests Failed" << std::endl;
    }
}
