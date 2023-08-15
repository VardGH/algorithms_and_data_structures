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
void bubble_sort(std::vector<T>& vec)
{
    for (int i = 0; i < vec.size(); ++i) {
        bool swapped = false;
        for (int j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
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

    bubble_sort(vec);

    std::cout << "After sorting: ";
    print_vector(vec);
}