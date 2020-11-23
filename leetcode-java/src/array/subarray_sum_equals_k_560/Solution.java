/**
 * Given an array of integers and an integer k, you need to find the total
 *
 * number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 *
 * Note:
 * The length of the array is in range [1, 20,000].
 *
 * The range of numbers in the array is [-1000, 1000] and the range of
 *
 * the integer k is [-1e7, 1e7].
 *
 *
 * */

package array.subarray_sum_equals_k_560;

import java.util.Arrays;

public class Solution{

    /**
     * 使用 01 背包解决数组之后等于某个值的情况,
     * 但是最后使用 01 背包问题不能解决这个问题,原因是因为题目中的 k 有可能出现负值的情况,
     * 但是 01 背包问题中是不能出现 target 为负值的情况的.所以不能使用01 背包解法进行求解.
     * */
    public int subarraySum(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int count = 0;
        for (int window = 1; window < nums.length; window++) {
            for (int i = 0; i + window <= nums.length; i++) {
                int[] tmp = Arrays.copyOfRange(nums, i, i + window);
                if (canPartition(tmp, k)) {
                    count++;
                }
            }
        }
        return count;
    }


    private boolean canPartition(int[] nums, int target) {
        int sum = 0;
        for (Integer item : nums) {
            sum += item;
        }
        if (sum < target) {
            return false;
        }
        boolean[] dp = new boolean[target + 1];
        Arrays.fill(dp, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i > 0; i--) {
                if ( i-num>=0 && i - num < target+1) {
                    dp[i] = dp[i] || dp[i - num];
                }
            }
        }
        return dp[target];
    }

    public static void main(String[] arguments) {
        //[-92,-63,75,-86,-58,22,31,-16,-66,-67,420]
        //100
        int[] nums = new int[]{-92,-63,75,-86,-58,22,31,-16,-66,-67,420};
        int k = 100;
        Solution solution = new Solution();
        System.out.println(solution.subarraySum(nums, k));
    }
}
