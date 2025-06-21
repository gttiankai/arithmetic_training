// Given an integer array nums, find a subarray that has the largest product,
// and return the product.
//
//  The test cases are generated so that the answer will fit in a 32-bit
//  integer.
//
//
//
//  Example 1:
//
//
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
//
//
//  Example 2:
//
//
// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 2 * 10⁴
//  -10 <= nums[i] <= 10
//  The product of any subarray of nums is guaranteed to fit in a 32-bit
//  integer.
//
//
//
//  Related Topics 数组 动态规划 👍 2451 👎 0

#include <iostream>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 时间复杂度: O(N!)
     * 空间复杂度: O(N^2)
     * 下面的实现超时了, 需要对下面的代码进行
     ***/
    int maxProductTimeLimit(std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = nums[j];
                } else {
                    dp[i][j] = nums[j] * dp[i][j - 1];
                }
            }
        }
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                max = std::max(max, dp[i][j]);
            }
        }
        return max;
    }
    /**
     * max_dp[i] 代表以 nums[i] 为结尾的子数组的最大积.
     * min_dp[i] 代表以 nums[i] 为结尾的子数组的最小积.
     * max_dp[i] = max(nums[i], max_dp[i-1] * nums[i], min_dp[i-1] * nums[i])
     * min_dp[i] = min(nums[i], max_dp[i-1] * nums[i], min_dp[i-1] * nums[i])
     *
     * 时间复杂度: O(N)
     * 空间复杂度: O(1)
     ***/
    int maxProduct(std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n   = nums.size();
        int max = nums[0];
        int min = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            // 注意下面的代码需要将 max 和 min 进行暂存,要不然计算 max 之后,会污染后面的数据
            int max_temp = max;
            int min_temp = min;

            max = std::max(std::max(nums[i], max_temp * nums[i]),
                           min_temp * nums[i]);
            min = std::min(std::min(nums[i], max_temp * nums[i]),
                           min_temp * nums[i]);
            ans = std::max(ans, max);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<int> nums = {-4, -3, -2};
    Solution solution;
    std::cout << solution.maxProduct(nums);
}
