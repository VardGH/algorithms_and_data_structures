#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class node
{
public:
    node(); // Default constructor
    explicit node(const T& data); // Constructor with parameter
    node(const T& data, node<T>* next); // Constructor with parameter

    node(const node<T>& other); // Copy constructor
    node<T>& operator=(const node<T>& other); // Copy assignment operator

    node(node<T>&& other) noexcept; // Move constructor
    node<T>&& operator=(node<T>&& other) noexcept; // Move assignment operator

    ~node() = default; // Destructor

public:
    T m_data;
    node<T>* m_prev;
    node<T>* m_next;
};

#include "node_impl_.hpp"

#endif // NODE_HPP
