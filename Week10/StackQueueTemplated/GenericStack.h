#ifndef GENERICSTACK_H
#define GENERICSTACK_H

namespace Week10
{
    template <class T>
    class Stack
    {
    public:
        virtual ~Stack(){}

        /**
         * @brief empty checks if the stack is empty
         * @return true if empty otherwise false
         */
        virtual bool empty() const = 0;

        /**
         * @brief size checks the number of items in the stack
         * @return the number of items in the stack
         */
        virtual size_t size() const = 0;

        /**
         * @brief peek is the item at the top of the stack
         * this method should not alter the state of the stack
         * @return a reference to the top of the stack
         */
        virtual const T& peek() const = 0;

        /**
         * @brief push adds an new item to the top of the stack
         * @param item the new item to add to the top of the stack
         */
        virtual void push(const T &item) = 0;

        /**
         * @brief pop removes the item on the top of the stack
         * if the stack is empty return a default constructed T
         * @return the item that was previously on the top of the stack
         */
        virtual T pop() = 0;

        /**
         * @brief operator = overwrites the current stack with a new stack
         * @param stack the new stack
         * @return a reference to the current stack
         */
        virtual Stack<T>& operator=(const Stack<T> &stack) = 0;
    };
}

#endif // GENERICSTACK_H
