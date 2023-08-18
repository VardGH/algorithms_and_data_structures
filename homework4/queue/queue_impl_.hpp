#ifndef QUEUE_IMPL_HPP
#define QUEUE_IMPL_HPP

#include <stdexcept>

namespace adapter {

template <typename T>
queue<T>::queue() 
    : m_index(0) 
{
}

template <typename T>
queue<T>::queue(const int size) 
    : m_arr(size)
    , m_index(0) 
{
}

template <typename T>
queue<T>::queue(const queue& other) 
    : m_arr(other.m_arr)
    , m_index(other.m_index) 
{
}

template <typename T>
queue<T>& queue<T>::operator=(const queue& other) 
{
    if (this != &other) {
        m_arr = other.m_arr;
        m_index = other.m_index;
    }
    return *this;
}

template <typename T>
queue<T>::queue(queue&& other) 
    : m_arr(std::move(other.m_arr))
    , m_index(other.m_index) 
{
}

template <typename T>
queue<T>& queue<T>::operator=(queue&& other) 
{
    if (this != &other) {
        m_arr = std::move(other.m_arr);
        m_index = other.m_index;
    }
    return *this;
}

template <typename T>
void queue<T>::push(const T& value) 
{
    m_arr.push_back(value);
}

template <typename T>
void queue<T>::pop() {
    if (!empty()) {
        for (int i = 0; i < m_arr.size() - 1; ++i) {
            m_arr[i] = m_arr[i + 1];
        }
        --m_index;
        m_arr.pop_back(); // Remove the last element
    } else {
        throw std::runtime_error("Attempted to pop from an empty queue");
    }
}


template <typename T>
T& queue<T>::top() 
{
    return m_arr[m_index];
}

template <typename T>
const T& queue<T>::top() const 
{
    return m_arr[m_index];
}

template <typename T>
size_t queue<T>::size() const 
{
    return m_arr.size();
}

template <typename T>
bool queue<T>::empty() const 
{
    return m_arr.empty();
}

} // namespace adapter

#endif // QUEUE_IMPL_HPP