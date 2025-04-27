// Given an array nums of distinct integers, return all the possible
// permutations. You can return the answer in any order.
//
//
//  Example 1:
//  Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//  Example 2:
//  Input: nums = [0,1]
// Output: [[0,1],[1,0]]
//
//  Example 3:
//  Input: nums = [1]
// Output: [[1]]
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 6
//  -10 <= nums[i] <= 10
//  All the integers of nums are unique.
//
//
//  Related Topics 数组 回溯 👍 3099 👎 0
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        // solution one
        int n = nums.size();
        std::vector<std::vector<int>> ans;
        std::vector<int> permutation;
        std::vector<bool> used(n, false);
        BackTrackingOne(ans, nums, used, n, permutation);
        return ans;
        // solution tow
        // std::vector<std::vector<int>> ans;
        // BackTrackingTwo(ans, nums, 0, nums.size());
        // return ans;
    }

   private:
    /**
     * 解法思路比较简单,除了需要额外的存储空间之外,没有其他问题
     **/
    void BackTrackingOne(std::vector<std::vector<int>>& ans,
                         std::vector<int>& nums, std::vector<bool>& used,
                         int count, std::vector<int>& permutation) {
        if (permutation.size() == count) {
            ans.push_back(permutation);
            return;
        }

        for (int i = 0; i < count; i++) {
            if (used[i] == false) {
                used[i] = true;
                permutation.push_back(nums[i]);
                BackTrackingOne(ans, nums, used, count, permutation);
                permutation.pop_back();
                used[i] = false;
            }
        }
    }
    /**
     * 下面了的解法节省了空间复杂度,主要是减少了标记数组
     *
     **/
    void BackTrackingTwo(std::vector<std::vector<int>>& ans,
                         std::vector<int>& nums, int first, int count) {


        if (first == count) {
            ans.push_back(nums);
            return;
        }
        for (int i = first; i < count; i++) {
            std::swap(nums[first], nums[i]);
            BackTrackingTwo(ans, nums, first + 1, count);
            std::swap(nums[first], nums[i]);
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
