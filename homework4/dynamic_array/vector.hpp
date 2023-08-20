#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <initializer_list>

namespace container {

template <typename T>
class vector 
{
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

    // Adds an element at the end
    void push_back(const T& value); // Amortized O(1)

    // Inserts an element at a specific position
    void insert(const int pos, const T& value); // O(n) 

    // Inserts multiple elements at a position
    void insert(const int pos, const T& value, int count); // O(n + m)

    // Inserts the elements of another vector at a position
    void insert(const int pos, const vector<T>& other); // O(n + m)

    // Inserts elements from an initializer list
    void insert(const int pos, std::initializer_list<T> l); // O(n + m)

    // Removes the last element
    void pop_back(); // O(1)

    // Removes an element at a specific position
    void remove(const int pos); // O(n)

    // Removes multiple elements starting from a position
    void remove(const int pos, int count); // O(n)

    // Reduces the capacity to match the size
    void shrink_to_fit(); // O(n)

    // Removes all elements
    void clear(); // O(n)

    // Checks if the vector is empty
    bool is_empty(); // O(1)

    // Resizes the vector to a specified size
    void resize(const int count, const T& value = 0); // O(n)

    // Access element at a specific position
    T& operator[](const int pos); // O(1)

    // Const version of the above
    const T& operator[](const int pos) const; // O(1)

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

#include "vector_impl_.hpp"

#endif // VECTOR_HPP