#include <iostream>
#include <vector>

template <typename T>
void insertion_sort(std::vector<T>& bucket)
{
    for (size_t i = 1; i < bucket.size(); ++i) {
        T key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

template <typename T>
void bucket_sort(std::vector<T>& vec)
{
    T max_val = vec[0];
    T min_val = vec[0];
    for (auto& elem : vec) {
        if (elem > max_val) {
            max_val = elem;
        }
        if (elem < min_val) {
            min_val = elem;
        }
    }

    int num_buckets = vec.size();
    std::vector<std::vector<T>> buckets(num_buckets);

    for (auto& elem : vec) {
        int bucket_index = (elem - min_val) * (num_buckets - 1) / (max_val - min_val);
        buckets[bucket_index].push_back(elem);
    }

    for (auto& bucket : buckets) {
        insertion_sort(bucket);
    }

    int index = 0;
    for (const auto& bucket : buckets) {
        for (const auto& elem : bucket) {
            vec[index++] = elem;
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
    std::vector<float> vec = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};

    std::cout << "Before sorting: ";
    print_vector(vec);

    bucket_sort(vec);

    std::cout << "After sorting: ";
    print_vector(vec);

    return 0;
}
