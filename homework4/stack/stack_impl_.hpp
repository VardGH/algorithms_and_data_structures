#ifndef STACK_IMPL_HPP
#define STACK_IMPL_HPP

#include <stdexcept>

namespace adapter {

template <typename T>
stack<T>::stack() 
    : m_index(-1) 
{
}

template <typename T>
stack<T>::stack(const int size) 
    : m_arr(size)
    , m_index(-1) 
{
}

template <typename T>
stack<T>::stack(const stack& other) 
    : m_arr(other.m_arr)
    , m_index(other.m_index) 
{
}

template <typename T>
stack<T>& stack<T>::operator=(const stack& other) 
{
    if (this != &other) {
        m_arr = other.m_arr;
        m_index = other.m_index;
    }
    return *this;
}

template <typename T>
stack<T>::stack(stack&& other) 
    : m_arr(std::move(other.m_arr))
    , m_index(other.m_index)
{
}

template <typename T>
stack<T>& stack<T>::operator=(stack&& other) 
{
    if (this != &other) {
        m_arr = std::move(other.m_arr);
        m_index = other.m_index;
    }
    return *this;
}

template <typename T>
void stack<T>::push(const T& value) 
{
    m_arr.push_back(value);
    ++m_index;
}

template <typename T>
void stack<T>::pop() 
{
    if (!empty()) {
        m_arr.pop_back();
        --m_index;
    } else {
        throw std::runtime_error("Attempted to pop from an empty stack");
    }
}

template <typename T>
T& stack<T>::top() 
{
    return m_arr[m_index];
}

template <typename T>
const T& stack<T>::top() const 
{
    return m_arr[m_index];
}

template <typename T>
size_t stack<T>::size() const 
{
    return m_arr.size();
}

template <typename T>
bool stack<T>::empty() const 
{
    return m_arr.empty();
}

} // namespace adapter

#endif // STACK_IMPL_HPP
