#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <vector>

namespace adapter {

template <typename T>
class queue
{
public:
    queue(); // Default constructor
    explicit queue(const int size); // Constructor with parameter

    queue(const queue& other); // Copy constructor
    queue& operator=(const queue& other);  // Copy assignment operator

    queue(queue&& other); // Move constructor
    queue& operator=(queue&& other); // Move assignment operator

    ~queue() = default; // Destructor

public:
    void push(const T& value);
    void pop(); 
    T& top(); 
    const T& top() const; 
    size_t size() const; 
    bool empty() const; 

private:
    std::vector<T> m_arr;
    int m_index;
};

/*
// Non-member comparison operators
template <typename T>
bool operator==(const queue<T>& lhs, const queue<T>& rhs);

template <typename T>
bool operator!=(const queue<T>& lhs, const queue<T>& rhs);

template <typename T>
bool operator<(const queue<T>& lhs, const queue<T>& rhs);

template <typename T>
bool operator<=(const queue<T>& lhs, const queue<T>& rhs);

template <typename T>
bool operator>(const queue<T>& lhs, const queue<T>& rhs);

template <typename T>
bool operator>=(const queue<T>& lhs, const queue<T>& rhs); */

} // namespace adapter

#include "queue_impl_.hpp"

#endif // QUEUE_HPP