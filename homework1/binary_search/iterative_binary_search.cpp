#include <iostream>
#include <vector>

template <typename T>
int iterative_binary_search(const std::vector<T>& vec, int first, int last, const T key)
{
    while (first <= last) {
        int mid  = first + (last - first) / 2;
        if (vec[mid] == key) {
            return mid;
        } else if (vec[mid] > key) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> int_vec {3, 6, 7, 11, 16, 20, 25};
    int int_target = 25;
    std::cout << "Index of " << int_target << ": " << iterative_binary_search(int_vec, 0, int_vec.size() - 1, int_target) << std::endl;

    std::vector<double> double_vec {1.5, 2.7, 3.14, 5.0, 8.9, 10.2, 15.7};
    double double_target = 3.14;
    std::cout << "Index of " << double_target << ": " << iterative_binary_search(double_vec, 0, double_vec.size() - 1, double_target) << std::endl;

    std::vector<std::string> str_vec {"apple", "banana", "cherry", "grape", "orange", "pear"};
    std::string str_target = "grape";
    std::cout << "Index of " << str_target << ": " << iterative_binary_search(str_vec, 0, str_vec.size() - 1, str_target) << std::endl;
    
    return 0;
}