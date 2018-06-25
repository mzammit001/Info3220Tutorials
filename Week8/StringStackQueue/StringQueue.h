#ifndef STRINGQUEUE_H
#define STRINGQUEUE_H

#include<string>

class StringQueue
{
public:
    virtual ~StringQueue(){}

    /**
     * @brief empty checks if the queue is empty
     * @return true if empty otherwise false
     */
    virtual bool empty() const = 0;

    /**
     * @brief size checks the number of items in the queue
     * @return the number of items in the queue
     */
    virtual size_t size() const = 0;

    /**
     * @brief front is the item at the front of the queue
     * this method should not alter the state of the queue
     * @return a reference to the first item in the queue
     */
    virtual const std::string& front() const = 0;

    /**
     * @brief enqueue adds a item to the end of the queue
     * @param string the item to add at the end of the queue
     */
    virtual void enqueue(const std::string &string) = 0;

    /**
     * @brief deqeue deletes an item from the front of the queue
     * if the deqeue is empty return an empty string
     * @return the first item from the queue before deleted
     */
    virtual std::string deqeue() = 0;

    /**
     * @brief operator = overwrites the current queue with a new queue
     * @param queue the new queue
     * @return a reference to the current queue
     */
    virtual StringQueue& operator=(const StringQueue &queue) = 0;
};

#endif // STRINGQUEUE_H
