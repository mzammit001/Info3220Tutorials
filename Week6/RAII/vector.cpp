#include "vector.h"

Vector::Vector(unsigned int size) {
    // calling the constructor will zero the heap memory
    m_elements = new float[size]();
    m_size = size;
}

Vector::Vector(const Vector& other) {
    // allocate m_elements
    this->m_elements = new float[other.m_size];
    // copy others m_elements to ours
    memcpy(this->m_elements, other.m_elements, sizeof(float) * other.m_size);
    // update our size
    this->m_size = other.m_size;
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        // cleanup first
        delete[] this->m_elements;
        // allocate m_elements
        this->m_elements = new float[other.m_size];
        // copy others m_elements to ours
        memcpy(this->m_elements, other.m_elements, sizeof(float) * other.m_size);
        // update our size
        this->m_size = other.m_size;
    }

    return *this;
}

float Vector::length() const {
    float length = 0.0f;

    for (int i = 0; i < m_size; ++i) {
        length += (m_elements[i] * m_elements[i]);
    }

    return sqrt(length);
}

Vector Vector::operator+(const Vector &other) const {
    if (m_size != other.m_size)
        throw std::range_error("sizes differ");
    
    Vector v(m_size);
    
    for (int i = 0; i < m_size; ++i) {
        v[i] = m_elements[i] + other.m_elements[i];
    }

    return v;
}

float& Vector::operator[](unsigned int index) {
    return m_elements[index];
}

unsigned int Vector::size() const {
    return m_size;
}

Vector::~Vector() {
    delete[] m_elements;
}

/*
 * If we used std::array instead of new, we won't have to worry about deleting the array in the destructor
 * since the std::array container will perform its own cleanup when the lifetime of the Vector instance is over
 * 
 */