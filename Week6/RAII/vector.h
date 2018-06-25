#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <stdexcept>
#include <memory>

/**
 * @brief The Vector class is list of floats representing a mathematical vector
 */
class Vector
{
public:
    /**
     * @brief Constructs the vector allocating space for size number of floats and initialize all values to zero
     * @param size
     */
    Vector(unsigned int size);

    /**
     * @brief copy constructor that replaces default shallow copy with a deep copy
     * @param other
     */
    Vector(const Vector& other);

    /**
     * @brief the assignment operator
     * @param other
     * @return
     */
    Vector& operator=(const Vector& other);

    /**
     * @brief calculates the euclidean length of the vector using L = sqrt(a*a + b*b + c*c ...) for all elements in the vector
     * @return the euclidean length of the vector
     */
    float length() const;

    /**
     * @brief operator + adds two vectors together a3 = a1+a2, b3 = b1 + b2 ... for all elements in the two vectors. If the vectors are of
     * different dimensions (i.e. the sizes are different) then this throws std::range_error
     * @param other vector to add
     * @return the vector of which each element is the sum of the two parent elements
     */
    Vector operator+(const Vector &other) const;

    /**
     * @brief operator [] returns a reference to the float at the provided index. Throws std::out_of_range if index is >= size()
     * @param index
     * @return
     */
    float& operator[](unsigned int index);

    /**
     * @brief
     * @return the number of elements in the vector
     */
    unsigned int size() const;

    ~Vector();

private:
    unsigned int m_size;
    float* m_elements;
};

#endif // VECTOR_H
