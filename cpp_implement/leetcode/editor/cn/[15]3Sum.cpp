// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[
// k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] ==
// 0.
//
//  Notice that the solution set must not contain duplicate triplets.
//
//
//  Example 1:
//
//
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not
// matter.
//
//
//  Example 2:
//
//
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
//
//
//  Example 3:
//
//
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
//
//
//
//  Constraints:
//
//
//  3 <= nums.length <= 3000
//  -10⁵ <= nums[i] <= 10⁵
//
//
//  Related Topics 数组 双指针 排序 👍 7423 👎 0
#include <algorithm>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int> > threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int> > ans;
        int n = nums.size();
        // sort the array
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int k = n - 1;
            for (int j = i + 1; j < n - 1; j++) {
                if (j != 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                while (j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum > 0) {
                        k--;
                    } else {
                        break;
                    }
                }
                if (j == k) {
                    break;
                }
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
