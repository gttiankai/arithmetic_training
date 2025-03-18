// Given an array nums of size n, return the majority element.
//
//  The majority element is the element that appears more than ⌊n / 2⌋ times.
// You may assume that the majority element always exists in the array.
//
//
//  Example 1:
//  Input: nums = [3,2,3]
// Output: 3
//
//  Example 2:
//  Input: nums = [2,2,1,1,1,2,2]
// Output: 2
//
//
//  Constraints:
//
//
//  n == nums.length
//  1 <= n <= 5 * 10⁴
//  -10⁹ <= nums[i] <= 10⁹
//
//
//
// Follow-up: Could you solve the problem in linear time and in
// O(1) space?
//

#include <unordered_set>
#include <vector>
#include <iostream>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_set<int> nums_set;
        int m = nums.size() / 2;
        for (int i = 0; i < nums.size(); ++i) {
            nums_set.insert(nums[i]);
            int count = nums_set.count(nums[i]);
            if (count > m) {
                return nums[i];
            }
        }
        return 0;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> test_cases({{3, 2, 3}, {2, 2, 1, 1, 1, 2, 2}});
    for (auto& case_ : test_cases) {
        int majority_element = solution.majorityElement(case_);
        std::cout << "majority element is:" << majority_element << std::endl;
    }
    return 0;
}
