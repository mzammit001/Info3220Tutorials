#ifndef STACKQUEUE_H
#define STACKQUEUE_H
#include "GenericStack.h"
#include "GenericQueue.h"
#include <deque>

namespace Week10 {
    template <class T>
    class StackQueue : public Stack<T>, public Queue<T> {
    public:
        StackQueue() : Stack<T>(), Queue<T>(), m_data() {}
        StackQueue<T>(const StackQueue<T>& other) : Stack<T>(), Queue<T>(), m_data(other.m_data) {}
        virtual ~StackQueue() {}

        /**
        * @brief empty checks if the stack is empty
        * @return true if empty otherwise false
        */
        virtual bool empty() const {
            return m_data.empty();
        }

        /**
        * @brief size checks the number of items in the stack
        * @return the number of items in the stack
        */
        virtual size_t size() const {
            return m_data.size();
        }

        /**
        * @brief peek is the item at the top of the stack
        * this method should not alter the state of the stack
        * @return a reference to the top of the stack
        */
        virtual const T& peek() const {
            return m_data[0];
        }

        /**
        * @brief push adds an new item to the top of the stack
        * @param string the new item to add to the top of the stack
        */
        virtual void push(const T &data) {
            m_data.insert(m_data.begin(), data);
        }

        /**
        * @brief pop removes the item on the top of the stack
        * if the stack is empty return an empty string
        * @return the item that was previously on the top of the stack
        */
        virtual T pop() {
            if (m_data.size() == 0) {
                return T();
            }

            T s = m_data.front();
            m_data.pop_front();

            return s;
        }

        /**
        * @brief front is the item at the front of the queue
        * this method should not alter the state of the queue
        * @return a reference to the first item in the queue
        */
        virtual const T& front() const {
            return m_data.front();
        }

        /**
        * @brief enqueue adds a item to the end of the queue
        * @param string the item to add at the end of the queue
        */
        virtual void enqueue(const T &data) {
            m_data.insert(m_data.end(), data);
        }

        /**
        * @brief deqeue deletes an item from the front of the queue
        * if the deqeue is empty return an empty string
        * @return the first item from the queue before deleted
        */
        virtual T deqeue() {
            if (m_data.size() == 0)
                return T();

            T s = m_data.front();
            m_data.pop_front();
            return s;
        }

        /**
        * @brief operator = overwrites the current queue with a new queue
        * @param queue the new queue
        * @return a reference to the current queue
        */
        virtual Queue<T>& operator=(const Queue<T> &queue) {
            const StackQueue<T> &ssqueue = static_cast<const StackQueue<T> &>(queue);
            for (size_t i = 0; i < ssqueue.size(); ++i) {
                m_data.push_back(ssqueue[i]);
            }
            return static_cast<Queue<T>&>(*this);
        }
        /**
        * @brief operator = overwrites the current stack with a new stack
        * @param stack the new stack
        * @return a reference to the current stack
        */
        virtual Stack<T>& operator=(const Stack<T> &stack) {
            const StackQueue<T> &ssqueue = static_cast<const StackQueue<T> &>(stack);
            for (size_t i = 0; i < ssqueue.size(); ++i) {
                m_data.push_back(ssqueue[i]);
            }
            return static_cast<Stack<T>&>(*this);
        }

        virtual StackQueue<T>& operator=(const StackQueue<T> &ssqueue) {
            for (size_t i = 0; i < ssqueue.size(); ++i) {
                m_data.push_back(ssqueue[i]);
            }
            return *this;
        }

        T& operator[](std::size_t idx) {
            return m_data[idx];
        }

        const T& operator[](std::size_t idx) const {
            return m_data[idx];
        }

    private:
        std::deque<T> m_data;
    };
}

#endif // STACKQUEUE_H
