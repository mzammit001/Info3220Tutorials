#include "EuclideanVector.h"

namespace Week9 {
    EuclideanVector::EuclideanVector(size_t size)
    {
        m_data = new double[size]();
        m_size = size;
    }

    EuclideanVector::EuclideanVector(const std::vector<double>& vector)
    {
        m_data = new double[vector.size()];
        m_size = vector.size();
       
        for (size_t i = 0; i < vector.size(); ++i) {
            m_data[i] = vector[i];
        }
    }

    EuclideanVector::EuclideanVector(const EuclideanVector & vector)
    {
        m_data = new double[vector.size()];
        m_size = vector.size();

        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = vector[i];
        }
    }

    EuclideanVector::~EuclideanVector()
    {
        delete[] m_data;
    }

    EuclideanVector & EuclideanVector::operator=(const EuclideanVector & vector)
    {
        if (*this != vector) {
            if (m_size != vector.size()) {
                throw VectorAssignmentException("Incompatible Vector Sizes");
            }

            for (size_t i = 0; i < m_size; ++i) {
                m_data[i] = vector[i];
            }
        }

        return *this;
    }

    size_t EuclideanVector::size() const
    {
        return m_size;
    }

    bool EuclideanVector::operator==(const EuclideanVector & vector) const
    {
        if (m_size != vector.size()) {
            return false;
        }

        for (size_t i = 0; i < m_size; ++i) {
            if (std::abs(m_data[i] - vector[i]) > 0.01)
                return false;
        }

        return true;
    }

    bool EuclideanVector::operator!=(const EuclideanVector & vector) const
    {
        return !(*this == vector);
    }

    double EuclideanVector::length() const
    {
        // because why not
        return sqrt(this->dotProduct(*this));
    }

    double EuclideanVector::dotProduct(const EuclideanVector & vector) const
    {
        if (m_size != vector.size())
            throw VectorArithmeticException("Vectors are not the same size");

        double dot = 0.0;

        // a[0] * b[0] + ... + a[n-1] * b[n-1]
        for (size_t i = 0; i < m_size; ++i) {
            dot += (m_data[i] * vector[i]);
        }

        return dot;
    }

    EuclideanVector EuclideanVector::unitVector() const
    {
        double len = length();
        // already a unit vector
        if (len == 1.0)
            return EuclideanVector(*this);

        EuclideanVector v(*this);
        v /= len;

        return v;
    }

    EuclideanVector EuclideanVector::operator+(const EuclideanVector & vector) const
    {
        if (m_size != vector.size())
            throw VectorArithmeticException("Vectors are not the same size");

        EuclideanVector v(*this);
        v += vector;
        
        return v;
    }

    EuclideanVector EuclideanVector::operator-(const EuclideanVector & vector) const
    {
        if (m_size != vector.size())
            throw VectorArithmeticException("Vectors are not the same size");

        EuclideanVector v(*this);
        v -= vector;

        return v;
    }

    EuclideanVector & EuclideanVector::operator+=(const EuclideanVector & vector)
    {
        if (m_size != vector.size())
            throw VectorArithmeticException("Vectors are not the same size");

        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] += vector[i];
        }

        return *this;
    }

    EuclideanVector & EuclideanVector::operator-=(const EuclideanVector & vector)
    {
        if (m_size != vector.size())
            throw VectorArithmeticException("Vectors are not the same size");

        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] -= vector[i];
        }

        return *this;
    }

    EuclideanVector & EuclideanVector::operator*=(double scalingValue)
    {
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] *= scalingValue;
        }

        return *this;
    }

    EuclideanVector & EuclideanVector::operator/=(double scalingValue)
    {
        if (scalingValue == 0.0) {
            throw VectorArithmeticException("Divide by zero");
        }

        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] /= scalingValue;
        }

        return *this;
    }

    double & EuclideanVector::operator[](size_t index)
    {
        if (index >= m_size)
            throw VectorIndexOutOfBoundsException("Index is greater than or equal to the allocated size");

        return m_data[index];
    }

    const double & EuclideanVector::operator[](size_t index) const
    {
        if (index >= m_size)
            throw VectorIndexOutOfBoundsException("Index is greater than or equal to the allocated size");

        return m_data[index];
    }

    EuclideanVector::EuclideanVector()
    {
    }
}