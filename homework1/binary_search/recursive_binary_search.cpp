#include <iostream>
#include <vector>


template <typename T>
int recursive_binary_search(const std::vector<T>& vec, const int first, const int last, const T key)
{
    if (first <= last) {
        int mid = first + (last - first) / 2;
        if (vec[mid] == key) {
            return mid;
        } else if (vec[mid] > key) {
            return recursive_binary_search(vec, first, mid - 1, key);
        } else {
            return recursive_binary_search(vec, mid + 1, last, key);
        }
    }
    return - 1;
}

int main()
{
    std::vector<int> int_vec {3, 6, 7, 11, 16, 20, 25};
    int int_target = 25;
    std::cout << "Index of " << int_target << ": " << recursive_binary_search(int_vec, 0, int_vec.size() - 1, int_target) << std::endl;

    std::vector<double> double_vec {1.5, 2.7, 3.14, 5.0, 8.9, 10.2, 15.7};
    double double_target = 3.14;
    std::cout << "Index of " << double_target << ": " << recursive_binary_search(double_vec, 0, double_vec.size() - 1, double_target) << std::endl;

    std::vector<std::string> str_vec {"apple", "banana", "cherry", "grape", "orange", "pear"};
    std::string str_target = "grape";
    std::cout << "Index of " << str_target << ": " << recursive_binary_search(str_vec, 0, str_vec.size() - 1, str_target) << std::endl;

    return 0;
}