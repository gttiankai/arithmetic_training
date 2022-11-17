package dynamic_programming.partition_equal_subset_sum_416;

import java.util.Arrays;

public class Solution1 {
    public boolean canPartition(int[] nums) {
        if (nums == null || nums.length < 2) {
            return false;
        }
        int n = nums.length;
        int sum = 0;
        for (Integer item : nums) {
            sum += item;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        boolean[] dp = new boolean[target +1];
        Arrays.fill(dp,false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i > 0; i--) {
                if (i >= num) {
                    dp[i] = dp[i] || dp[i-num];
                }
            }
        }
        return dp[target];
    }

    public static void main(String[] arguments) {
        int[] nums = new int[]{1, 5, 11};
        Solution solution = new Solution();
        System.out.println(solution.canPartition(nums));
    }
}
