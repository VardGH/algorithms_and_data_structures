#include <iostream>
#include <vector>

template <typename T>
void swap(T& num1, T& num2)
{
    T tmp = num1;
    num1 = num2;
    num2 = tmp;
}

template <typename T>
void selection_sort(std::vector<T>& vec)
{
    for (int i = 0; i < vec.size(); ++i) {
        int min_index = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[min_index] > vec[j]) {
                min_index = j;
            }
        }
        swap(vec[min_index], vec[i]);
    }
}


template <typename T>
void print_vector(const std::vector<T>& vec)
{
    for (auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec {4, 7, -12, 23, -45, 67, 71, 20, -32};

    std::cout << "Before sorting: ";
    print_vector(vec);

    selection_sort(vec);

    std::cout << "After sort: ";
    print_vector(vec);
}