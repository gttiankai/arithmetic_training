/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (36.89%)
 * Likes:    1603
 * Dislikes: 0
 * Total Accepted:    458.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers, return an array of all the unique
 * quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *
 *
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
// @lc code=start
/**
 * 由于 -10^9 <= nums[i] <= 10^9, INT_MAX: 2^31-1
 * 所以中间的结果有可能产生溢出,故中间值要用 long 进行存储
 *
 * */
class Solution {
 public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> ans;
    int N = nums.size();
    if (N < 4) {
      return ans;
    }
    // sort nums
    std::sort(nums.begin(), nums.end());
    for (int a = 0; a < N - 3; ++a) {
      if (a > 0 && nums[a] == nums[a - 1]) {
        continue;
      }
      for (int b = a + 1; b < N - 2; ++b) {
        if (b > a + 1 && nums[b] == nums[b - 1]) {
          continue;
        }
        long new_target = (long)target - (long)nums[a] - (long)nums[b];
        int d           = N - 1;
        for (int c = b + 1; c < N - 1; ++c) {
          if (c > b + 1 && nums[c] == nums[c - 1]) {
            continue;
          }
          while (c < d && (long)nums[c] + (long)nums[d] > new_target) {
            d--;
          }
          if (d == c) {
            break;
          }
          if (nums[c] + nums[d] == new_target) {
            ans.push_back({nums[a], nums[b], nums[c], nums[d]});
          }
        }
      }
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> test_case;
  std::vector<int> targets;
  test_case.push_back({1000000000, 1000000000, 1000000000, 1000000000});
  targets.push_back(-294967296);
  test_case.push_back({1, 0, -1, 0, -2, 2});
  targets.push_back(0);
  test_case.push_back({2, 2, 2, 2, 2});
  targets.push_back(8);
  Solution solution;

  for (int i = 0; i < test_case.size(); ++i) {
    auto nums  = test_case[i];
    int target = targets[i];
    auto ans   = solution.fourSum(nums, target);
    for (int j = 0; j < ans.size(); ++j) {
      std::vector<int> output = ans[j];
      std::cout << "[ ";
      for (int k = 0; k < 4; ++k) {
        std::cout << output[k] << " ";
      }
      std::cout << "] ";
    }
    std::cout << std::endl;
  }

  return 0;
}