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
 * If you have figured out the O(n) solution, try coding another solution using the divide
 * and conquer approach, which is more subtle.
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


//            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);

            /**
             * 以下的这个解法是错误的
             * */
            if (nums[i] < 0) {
                dp[i] = dp[i-1];
            } else {
                // 这个逻辑是错误的，这是因为当前的 nums[i] 大于0时，但是 nums[i]比较小的情况下，
                // nums[i-1] 有比较大的情况下，这是时候，就不能简单的添加 nums[i]了
                dp[i] = Math.max(dp[i - 1] + nums[i], dp[i-1]);
            }

            /**
             * 这个算法的关键是对 dp[] 的理解.
             * dp[i] : 以 nums[i]为结尾的最大的连续子序列.
             * */
//            if (dp[i-1] < 0) {
//                dp[i] = nums[i];
//            } else {
//                dp[i] = nums[i] + dp[i-1];
//            }

            max = Math.max(max, dp[i]);
        }
        return max;
    }

    /**
    * 下面方法错误原因是对 dp 的抽象是不合适的.对 dp[i]的抽象为从(0,i)的序列上的和最大的子序列
    *
    * */
    public static int maxSubArrayDF2(int[] nums) {

        if (nums  == null){
            return 0;
        }
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        int n = nums.length;
        int maxSofar = Integer.MIN_VALUE;
        int maxEndingHere = Integer.MIN_VALUE;
        for (int i = 0;i < n; i++) {
            //maxEndingHere = Math.max(maxEndingHere + nums[i], nums[i]);
            //maxSofar = Math.max(maxSofar, maxEndingHere+[);
        }
        return maxSofar;

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
