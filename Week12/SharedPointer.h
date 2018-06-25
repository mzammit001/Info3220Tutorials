#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H

#include <stdexcept>
#include <vector>
#include <algorithm>

namespace week12
{
    struct SharedPointerControlBlock {
        SharedPointerControlBlock() : refCount(0) {}
        size_t refCount;
    };

    template <class T>
    class SharedPointer
    {
    public:

        /**
         * @brief SharedPointer creates an new instance of an empty shared pointer
         */
        SharedPointer()
            : m_ptr(nullptr), m_block(nullptr) {}

        /**
         * @brief SharedPointer creates an new instance of a shared pointer storing item
         * @param item the item to store in a newly created const reference
         */
        SharedPointer(const T& item)
            : m_ptr(new T(item)), m_block(nullptr) {
            addRef();
        }

        /**
         * @brief SharedPointer creates a new instance of a shared pointer storing the raw pointer
         * @param rawPointer the pointer to store in the newly created shared pointer
         */
        SharedPointer(T* rawPointer)
            : m_ptr(nullptr), m_block(nullptr)
        {
            // noop
            if (rawPointer == nullptr)
                return;

            m_ptr = new T(*rawPointer);
            addRef();
        }

        /**
         * @brief SharedPointer creates a new instance of a shared pointer based on the construction of an existing shared pointers
         * @param sharedPointer the shared pointer for which the new shared pointer will be based on
         */
        SharedPointer(const SharedPointer &sharedPointer)
            : m_ptr(nullptr), m_block(nullptr)
        {
            m_ptr = sharedPointer.m_ptr;
            m_block = sharedPointer.m_block;

            if (get() != nullptr) {
                addRef();
            }
        }

        /**
         * @brief ~SharedPointer destructor for the shared pointer
         */
        ~SharedPointer() {
            if (get() == nullptr)
                return;

            reset();
        }

        /**
         * @brief get retrieves the raw pointer stored in the shared pointer
         * @return the raw pointer stored in the shared pointer
         */
        T* get() const {
            return m_ptr;
        }

        /**
         * @brief reset returns the shared pointer to a state as if it had been default constructed
         */
        void reset() {
            delRef();

            if (refCount() == 0) {
                delete m_block;
                delete m_ptr;
            }

            m_ptr = nullptr;
            m_block = nullptr;
        }

        /**
         * @brief unique checks if the shared pointer object does not share ownership over its pointer with other shared_ptr objects. Empty pointers are not unique (as they do not own any pointers)
         * @return true if the shared pointer is unique otherwise false
         */
        bool unique() const {
            if (refCount() != 1)
                return false;

            return true;
        }

        /**
         * @brief operator = copy assignments add the object as a shared owner of other's assets and the counter is then increased by 1
         * @param sharedPointer which is assignment to this pointer
         * @return a reference to this pointer
         */
        SharedPointer& operator=(const SharedPointer &sharedPointer) {
            if (this != std::addressof(sharedPointer)) {
                // we might be the only one holding a reference, so cleanup if necessary
                if (get() != nullptr) {
                    reset();
                }

                m_ptr = sharedPointer.m_ptr;
                m_block = sharedPointer.m_block;

                if (get() != nullptr) {
                    addRef();
                }
            }

            return *this;
        }

        /**
         * @brief operator * recovers a reference to the shared pointer
         * @return a reference to the shared pointer
         */
        T& operator*() const {
            return *get();
        }

        /**
         * @brief operator -> recovers the pointer to the object stored in the shared pointer
         * @return the pointer to the object stored in the shared pointer
         */
        T* operator->() const {
            return get();
        }

        /**
         * @brief operator bool return true iff the pointer is not null
         */
        operator bool() const {
            return get() != nullptr;
        }

    private:
        size_t refCount() const {
            if (m_block != nullptr)
                return m_block->refCount;

            return 0;
        }

        void addRef() {
            if (m_block == nullptr) {
                m_block = new SharedPointerControlBlock();
            }

            m_block->refCount++;
        }

        void delRef() {
            if (m_block == nullptr)
                return;

            m_block->refCount--;

            if (refCount() == 0)
                reset();
        }

        T* m_ptr;
        SharedPointerControlBlock *m_block;
    };
}

#endif // SHAREDPOINTER_H
