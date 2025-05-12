// Given an integer array nums that may contain duplicates, return all possible
// subsets (the power set).
//
//  The solution set must not contain duplicate subsets. Return the solution in
// any order.
//
//
//  Example 1:
//  Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
//
//  Example 2:
//  Input: nums = [0]
// Output: [[],[0]]
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 10
//  -10 <= nums[i] <= 10
//
//
//  Related Topics 位运算 数组 回溯 👍 1307 👎 0
#include <algorithm>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        ans.push_back({});
        std::vector<int> sub_set;
        int size = nums.size();
        for (int n = 1; n <= size; n++) {
            BackTracking(ans, nums, sub_set, n, 0);
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
            if (i != start && nums[i - 1] == nums[i]) {
                continue;
            }
            sub_set.push_back(nums[i]);
            BackTracking(ans, nums, sub_set, N, i + 1);
            sub_set.pop_back();
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
