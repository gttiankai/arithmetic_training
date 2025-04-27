// Given a collection of numbers, nums, that might contain duplicates, return
// all possible unique permutations in any order.
//
//
//  Example 1:
//
//
// Input: nums = [1,1,2]
// Output:
//[[1,1,2],
//  [1,2,1],
//  [2,1,1]]
//
//
//  Example 2:
//
//
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 8
//  -10 <= nums[i] <= 10
//
//
//  Related Topics 数组 回溯 排序 👍 1708 👎 0

#include <__ostream/basic_ostream.h>

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        std::vector<bool> used_flags(nums.size(), false);
        std::vector<int> permutation;
        BackTracking(ans, nums, used_flags, permutation);
        return ans;
    }

   private:
    void BackTracking(std::vector<std::vector<int>>& ans,
                      std::vector<int>& nums, std::vector<bool>& used_flags,
                      std::vector<int>& permutation) {
        if (permutation.size() == nums.size()) {
            ans.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used_flags[i] == true) {
                continue;
            }
            // 核心思想保证:
            // 每次填入的数一定是这个数所在重复数集合中「从左往右第一个未被填过的数字」，
            // 解决下面的题目,要记得并不能将数组截断,如果将数组截断,
            // 如何进行重复数组的判断呢?
            if (i > 0 && nums[i] == nums[i - 1] && used_flags[i - 1] == false) {
                continue;
            }

            used_flags[i] = true;
            permutation.push_back(nums[i]);
            BackTracking(ans, nums, used_flags, permutation);
            permutation.pop_back();
            used_flags[i] = false;
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> test_case = {{1, 1}, {1, 1, 2}, {1, 2, 3}};
    for (int i = 0; i < test_case.size(); ++i) {
        auto ans = solution.permuteUnique(test_case[i]);
        std::cout << "permutation size: " << ans.size() << std::endl;
    }
    return 0;
}
