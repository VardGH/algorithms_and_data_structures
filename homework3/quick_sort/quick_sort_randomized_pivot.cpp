#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
void swap(T& num1, T& num2)
{
    T tmp = num1;
    num1 = num2;
    num2 = tmp;
}

template <typename T>
int random_partition(std::vector<T>& vec, int first, int last)
{
    int random_index = first + rand() % (last - first + 1);
    swap(vec[random_index], vec[last]);
    T pivot = vec[last];
    int i = first - 1;

    for (int j = first; j < last; ++j) {
        if (vec[j] < pivot) {
            ++i;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[last]);
    return i + 1;
}

template <typename T>
void randomized_quick_sort(std::vector<T>& vec, int first, int last)
{
    if (first < last) {
        int pi = random_partition(vec, first, last);
        randomized_quick_sort(vec, first, pi - 1);
        randomized_quick_sort(vec, pi + 1, last);
    }
}

template <typename T>
void print_vector(const std::vector<T>& vec)
{
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed the random number generator
    std::vector<int> vec {-2, -3, 4, -1, -2, 1, 5, -3 };

    std::cout << "Before sorting: ";
    print_vector(vec);

    randomized_quick_sort(vec, 0, vec.size() - 1);

    std::cout << "After sorting: ";
    print_vector(vec);
}
