#include <iostream>
#include <vector>

int max_subarray_sum(const std::vector<int>& vec) {
    int max_sum = vec[0];  
    int current_sum = vec[0]; 

    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] > current_sum + vec[i]) {
            current_sum = vec[i];  
        } else {
            current_sum = current_sum + vec[i]; 
        }

        if (current_sum > max_sum) {
            max_sum = current_sum; 
        }
    }

    return max_sum;
}

int main() {
    std::vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
    int result = max_subarray_sum(nums);
    std::cout << "Maximum subarray sum: " << result << std::endl;

    return 0;
}
