#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

namespace adapter {

template <typename T>
class stack
{
public:
    stack(); // Default constructor
    explicit stack(const int size); // Constructor with parameter

    stack(const stack& other); // Copy constructor
    stack& operator=(const stack& other);  // Copy assignment operator

    stack(stack&& other); // Move constructor
    stack& operator=(stack&& other); // Move assignment operator

    ~stack() = default; // Destructor

public:
    void push(const T& value); // Pushes an element onto the top of the stack.
    void pop(); // Removes the top element from the stack.
    T& top(); // Returns a reference to the top element of the stack.
    const T& top() const; // Returns a const reference to the top element.
    size_t size() const; // Returns the number of elements in the stack.
    bool empty() const; //  Checks if the stack is empty.

private:
    std::vector<T> m_arr;
    int m_index;
};

/*
// Non-member comparison operators
template <typename T>
bool operator==(const stack<T>& lhs, const stack<T>& rhs);

template <typename T>
bool operator!=(const stack<T>& lhs, const stack<T>& rhs);

template <typename T>
bool operator<(const stack<T>& lhs, const stack<T>& rhs);

template <typename T>
bool operator<=(const stack<T>& lhs, const stack<T>& rhs);

template <typename T>
bool operator>(const stack<T>& lhs, const stack<T>& rhs);

template <typename T>
bool operator>=(const stack<T>& lhs, const stack<T>& rhs); */

} // namespace adapter

#include "stack_impl_.hpp"

#endif // STACK_HPP