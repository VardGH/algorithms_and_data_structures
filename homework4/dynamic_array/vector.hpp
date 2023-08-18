#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <initializer_list>

namespace container {

template <typename T>
class vector {
public:
    vector(); // Default constructor
    explicit vector(int size); // Constructor with parameter

    vector(const vector& other); // Copy constructor
    vector& operator=(const vector& other); // Copy assignment operator

    vector(vector&& other); // Move constructor
    vector& operator=(vector&& other); // Move assignment operator

    ~vector(); // Destructor

public:
    int get_size() const;
    int get_capacity() const;

    void push_back(const T& value); // Adds an element at the end
    void insert(const int pos, const T& value); // Inserts an element at a specific position
    void insert(const int pos, const T& value, int count); // Inserts multiple elements at a position
    void insert(const int pos, const vector<T>& other); // Inserts the elements of another vector at a position
    void insert(const int pos, std::initializer_list<T> l); // Inserts elements from an initializer list
    void pop_back(); // Removes the last element
    void remove(const int pos); // Removes an element at a specific position
    void remove(const int pos, int count); // Removes multiple elements starting from a position
    void shrink_to_fit(); // Reduces the capacity to match the size
    void clear(); // Removes all elements
    bool is_empty(); // Checks if the vector is empty
    void resize(const int count, const T& value = 0); // Resizes the vector to a specified size
    T& operator[](const int pos); // Access element at a specific position
    const T& operator[](const int pos) const; // Const version of the above

private:
    T* m_arr; // Pointer to the dynamic array
    int m_size; // Current number of elements in the vector
    int m_cap; // Current capacity of the vector
};

// Non-member functions for comparison operators
template <typename T>
bool operator==(const vector<T>& lhs, const vector<T>& rhs);

template <typename T>
bool operator!=(const vector<T>& lhs, const vector<T>& rhs);

template <typename T>
bool operator<(const vector<T>& lhs, const vector<T>& rhs);

template <typename T>
bool operator<=(const vector<T>& lhs, const vector<T>& rhs);

template <typename T>
bool operator>(const vector<T>& lhs, const vector<T>& rhs);

template <typename T>
bool operator>=(const vector<T>& lhs, const vector<T>& rhs);

} // namespace container

#include "vector_impl.hpp"

#endif // VECTOR_HPP