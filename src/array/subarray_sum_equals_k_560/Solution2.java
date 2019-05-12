package array.subarray_sum_equals_k_560;

import java.util.Arrays;

public class Solution2 {
    /**
     * Runtime: 196 ms, faster than 5.07% of Java online submissions for Subarray Sum Equals K.
     *
     * 经过提醒,使用新的方法将 O(n^3)的时间复杂度降低到了 O(n^2),测试通过了.
     *
     * */
    public int subarraySum(int[] nums, int k) {

        if (nums == null || nums.length == 0) {
            return 0;
        }
        int count = 0;
        int n = nums.length;
        int[] sum = new int[n+1];
        sum[0] = 0;
        for (int i = 1; i <= n; i++){
            sum[i] = sum[i-1] + nums[i-1];
        }
        for (int window = 1; window <= n; window++) {
            for (int i = 0; i + window <= nums.length; i++) {
                int tmpSum = sum[i+window] - sum[i];
                if (tmpSum == k) {
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] arguments) {
        int[] nums = new int[]{1, 1, 1};
        int k = 2;
        Solution2 solution2 = new Solution2();
        System.out.println(solution2.subarraySum(nums, k));
    }
}
