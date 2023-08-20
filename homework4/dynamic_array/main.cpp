#include <iostream>
#include "vector.hpp" 

int main() 
{
    container::vector<int> v;  // Create a vector of integers

    // Push elements into the vector
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // Display vector size and capacity
    std::cout << "Vector size: " << v.get_size() << std::endl;
    std::cout << "Vector capacity: " << v.get_capacity() << std::endl;

    // Display vector elements using index operator
    for (int i = 0; i < v.get_size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // Insert elements from another vector at a specific position
    container::vector<int> other;
    other.push_back(100);
    other.push_back(200);
    other.push_back(300);
    v.insert(2, other);

    // Display updated vector elements
    for (int i = 0; i < v.get_size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // Insert elements from an initializer list at a specific position
    v.insert(1, {50, 60, 70});

    // Display updated vector elements
    for (int i = 0; i < v.get_size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;


    v.pop_back();
    v.pop_back();

    for (int i = 0; i < v.get_size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
