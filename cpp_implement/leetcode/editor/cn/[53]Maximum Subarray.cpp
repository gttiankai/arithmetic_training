
//
//
// Example 1:
//
//
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
//
//
// Example 2:
//
//
// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
//
//
// Example 3:
//
//
// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
//
//
//
// Constraints:
//
//
// 1 <= nums.length <= 10⁵
// -10⁴ <= nums[i] <= 10⁴
//
//
//
// Follow up: If you have figured out the O(n) solution, try coding another
// solution using the divide and conquer approach, which is more subtle.
//
// Related Topics 数组 分治 动态规划 👍 7018 👎 0
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /***
     * 动态规划类的题目最重要的就是找到子问题,
     * 这个题目的子问题:
     *     以 nums[i] 结尾的连续子数组的最大和
     * 时间复杂度:  O(N),
     * 空间复杂度:  O(N)
     **/
    int maxSubArray(std::vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0]   = nums[0];
        int max = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
