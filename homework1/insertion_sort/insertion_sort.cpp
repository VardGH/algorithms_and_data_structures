#include <iostream>
#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& vec)
{
    for (int i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
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
    std::vector<int> vec {2, 5, -1, 0, 45, 23, -12, 87, 9};

    std::cout << "Before sorting: ";
    print_vector(vec);

    insertion_sort(vec);

    std::cout << "After sorting: ";
    print_vector(vec);

}