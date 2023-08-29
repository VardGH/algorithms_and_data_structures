#ifndef LINKED_LIST_IMPL_HPP
#define LINKED_LIST_IMPL_HPP

#include <iostream>

template <typename T>
linked_list<T>::linked_list()
    : m_head(nullptr)
    , m_tail(nullptr)
    , m_size(0)
{
}

template <typename T>
linked_list<T>::linked_list(const linked_list<T>& other)
    : m_head(nullptr)
    , m_tail(nullptr)
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
    , m_tail(other.m_tail)
    , m_size(other.m_size)
{
    other.m_head = nullptr;
    other.m_head = nullptr;
    other.m_size = 0;
}

template <typename T>
linked_list<T>& linked_list<T>::operator=(linked_list<T>&& other)
{
    if (this != &other) {
        clear();

        m_head = other.m_head;
        m_tail = other.m_tail;
        m_size = other.m_size;
        
        other.m_head = nullptr;
        other.m_tail = nullptr;
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
    m_tail = nullptr;
    m_size = 0;
}

template <typename T>
void linked_list<T>::push_back(const T& value)
{
    node<T>* new_node = new node<T>(value);

    if (!m_head) {
        m_head = new_node;
        m_tail = new_node;
    } else {
        new_node->m_prev = m_tail;
        m_tail->m_next = new_node;
        m_tail = new_node;
    }
    ++m_size;
}

template <typename T>
void linked_list<T>::pop_back() 
{
    if (!m_tail) {
        throw std::runtime_error("List is empty. Cannot pop_back()");
    }

    node<T>* tmp = m_tail;

    if (m_head == m_tail) {
        m_head = nullptr;
        m_tail = nullptr;
    } else {
        m_tail = m_tail->m_prev;
        m_tail->m_next = nullptr;
    }
    delete tmp;
    --m_size;
}

template <typename T>
void linked_list<T>::erase(int pos)
{
    if (pos < 0 || pos >= m_size) {
        throw std::out_of_range("Invalid position for erase");
    }

    if (pos == 0) {
        pop_front();
    } else if (pos == m_size - 1) {
        pop_back();
    } else {
        node<T>* current = m_head;

        for (int i = 0; i < pos; ++i) {
            current = current->m_next;
        }

        current->m_prev->m_next = current->m_next;
        current->m_next->m_prev = current->m_prev;
        delete current;
        --m_size;
    }
}

template <typename T>
void linked_list<T>::insert(const int pos, const T& value) {
    if (pos < 0 || pos > m_size) {
        throw std::out_of_range("Invalid position for insert");
    }

    if (pos == 0) {
        push_front(value);
    } else if (pos == m_size) {
        push_back(value);
    } else {
        node<T>* new_node = new node<T>(value);
        node<T>* current = m_head;

        for (int i = 0; i < pos - 1; ++i) {
            current = current->m_next;
        }

        new_node->m_prev = current;
        new_node->m_next = current->m_next;
        current->m_next->m_prev = new_node;
        current->m_next = new_node;

        ++m_size;
    }
}

template <typename T>
void linked_list<T>::push_front(const T& value)
{
    node<T>* tmp = new node<T>(value, m_head);
    if (!m_head) {
        m_head = tmp;
        m_tail = tmp;
    }
    m_head->m_prev = tmp;
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
    if (m_head == m_tail) {
        m_head = nullptr;
        m_tail = nullptr;
    } else {
        m_head = m_head->m_next;
        m_head->m_prev = nullptr;
    }
    delete tmp;
    --m_size;
}

template <typename T>
void linked_list<T>::print_list1() const
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
void linked_list<T>::print_list2() const
{
    if (!m_tail) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    node<T>* current = m_tail;
    while (current) {
        std::cout << current->m_data << " ";
        current = current->m_prev;
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
void linked_list<T>::revers() {
    if (!m_head || !m_tail) {
        return;
    }

    node<T>* current = m_head;
    node<T>* temp;

    while (current) {
        // Swap next and prev
        temp = current->m_next;
        current->m_next = current->m_prev;
        current->m_prev = temp;
        current = temp;
    }

    // Swap m_head and m_tail pointers
    temp = m_head;
    m_head = m_tail;
    m_tail = temp;
}

template <typename T>
void linked_list<T>::merge(linked_list<T>& list) 
{
    m_head = merge_recursive(m_head, list.m_head);
    list.m_head = nullptr;
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
        if (l1->m_next) {
            l1->m_next->m_prev = l1;
        }
        l1->m_prev = nullptr;
        return l1;
    } else {
        l2->m_next = merge_recursive(l1, l2->m_next);
        if (l2->m_next) {
            l2->m_next->m_prev = l2;
        }
        l2->m_prev = nullptr;
        return l2;
    }
}

template <typename T>
void linked_list<T>::sort()
{
    m_head = sort_(m_head);
}

template <typename T>
node<T>* linked_list<T>::sort_(node<T>* list)
{
    if (!list || !list->m_next) {
        return list;
    }

    node<T>* slow = list;
    node<T>* fast = list->m_next;

    while (fast && fast->m_next) {
        slow = slow->m_next;
        fast = fast->m_next->m_next;
    }

    fast = slow->m_next;
    slow->m_next = nullptr;

    node<T>* left = sort_(list);
    node<T>* right = sort_(fast);
    return merge_recursive(left, right);
}

#endif // LINKED_LIST_IMPL_HPP