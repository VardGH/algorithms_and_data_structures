#include <iostream>
#include <vector>
#include <limits>

int max_subarray_sum(const std::vector<int>& vec)
{
    int max_sum = std::numeric_limits<int>::min();
    int current_sum = 0;

    for (int i = 0; i < vec.size(); ++i) {
        current_sum = vec[i]; 
        for (int j = i + 1; j < vec.size(); ++j) {
            current_sum += vec[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }

    return max_sum;
}

int main()
{
    std::vector<int> vec {-2, -3, 4, -1, -2, 1, 5, -3};

    std::cout << "Maximum Subarray Sum: " << max_subarray_sum(vec) << std::endl;

    return 0;
}