#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "node.hpp"

template <typename T>
class linked_list 
{
public:
    // Default constructor
    linked_list();

    // Copy constructor
    linked_list(const linked_list<T>& other);

    // Copy assignment operator
    linked_list<T>& operator=(const linked_list<T>& other);

    // Move constructor
    linked_list(linked_list<T>&& other);

    // Move assignment operator
    linked_list<T>& operator=(linked_list<T>&& other);

    // Destructor
    ~linked_list();

public:
    // Adds an element at the end of the list
    void push_back(const T& value); // O(n)

    // Removes the last element from the list
    void pop_back(); // O(1)

    // Removes an element at a specific position
    void erase(int pos); // O(n)

    // Inserts an element at a specific position
    void insert(const int pos, const T& value);  // O(n)

    // Removes all elements from the list
    void clear() noexcept; // O(n)

    // Checks if the list is empty
    bool is_empty() const;  // O(1)

    // Returns the number of elements in the list
    int get_size() const; // O(1)

    // Adds an element at the beginning of the list
    void push_front(const T& value);  // O(1)

    // Removes the first element from the list
    void pop_front(); // O(1)

    // Prints the elements of the list
    void print_list1() const; // O(n)

    // Prints the elements of the list
    void print_list2() const; // O(n)

    // Reverse the linked list in-place
    void revers(); // O(n)

    // Merge two sorted linked lists and return a new sorted linked list
    void merge(linked_list<T>& list); // O(n)

    // recursive merge
    node<T>* merge_recursive(node<T>* l1, node<T>* l2); // O(n)

    // Sort the linked list using the merge sort algorithm.
    void sort(); // O(n log n)

private:
    node<T>* sort_(node<T>* list);
 
private:
    node<T>* m_head; // Pointer to the head node
    node<T>* m_tail; // Pointer to the tail node
    int m_size;      // Number of elements in the list
};

#include "linked_list_impl.hpp"

#endif // LINKED_LIST_HPP
