#ifndef STRINGSTACK_H
#define STRINGSTACK_H

#include<string>

class StringStack
{
public:
    virtual ~StringStack(){}

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
    virtual const std::string& peek() const = 0;

    /**
     * @brief push adds an new item to the top of the stack
     * @param string the new item to add to the top of the stack
     */
    virtual void push(const std::string &string) = 0;

    /**
     * @brief pop removes the item on the top of the stack
     * if the stack is empty return an empty string
     * @return the item that was previously on the top of the stack
     */
    virtual std::string pop() = 0;

    /**
     * @brief operator = overwrites the current stack with a new stack
     * @param stack the new stack
     * @return a reference to the current stack
     */
    virtual StringStack& operator=(const StringStack &stack) = 0;
};

#endif // STRINGSTACK_H
