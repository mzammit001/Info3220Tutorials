#ifndef GENERICQUEUE_H
#define GENERICQUEUE_H

namespace Week10
{
    template <class T>
    class Queue
    {
    public:
        virtual ~Queue(){}

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
        virtual const T& front() const = 0;

        /**
         * @brief enqueue adds a item to the end of the queue
         * @param item the item to add at the end of the queue
         */
        virtual void enqueue(const T &item) = 0;

        /**
         * @brief deqeue deletes an item from the front of the queue
         * if the deqeue is empty return a default constructed T
         * @return the first item from the queue before deleted
         */
        virtual T deqeue() = 0;

        /**
         * @brief operator = overwrites the current queue with a new queue
         * @param queue the new queue
         * @return a reference to the current queue
         */
        virtual Queue<T>& operator=(const Queue<T> &queue) = 0;
    };
}

#endif // GENERICQUEUE_H
