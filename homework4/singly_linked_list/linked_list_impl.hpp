#ifndef LINKED_LIST_IMPL_HPP
#define LINKED_LIST_IMPL_HPP

#include <iostream>

template <typename T>
linked_list<T>::linked_list()
    : m_head(nullptr)
    , m_size(0)
{
}

template <typename T>
linked_list<T>::linked_list(const linked_list<T>& other)
    : m_head(nullptr)
    , m_size(0)
{
    node<T>* current = other.m_head;
    while (current) {
        push_back(current->m_data);
        current = current->m_next;
    }
}

template <typename T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& other)
{
    if (this != &other) {
        clear();

        node<T>* current = other.m_head;
        while (current->m_next) {
            push_back(current->m_data);
            current = current->m_next;
        }
    }
    return *this;
}

template <typename T>
linked_list<T>::linked_list(linked_list<T>&& other)
    : m_head(other.m_head)
    , m_size(other.m_size)
{
    other.m_head = nullptr;
    other.m_size = 0;
}

template <typename T>
linked_list<T>& linked_list<T>::operator=(linked_list<T>&& other)
{
    if (this != &other) {
        clear();

        m_head = other.m_head;
        m_size = other.m_size;
        
        other.m_head = nullptr;
        other.m_size = 0;
    }   
    return *this;
}

template <typename T>
linked_list<T>::~linked_list()
{
    clear();
}

template <typename T>
void linked_list<T>::clear() noexcept
{
    while (m_head) {
        node<T>* tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }
    m_head = nullptr;
    m_size = 0;
}

template <typename T>
void linked_list<T>::push_back(const T& value)
{
    node<T>* new_node = new node<T>(value);

    if (!m_head) {
        m_head = new_node;
    } else {
        node<T>* current = m_head;

        while (current->m_next) {
            current = current->m_next;
        }
        current->m_next = new_node;
    }
    ++m_size;
}

template <typename T>
void linked_list<T>::pop_back() 
{
    if (m_head) {
        if (m_head->m_next) {
            node<T>* current = m_head;
            while (current->m_next->m_next) {
                current = current->m_next;
            }
            delete current->m_next;
            current->m_next = nullptr;
        } else {
            delete m_head;
            m_head = nullptr;
        }
        --m_size;
    }
}

template <typename T>
void linked_list<T>::erase(int pos)
{
    if (pos < 0 || pos >= m_size) {
        throw std::out_of_range("Invalid position for erase");
    }

    if (pos == 0) {
        pop_front();
    } else {
        node<T>* current = m_head;
        for (int i = 0; i < pos - 1; ++i) {
            current = current->m_next;
        }

        node<T>* tmp = current->m_next;
        current->m_next = tmp->m_next;
        delete tmp;
        --m_size;
    }
}

template <typename T>
void linked_list<T>::insert(const int pos, const T& value) 
{
    if (pos < 0 || pos > m_size) {
        throw std::out_of_range("Invalid position for insertion");
    }

    if (pos == 0) {
        push_front(value);
        return;
    }

    node<T>* new_node = new node<T>(value);
    node<T>* current = m_head;

    for (int i = 0; i < pos - 1; ++i) {
        current = current->m_next;
    }

    new_node->m_next = current->m_next;
    current->m_next = new_node;
    ++m_size;
}

template <typename T>
void linked_list<T>::push_front(const T& value)
{
    node<T>* tmp = new node<T>(value, m_head);
    m_head = tmp;
    ++m_size;
}

template <typename T>
void linked_list<T>::pop_front()
{
    if (!m_head) {
        throw std::runtime_error("List is empty. Cannot pop_front()");
    }

    node<T>* tmp = m_head;
    m_head = m_head->m_next;
    delete tmp;
    --m_size;
}

template <typename T>
void linked_list<T>::print_list() const
{
    if (!m_head) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    node<T>* current = m_head;
    while (current) {
        std::cout << current->m_data << " ";
        current = current->m_next;
    }
    std::cout << std::endl;
}

template <typename T>
bool linked_list<T>::is_empty() const 
{
    return m_head == nullptr;
}

template <typename T>
int linked_list<T>::get_size() const
{
    return m_size;
}

template <typename T>
void linked_list<T>::revers() 
{
    if (!m_head || !m_head->m_next) {
        return;
    }

    node<T>* prev = nullptr;
    node<T>* current = m_head;
    node<T>* next;

    while (current) {
        next = current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }

    m_head = prev;
}

template <typename T>
void linked_list<T>::sort()
{
    if (!m_head || !m_head->m_next) {
        return;
    }

    node<T>* slow = m_head;
    node<T>* fast = m_head->m_next;

    while (fast && fast->m_next) {
        slow = slow->m_next;
        fast = fast->m_next->m_next;
    }

    fast = slow->m_next;
    slow->m_next = nullptr;

    linked_list<T> left;
    linked_list<T> right;

    left.m_head = m_head;
    right.m_head = fast;

    left.sort();
    right.sort();

    left.merge(right);
}

/*template <typename T>
void linked_list<T>::merge(const linked_list<T>& list) 
{
    if (!list.m_head) {
        return; 
    }

    node<T>* h1 = m_head;
    node<T>* h2 = list.m_head;

    node<T>* tmp = new node<T>;
    node<T>* res = tmp;

    while (h1 && h2) {
        if (h1->m_data < h2->m_data) {
            tmp->m_next = h1;
            h1 = h1->m_next;
        } else {
            tmp->m_next = h2;
            h2 = h2->m_next;
        }
        tmp = tmp->m_next;
    }

    if (h1) {
        tmp->m_next = h1;
    }

    if (h2) {
        tmp->m_next = h2;
    }
    
    m_head = res->m_next; 

    delete res;
}*/

template <typename T>
void linked_list<T>::merge(const linked_list<T>& list) 
{
    m_head = merge_recursive(m_head, list.m_head);
}

template <typename T>
node<T>* linked_list<T>::merge_recursive(node<T>* l1, node<T>* l2) 
{
    if (!l1) {
        return l2;
    }

    if (!l2) {
        return l1;
    }

    if (l1->m_data < l2->m_data) {
        l1->m_next = merge_recursive(l1->m_next, l2);
        return l1;
    } else {
        l2->m_next = merge_recursive(l1, l2->m_next);
        return l2;
    }
}

#endif // LINKED_LIST_IMPL_HPP