#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T>& vec, int first, int mid, int last)
{
    int first1 = first;
    int end1 = mid;
    int first2 = mid + 1;
    int end2 = last;
    int k = 0;

    std::vector<T> tmp(last - first + 1);

    while (first1 <= end1 && first2 <= end2) {
        if (vec[first1] < vec[first2]) {
            tmp[k++] = vec[first1++];
        } else {
            tmp[k++] = vec[first2++];
        }
    }

    while (first1 <= end1) {
        tmp[k++] = vec[first1++];
    }

    while (first2 <= end2) {
        tmp[k++] = vec[first2++];
    }

    k = 0;
    for (int i = first; i <= last; ++i) {
        vec[i] = tmp[k++];
    }
}

template <typename T>
void merge_sort(std::vector<T>& vec, int first, int last)
{
    if (first < last) {
        int mid = first + (last - first) / 2;
        merge_sort(vec, first, mid);
        merge_sort(vec, mid + 1, last);
        merge(vec, first, mid, last);
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
    std::vector<int> vec {4, 7, -12, 23, -45, 67, 71, 20, -32};

    std::cout << "Before sorting: ";
    print_vector(vec);

    merge_sort(vec, 0, vec.size() - 1);

    std::cout << "After sorting: ";
    print_vector(vec);
}
