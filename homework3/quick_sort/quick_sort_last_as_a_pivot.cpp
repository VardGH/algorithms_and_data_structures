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
int partition(std::vector<T>& vec, int first, int last)
{
    T pivot = vec[last];
    int i = first - 1;

    for (int j = first; j <= last - 1; ++j) {
        if (vec[j] < pivot) {
            ++i;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[last]);
    return i + 1;
}

template <typename T>
void quick_sort(std::vector<T>& vec, int first, int last)
{
    if (first < last) {
        int pi = partition(vec, first, last);

        quick_sort(vec, first, pi - 1);
        quick_sort(vec, pi + 1, last);
    }
}

template <typename T>
void print_vector(std::vector<T>& vec)
{
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::vector<int> vec {-2, -3, 4, -1, -2, 1, 5, -3 };

    std::cout << "Before sorting: ";
    print_vector(vec);

    quick_sort(vec, 0, vec.size() - 1);

    std::cout << "After sorting: ";
    print_vector(vec);
}