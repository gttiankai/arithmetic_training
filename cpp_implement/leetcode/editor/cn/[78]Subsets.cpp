// Given an integer array nums of unique elements, return all possible subsets (
// the power set).
//
//  The solution set must not contain duplicate subsets. Return the solution in
// any order.
//
//
//  Example 1:
//
//
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//
//
//  Example 2:
//
//
// Input: nums = [0]
// Output: [[],[0]]
//
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 10
//  -10 <= nums[i] <= 10
//  All the numbers of nums are unique.
//
//
//  Related Topics 位运算 数组 回溯 👍 2484 👎 0
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> sub_set;
        ans.push_back({});
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            BackTracking(ans, nums, sub_set, i, 0);
        }
        return ans;
    }

   private:
    void BackTracking(std::vector<std::vector<int>>& ans,
                      std::vector<int>& nums, std::vector<int>& sub_set, int N,
                      int start) {
        if (sub_set.size() == N) {
            ans.push_back(sub_set);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            sub_set.push_back(nums[i]);
            BackTracking(ans, nums, sub_set, N, i + 1);
            sub_set.pop_back();
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
