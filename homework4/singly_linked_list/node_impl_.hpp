#ifndef NODE_IMPL_HPP
#define NODE_IMPL_HPP

template <typename T>
node<T>::node()
    : m_data(0)
    , m_next(nullptr)
{
}

template <typename T>
node<T>::node(const T& data, node<T>* next)
    : m_data(data)
    , m_next(next)
{
}

template <typename T>
node<T>::node(const T& data)
    : m_data(data)
    , m_next(nullptr)
{
}

template <typename T>
node<T>::node(const node<T>& other)
    : m_data(other.m_data)
    , m_next(nullptr)
{
}

template <typename T>
node<T>& node<T>::operator=(const node<T>& other)
{
    if (this != &other) {
        m_data = other.m_data;
    }
    return *this;
}

template <typename T>
node<T>::node(node<T>&& other) noexcept
    : m_data(std::move(other.m_data))
    , m_next(other.m_next)
{
    other.m_data = 0;
    other.m_next = nullptr;
}

template <typename T>
node<T>&& node<T>::operator=(node<T>&& other) noexcept
{
    if (this != &other) {
        m_data = std::move(other.m_data);
        m_next = other.m_next;
        other.m_next = nullptr;
    }
    return *this;
}

#endif // NODE_IMPL_HPP