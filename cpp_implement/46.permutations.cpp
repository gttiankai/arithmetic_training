/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (78.88%)
 * Likes:    2577
 * Dislikes: 0
 * Total Accepted:    875.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *
 * Constraints:
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 */

#include <iostream>
#include <string>
#include <vector>
#include "integer_utils.h"
// @lc code=start
/**
 * 我的编程思路应该是:先有思路,然后将思路通过代码实现出来
 * 这道题的时间复杂度:O(n!), 空间复杂度: O(n^2),由于是要将所有的组合都列出来,所以时间和空间复杂度都不能再优化了.
 *
 * nums: [1, 2, 3, 4]
 * ans:  [1, 2, 3, 4] [1, 2, 4, 3] [1, 3, 2, 4] [1, 3, 4, 2] [1, 4, 2, 3] [1, 4, 3, 2]
 *
 * */
class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    return ans;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<std::string> test_test;
  test_test.push_back("[1,2,3]");
  test_test.push_back("[0,1]");
  for (int i = 0; i < test_test.size(); ++i) {
    std::cout << test_test[i] << " permute: ";
    auto nums = StringToIntegerVector(test_test[i]);
    auto ans  = solution.permute(nums);
    for (int j = 0; j < ans.size(); ++j) {
      std::string message = "[";
      for (const auto& iter : ans[i]) {
        message += std::to_string(iter) + ", ";
      }
      message += "] ";
      std::cout << message;
    }
    std::cout << std::endl;
  }
  return 0;
}
