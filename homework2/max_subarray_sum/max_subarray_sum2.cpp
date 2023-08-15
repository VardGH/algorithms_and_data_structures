#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

std::tuple<int, int, int> max_crossing_sum(const std::vector<int>& vec, int low, int mid, int high) {
    int left_sum = std::numeric_limits<int>::min();
    int sum = 0;
    int max_left;
    int max_right;

    for (int i = mid; i >= low; --i) {
        sum += vec[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = std::numeric_limits<int>::min();
    sum = 0;

    for (int j = mid + 1; j <= high; ++j) {
        sum += vec[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    return std::make_tuple(max_left, max_right, left_sum + right_sum);
}

std::tuple<int, int, int> max_subarray(const std::vector<int>& vec, int low, int high) {
    if (low == high) {
        return std::make_tuple(low, high, vec[low]);
    }

    int mid = (low + high) / 2;

    auto [left_low, left_high, left_sum] = max_subarray(vec, low, mid);
    auto [right_low, right_high, right_sum] = max_subarray(vec, mid + 1, high);
    auto [cross_low, cross_high, cross_sum] = max_crossing_sum(vec, low, mid, high);

    if (left_sum >= right_sum && left_sum >= cross_sum && left_sum > 0) {
        return std::make_tuple(left_low, left_high, left_sum);
    } else if (right_sum >= left_sum && right_sum >= cross_sum && right_sum > 0) {
        return std::make_tuple(right_low, right_high, right_sum);
    } else {
        return std::make_tuple(cross_low, cross_high, cross_sum);
    }
}

int main() {
    std::vector<int> vec = { -2, -3, 4, -1, -2, 1, 5, -3 };

    auto [low, high, sum] = max_subarray(vec, 0, vec.size() - 1);

    std::cout << "Maximum subarray sum: " << sum << std::endl;
    std::cout << "Subarray indices: " << low << " to " << high << std::endl;

    return 0;
}
