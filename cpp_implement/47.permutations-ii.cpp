/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.cn/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (65.53%)
 * Likes:    1383
 * Dislikes: 0
 * Total Accepted:    461.9K
 * Total Submissions: 704.9K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include "integer_utils.h"
// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    std::vector<int> permutation;
    std::sort(nums.begin(), nums.end());
    std::vector<bool> flags(nums.size(), false);
    BackTrack(nums, 0, flags, permutation, ans);
    return ans;
  }

 private:
  void BackTrack(std::vector<int>& nums, int index, std::vector<bool>& flags, std::vector<int>& permutation,
                 std::vector<std::vector<int>>& ans) {
    if (permutation.size() == nums.size()) {
      ans.push_back(permutation);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if ((i > index) && nums[i - 1] == nums[i]) {
        continue;
      }
      if (!flags[i]) {
        flags[i] = true;
        permutation.push_back(nums[i]);
        BackTrack(nums, i + 1, flags, permutation, ans);
        permutation.pop_back();
        flags[i] = false;
      }
    }
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<std::string> test_test;
  test_test.push_back("[1,1,2]");
  test_test.push_back("[1,2,3]");
  for (int i = 0; i < test_test.size(); ++i) {
    std::cout << test_test[i] << " permute: ";
    auto nums = StringToIntegerVector(test_test[i]);
    auto ans  = solution.permuteUnique(nums);
    for (int j = 0; j < ans.size(); ++j) {
      std::string message = "[";
      for (const auto& iter : ans[j]) {
        message += std::to_string(iter) + ", ";
      }
      message += "] ";
      std::cout << message;
    }
    std::cout << std::endl;
  }
  return 0;
}
