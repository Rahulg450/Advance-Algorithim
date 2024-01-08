#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numIndexMap; 
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (numIndexMap.find(complement) != numIndexMap.end()) {
            return {numIndexMap[complement], i};
        }

        numIndexMap[nums[i]] = i;
    }

    return {};
}

int main() {
    // Initialize vector using push_back
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Output: [" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
        std::cout << "No valid solution found." << std::endl;
    }

    return 0;
}
