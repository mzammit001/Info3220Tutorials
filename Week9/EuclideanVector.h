#ifndef EUCLIDEANVECTOR_H
#define EUCLIDEANVECTOR_H

#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>

#include "VectorException.h"

namespace Week9
{

class EuclideanVector {

public:

    /**
     * @brief EuclideanVector constructor which allocates the number of dimensions of the Euclidean vector
     * @param size number of dimensions
     */
    EuclideanVector(size_t size);

    /**
     * @brief EuclideanVector constructor which allocates the number of dimensions of the vector
     * along with a values for each dimensions of the Euclidean vector
     * @param vector
     */
    EuclideanVector(const std::vector<double> &vector);

    /**
     * @brief EuclideanVector copy constructor of the vector which creates a new vector with the
     * same values as those stored in a previously created Euclidean vector
     * @param vector an existing euclidean vector
     */
    EuclideanVector(const EuclideanVector &vector);

    ~EuclideanVector();

    /**
     * @brief operator = assignment operator
     * @param vector the vector which will be assigned from
     * @throws if the current vector and the assignment vector are not equal throws a
     * VectorAssignmentException with the message Incompatible Vector Sizes and the state
     * should not change
     * @return a reference to the newly assigned vector
     */
    EuclideanVector& operator=(const EuclideanVector &vector);

    /**
     * @brief size returns the number of dimensions of the vector
     * @return the number of dimensions of the vector
     */
    size_t size() const;

    /**
     * @brief operator == equality operator
     * @param vector the vector to compare with
     * @return if item v1[i] == v2[i] for all i where equality is defined as
     * values which are with 0.01 of one another than return true otherwise false
     *
     */
    bool operator==(const EuclideanVector &vector) const;

    /**
     * @brief operator == inequality operator
     * @param vector the vector to compare with
     * @return if item v1[i] == v2[i] for all i where equality is defined as
     * values which are with 0.01 of one another than return false otherwise true
     *
     */
    bool operator!=(const EuclideanVector &vector) const;

    /**
     * @brief length calculates the length of a vector
     * @return the length of the vector
     */
    double length() const;

    /**
     * @brief dotProduct calculates the dot product of the vector compared to another vector
     * @param vector a comparison vector
     * @throws if the vectors sizes are not equal than method will throw a VectorArithmeticException
     * with the message "Vectors are not the same size"
     * @return the dot producot of this vector and another vector
     */
    double dotProduct(const EuclideanVector &vector) const;

    /**
     * @brief unitVector calculates the unit vector
     * @return the unitVector
     */
    EuclideanVector unitVector() const;

    /**
     * @brief operator + adds two vectors together
     * @param vector the second vector to add to the current vector
     * @throws if the vectors sizes are not equal than method will throw a VectorArithmeticException
     * with the message "Vectors are not the same size"
     * @return the vector which is the result of adding this vector with the second vector
     */
    EuclideanVector operator+(const EuclideanVector &vector) const;

    /**
     * @brief operator - subtract two vectors away from one another
     * @param vector the second vector to subtract away from the current vector
     * @throws if the vectors sizes are not equal than method will throw a VectorArithmeticException
     * with the message "Vectors are not the same size"
     * @return the vector which is the result of subtracting this vector away from the second vector
     */
    EuclideanVector operator-(const EuclideanVector &vector) const;

    /**
     * @brief operator += add a second vector to this vector
     * @param vector the second vector to add to the current vector
     * @throws if the vectors sizes are not equal than method will throw a VectorArithmeticException
     * with the message "Vectors are not the same size"
     * @return a reference to the current vector
     */
    EuclideanVector& operator+=(const EuclideanVector &vector);

    /**
     * @brief operator -= subtract a second vector away from this vector
     * @param vector the second vector to subtract away from the current vector
     * @throws if the vectors sizes are not equal than method will throw a VectorArithmeticException
     * with the message "Vectors are not the same size"
     * @return a reference to the current vector
     */
    EuclideanVector& operator-=(const EuclideanVector &vector);

    /**
     * @brief operator *= scaling operator
     * @param scalingValue value to scale of values in the vector by
     * @return a vector where each value has been multiplied by the scaling value
     */
    EuclideanVector& operator*=(double scalingValue);

    /**
     * @brief operator /= scaling operator
     * @param scalingValue value to scale of values in the vector by
     * @return a vector where each value has been divided by the scaling value
     */
    EuclideanVector& operator/=(double scalingValue);

    /**
     * @brief operator [] access operator
     * @param index of the value to access
     * @throws if the index is outside the range of the vector than throw
     * VectorIndexOutOfBoundsException with the message
     * "Index is greater than or equal to the allocated size"
     * @return the value at index
     */
    double& operator[](size_t index);

    /**
     * @brief operator [] access operator
     * @param index of the value to access
     * @throws if the index is outside the range of the vector than throw
     * VectorIndexOutOfBoundsException with the message
     * "Index is greater than or equal to the allocated size"
     * @return the value at index
     */
    const double& operator[](size_t index) const;

private:
    /**
     * @brief EuclideanVector private default constructor
     */
    EuclideanVector();

    double *m_data;
    size_t m_size;

};

}

#endif // EUCLIDEANVECTOR_H
