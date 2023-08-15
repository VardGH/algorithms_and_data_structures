#include <iostream>
#include <vector>

template <typename T>
T find_max(const std::vector<T>& vec)
{
    T max_val = vec[0];
    for (auto& elem : vec) {
        if (elem > max_val) {
            max_val = elem;
        }
    }
    return max_val;
}

template <typename T>
void counting_sort(std::vector<T>& vec, int exp)
{
    std::vector<T> output(vec.size());
    std::vector<int> count(10, 0);

    for (int i = 0; i < vec.size(); ++i) {
        count[(vec[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = vec.size() - 1; i >= 0; --i) {
        output[count[(vec[i] / exp) % 10] - 1] = vec[i];
        count[(vec[i] / exp) % 10]--;
    }

    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = output[i];
    }
}


template <typename T>
void radix_sort(std::vector<T>& vec)
{
    T max_val = find_max(vec);

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort(vec, exp);
    }
}


template <typename T>
void print_vector(const std::vector<T>& vec)
{
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = {17, 34, 58, 64};
    std::cout << "Before sorting: ";
    print_vector(vec);

    radix_sort(vec);

    std::cout << "Sorted array: ";
    print_vector(vec);

    return 0;
}
