/**
 * Given a non-empty array containing only positive integers, find if
 *
 * the array can be partitioned into two subsets such that the sum of
 *
 * elements in both subsets is equal.
 *
 * Note:
 *
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 *
 *
 * Example 1:
 *
 * Input: [1, 5, 11, 5]
 *
 * Output: true
 *
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 * Example 2:
 *
 * Input: [1, 2, 3, 5]
 *
 * Output: false
 *
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 * */

package dynamic_programming.partition_equal_subset_sum_416;

import java.util.Arrays;

public class Solution {
    public boolean canPartition(int[] nums) {
        if( nums == null || nums.length < 2) {
            return false;
        }
        int n = nums.length;
        int sum = 0;
        for (Integer item : nums) {
            sum += item;
        }
        if (sum %2 != 0) {
            return false;
        }
        int target = sum / 2;
        boolean[][] dp = new boolean[n+1][target+1];
        dp[0][0] = true;
        for (int i = 0; i < n+1; i++) {
            dp[i][0] = true;
        }
        for (int j = 0; j < target + 1; j++) {
            dp[0][j] = false;
        }
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < target+1; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1] ) {
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j - nums[i-1]]);
                }
            }
        }
        return dp[n][target];
    }
    public static void main(String[] arguments) {
        int[] nums = new int[] {1, 5, 11};
        Solution solution = new Solution();
        System.out.println(solution.canPartition(nums));
    }
}
