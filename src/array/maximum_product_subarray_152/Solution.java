/**
 * Given an integer array nums, find the contiguous subarray within an array (containing at least one number)
 *
 * which has the largest product(乘积).
 *
 * Example 1:
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * Example 2:
 *
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 *
 * */
package array.maximum_product_subarray_152;


public class Solution {
    /**
     * dp(i): 表示subarray 以 i 为结尾的 maximum product
     *
     * unite test: failed! {-2, 3, -4}
     * output:  3
     * expect:  24
     * */
    public int maxProductFailed(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = nums[0];
        int maxValue = dp[0];
        int minValue = dp[0];
        int ans = maxValue;
        for (int i = 1; i < n; i++) {
//            if (signEquality(dp[i - 1], nums[i])) {
//                dp[i] = dp[i - 1] * nums[i];
//            } else {
//                dp[i] = nums[i];
//            }
//            if (maxValue < dp[i]) {
//                maxValue = dp[i];
//            }
            /**
             * tmp 的作用是为了暂存上一次的 maxvalue
             * minValue 的作用是为了解决正负号的问题,如果都是正数的话,就可以只用 minValue 就可以了.
             * */
            int tmp =  Math.max(Math.max(maxValue*nums[i], minValue*nums[i]), nums[i]);
            minValue = Math.min(Math.min(maxValue*nums[i], minValue*nums[i]), nums[i]);
            maxValue = tmp;
            ans = Math.max(ans, maxValue);
        }
        return ans;
    }
    public static void main(String[] argument) {
        int[] nums= {-4,-3,-2};
        Solution solution = new Solution();
        System.out.println(solution.maxProductFailed(nums));
    }
}
