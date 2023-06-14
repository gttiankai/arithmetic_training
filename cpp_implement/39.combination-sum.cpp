/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.cn/problems/combination-sum/description/
 *
 * algorithms
 * Medium (72.36%)
 * Likes:    2508
 * Dislikes: 0
 * Total Accepted:    742.7K
 * Total Submissions: 1M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 *
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 *
 * The test cases are generated such that the number of unique combinations
 * that sum up to target is less than 150 combinations for the given input.
 *
 * Example 1:
 *
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 *
 * Example 2:
 *
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 *
 * Example 3:
 *
 * Input: candidates = [2], target = 1
 * Output: []
 *
 * Constraints:
 *
 * 1 <= candidates.length <= 30
 * 2 <= candidates[i] <= 40
 * All elements of candidates are distinct.
 * 1 <= target <= 40
 */

#include <iostream>
#include <string>
#include <vector>
#include "integer_utils.h"

// @lc code=start
/**
 * 解法 1：使用暴力枚举的方式遍历所有的组合，然后判断结果是否等于 target,这种方式的时间复杂度太高了
 * 解法 2：要想办法优化上面的算法，第一进行排序
 * 对于这类寻找所有可行解的题，我们都可以尝试用「搜索回溯」的方法来解决。
 * */
class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> ans;
    // sort candidates
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> combination;
    OPTDFS(candidates, target, 0, combination, ans);
    return ans;
  }

 private:
  void DFS(std::vector<int>& candidates, int target, int index, std::vector<int>& combination,
           std::vector<std::vector<int>>& ans) {
    if (index == candidates.size()) {
      // search the end of candidates
      return;
    }
    if (target == 0) {
      ans.emplace_back(combination);
      return;
    }
    // do not jump index element
    if (target - candidates[index] >= 0) {
      combination.emplace_back(candidates[index]);
      DFS(candidates, target - candidates[index], index, combination, ans);
      combination.pop_back();
    }
    // jump index element
    DFS(candidates, target, index + 1, combination, ans);
  }
  /**
   * 主要通过将数组进行排序，再加上对边界条件的检查的改善进行剪枝，进一步的优化性能
   *
   * */
  void OPTDFS(std::vector<int>& candidates, int target, int index, std::vector<int>& combination,
              std::vector<std::vector<int>>& ans) {
    if (index == candidates.size()) {
      return;
    }
    if (target == 0) {
      ans.push_back(combination);
      return;
    }
    if (target < candidates[index]) {
      return;
    }
    if (target == candidates[index]) {
      combination.push_back(candidates[index]);
      ans.push_back(combination);
      combination.pop_back();
      return;
    }
    if (target - candidates[index] >= candidates[index]) {
      // does not jump index element
      combination.push_back(candidates[index]);
      OPTDFS(candidates, target - candidates[index], index, combination, ans);
      combination.pop_back();
    }
    // jump the index element
    OPTDFS(candidates, target, index + 1, combination, ans);
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<std::string> test_case;
  std::vector<int> targets;
  test_case.push_back("[2,3,6,7]");
  targets.push_back(7);
    test_case.push_back("[2,3,5]");
    targets.push_back(8);
    test_case.push_back("[2]");
    targets.push_back(1);
  for (int i = 0; i < test_case.size(); ++i) {
    std::cout << "candidates: " << test_case[i] << " target:" << targets[i] << " ";
    auto candidates   = StringToIntegerVector(test_case[i]);
    auto combinations = solution.combinationSum(candidates, targets[i]);
    std::cout << " combinations:  ";
    for (const auto& item : combinations) {
      std::string message = "[";
      for (const auto& iter : item) {
        message += std::to_string(iter) + ", ";
      }
      message += "] ";
      std::cout << message;
    }
    std::cout << std::endl;
  }
  return 0;
}