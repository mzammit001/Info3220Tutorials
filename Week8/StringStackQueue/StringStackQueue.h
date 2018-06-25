#ifndef STRINGSTACKQUEUE_H
#define STRINGSTACKQUEUE_H
#include "StringStack.h"
#include "StringQueue.h"
#include <deque>

class StringStackQueue : public StringStack, public StringQueue {
public:
    StringStackQueue() : StringStack(), StringQueue(), m_data() {}
    StringStackQueue(const StringStackQueue& other);
    virtual ~StringStackQueue() {}

    /**
    * @brief empty checks if the stack is empty
    * @return true if empty otherwise false
    */
    virtual bool empty() const;

    /**
    * @brief size checks the number of items in the stack
    * @return the number of items in the stack
    */
    virtual size_t size() const;

    /**
    * @brief peek is the item at the top of the stack
    * this method should not alter the state of the stack
    * @return a reference to the top of the stack
    */
    virtual const std::string& peek() const;

    /**
    * @brief push adds an new item to the top of the stack
    * @param string the new item to add to the top of the stack
    */
    virtual void push(const std::string &string);

    /**
    * @brief pop removes the item on the top of the stack
    * if the stack is empty return an empty string
    * @return the item that was previously on the top of the stack
    */
    virtual std::string pop();

    /**
    * @brief front is the item at the front of the queue
    * this method should not alter the state of the queue
    * @return a reference to the first item in the queue
    */
    virtual const std::string& front() const;

    /**
    * @brief enqueue adds a item to the end of the queue
    * @param string the item to add at the end of the queue
    */
    virtual void enqueue(const std::string &string);

    /**
    * @brief deqeue deletes an item from the front of the queue
    * if the deqeue is empty return an empty string
    * @return the first item from the queue before deleted
    */
    virtual std::string deqeue();

    /**
    * @brief operator = overwrites the current queue with a new queue
    * @param queue the new queue
    * @return a reference to the current queue
    */
    virtual StringQueue& operator=(const StringQueue &queue);
    /**
    * @brief operator = overwrites the current stack with a new stack
    * @param stack the new stack
    * @return a reference to the current stack
    */
    virtual StringStack& operator=(const StringStack &stack);

    virtual StringStackQueue& operator=(const StringStackQueue &ssqueue);

    std::string& operator[](std::size_t idx);
    const std::string& operator[](std::size_t idx) const;

private:
    std::deque<std::string> m_data;

};

#endif // STRINGSTACKQUEUE_H
