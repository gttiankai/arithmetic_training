// Given a collection of candidate numbers (candidates) and a target number (
// target), find all unique combinations in candidates where the candidate
// numbers sum to target.
//
//  Each number in candidates may only be used once in the combination.
//
//  Note: The solution set must not contain duplicate combinations.
//
//
//  Example 1:
//
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]
//
//
//  Example 2:
//
//
// Input: candidates = [2,5,2,1,2], target = 5
// Output:
//[
//[1,2,2],
//[5]
//]
//
//
//
//  Constraints:
//
//
//  1 <= candidates.length <= 100
//  1 <= candidates[i] <= 50
//  1 <= target <= 30
//
//
//  Related Topics 数组 回溯 👍 1672 👎 0
#include <algorithm>
#include <numeric>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int>& candidates,
                                                   int target) {
        std::vector<std::vector<int> > ans;
        std::vector<int> combination;
        std::sort(candidates.begin(), candidates.end());
        BackTracking(ans, candidates, 0, combination, target);
        return ans;
    }

   private:
    /**
     * 第一次实现时,没有注意到给定的 candidates 是包含重复元素的,所以下面的解法
     * 汇包含重复的组合,这一点应该如何解决呢?
     **/
    void BackTracking(std::vector<std::vector<int> >& ans,
                      std::vector<int>& candidates, int start,
                      std::vector<int>& combination, int target) {
        int sum = std::accumulate(combination.begin(), combination.end(), 0);
        if (sum == target) {
            ans.push_back(combination);
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i != start && candidates[i-1] == candidates[i]) {
                continue;
            }
            combination.push_back(candidates[i]);
            BackTracking(ans, candidates, i + 1, combination, target);
            combination.pop_back();
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
