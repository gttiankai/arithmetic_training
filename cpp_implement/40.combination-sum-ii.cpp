/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (59.77%)
 * Likes:    1362
 * Dislikes: 0
 * Total Accepted:    434K
 * Total Submissions: 726K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 * Example 1:
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * Example 2:
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 * Constraints:
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "integer_utils.h"

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> ans;
    std::sort(candidates.begin(), candidates.end());
    // special case
    if (target < candidates[0]) {
      return ans;
    }
    std::vector<int> combination;
    DFS(candidates, target, 0, combination, ans);
    return ans;
  }

 private:
  void DFS(std::vector<int>& candidates, int target, int index, std::vector<int>& combination,
           std::vector<std::vector<int>>& ans) {
    // keypoint: 首先判断是否等于 target
    // bad case: candidates:[1, 2, 2, 5], target: 5. 当尝试元素 '5' 时,如果不先判断,就会漏掉这个情况
    if (target == 0) {
      ans.push_back(combination);
      return;
    }
    if (index == candidates.size()) {
      return;
    }
    if (target < candidates[index]) {
      return;
    }
    for (int i = index; i < candidates.size() && target - candidates[i] >= 0; ++i) {
      // keypoint: 下面的判断是通用的去重的好方法
      if (i > index && candidates[i] == candidates[i - 1]) {
        continue;
      }
      combination.push_back(candidates[i]);
      DFS(candidates, target - candidates[i], i + 1, combination, ans);
      combination.pop_back();
    }
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<std::string> test_case;
  std::vector<int> targets;
  test_case.push_back("[10,1,2,7,6,1,5]");
  targets.push_back(8);
  test_case.push_back("[2,5,2,1,2]");
  targets.push_back(5);
  test_case.push_back("[2]");
  targets.push_back(1);
  for (int i = 0; i < test_case.size(); ++i) {
    std::cout << "candidates: " << test_case[i] << " target:" << targets[i] << " ";
    auto candidates   = StringToIntegerVector(test_case[i]);
    auto combinations = solution.combinationSum2(candidates, targets[i]);
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
