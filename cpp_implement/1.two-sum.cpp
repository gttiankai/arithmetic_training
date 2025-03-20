/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.cn/problems/two-sum/description/
 *
 * algorithms
 * Easy (52.87%)
 * Likes:    19291
 * Dislikes: 0
 * Total Accepted:    6.1M
 * Total Submissions: 11.1M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 *
 *
 *
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */
#include <iostream>
#include <vector>
class SolutionSlow {
   public:
    // 先实现一个O(n^2)的解法
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        int count = nums.size();
        for (int i = 0; i < count; ++i) {
            for (int j = i + 1; j < count; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
// @lc code=start
class Solution {
   public:
    // 这个实现是有问题的,这个实现会重复的使用元素,与题目不符
    std::vector<int> twoSumWrong(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i) {
            hash_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (hash_map.find(diff) != hash_map.end()) {
                return {i, hash_map[diff]};
            }
        }
        return {};
    }

    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i) {
            hash_map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (hash_map.find(diff) != hash_map.end() && hash_map[diff] != i) {
                return {i, hash_map[diff]};
            }
        }
        return {};
    }
};
// @lc code=end
int main(int argc, char *argv[]) {
    std::vector<int> nums = {3, 2, 4};
    int target            = 6;

    Solution solution;
    auto ans = solution.twoSum(nums, target);
    for (const auto &item : ans) {
        std::cout << item << " ";
    }

    std::cout << std::endl;
    return 0;
}
