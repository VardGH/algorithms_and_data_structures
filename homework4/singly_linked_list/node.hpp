#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class node
{
public:
    // Default constructor
    node();

    // Constructor with parameter
    explicit node(const T& data);

    // Constructor with parameter
    node(const T& data, node<T>* next);

    // Copy constructor
    node(const node<T>& other);

    // Copy assignment operator
    node<T>& operator=(const node<T>& other);

    // Move constructor
    node(node<T>&& other) noexcept;

    // Move assignment operator
    node<T>&& operator=(node<T>&& other) noexcept;

    // Destructor
    ~node() = default;

public:
    T m_data;
    node<T>* m_next;
};

#include "node_impl_.hpp"

#endif // NODE_HPP