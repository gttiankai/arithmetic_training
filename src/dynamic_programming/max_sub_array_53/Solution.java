/**
 *  Given an integer array nums, find the contiguous subarray (containing at least one number)
 *  which has the largest sum and return its sum.
 *
 * Example:
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer
 * approach, which is more subtle.
 *
 * */

package dynamic_programming.max_sub_array_53;

public class Solution {
    /**
     * dynamic programming
     * time complexity  O(n)
     * */
    public static int maxSubArray(int[] nums) {
        if (nums  == null){
            return 0;
        }
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        int n = nums.length;
        /**
         * sub problem: dp[i]
         * */
        //dp[i] means the maximum sub array ending with A[i];
        int[] dp = new int[n];
        dp[0] = nums[0];
        int max = dp[0];

        for(int i = 1; i < n; i++){
            //
            if (dp[i-1] < 0) {
                dp[i] = nums[i];
            } else {
                dp[i] = nums[i] + dp[i-1];
            }
            //dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            // max 的这一行比较关键，
            max = Math.max(max, dp[i]);
        }
        return max;
    }
    /**
     *
     *
     * */
    public static int maxSubArrayBF(int[] nums) {
        if (nums  == null){
            return 0;
        }
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        int n = nums.length;
        int max = 0;
        //dp[i] means the maximum sub array ending with A[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 遍历数组，将所有的连续的数组遍历出来，然后依次计算出来，找到最大的就就可了。
            }
        }
        return max;
    }

    public static void main(String[] arguments) {
        int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println("the value:" + maxSubArray(nums));
    }

}
