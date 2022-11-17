package dynamic_programming.target_sum_494;

import java.util.Arrays;

public class Solution1 {

    public int findTargetSumWays(int[] nums, int S) {
        // 讲真的,这个算法真的看不懂,不知道怎么弄得.
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int sum = 0;
        for (Integer num :
                nums) {
            sum += num;
        }
        if (sum < S || (sum + S) % 2 != 0) {
            return 0;
        }
        int target = (sum + S) / 2;
        int n = nums.length;
        int[][] dp = new int[n + 1][target + 1];
        Arrays.fill(dp[0], 0);
        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < target + 1; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]] ;
                }
            }
        }

        return dp[n][target];
    }

    public static void main(String[] arguments) {
        int[] nums = new int[]{1, 1, 1, 1, 1};
        int S = 3;
        Solution1 solution = new Solution1();
        System.out.println(solution.findTargetSumWays(nums, S));
    }
}
