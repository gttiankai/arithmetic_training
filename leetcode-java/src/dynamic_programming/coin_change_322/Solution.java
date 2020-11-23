/**
 * You are given coins of different denominations and a total amount of
 * <p>
 * money amount. Write a function to compute the fewest number of coins
 * <p>
 * that you need to make up that amount. If that amount of money cannot
 * <p>
 * be made up by any combination of the coins, return -1.
 * <p>
 * Example 1:
 * <p>
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * <p>
 * Example 2:
 * <p>
 * Input: coins = [2], amount = 3
 * Output: -1
 */

package dynamic_programming.coin_change_322;


import java.util.Arrays;

public class Solution {
    /**
     * 这个题目还是挺难的,那就难在如何进行递归问题的假设上以及如何界定初始状态
     *
     * dp[i][j] : i 为coins 的 index, j 为 amount 的值,
     *
     * dp 代表的意义是在 coins 数组中,从下标 i+1 到 n(n 是 coins 的最后一个下标),
     *
     * 组成 j,所需要最小的数目. 所以我们最终的目的是求 dp[0][amount]
     *
     * dp[i][j] = Min{  dp[i+1][j],
     *                  dp[i+1][j-coins[i]] + 1,
     *                  dp[i+1][j-coins[i]*2] + 2,
     *                  dp[i+1][j-coins[i]*3] + 3,
     *                  ....
     *                  ....
     *                  }
     * dp[i][j] = Min{  dp[i+1][j - coins[i]*k] + k |   0 <= k <= j/coins[i],
     *                                                  0 <= i <= n
     *                                                  0 <= j <= amount}
     *
     * base condition: dp[n][0] = 0, dp[n][1...n] = 无解,(可以设置为最大值)
     * 起始条件要从i最大的开始推导,因为 i 时,我们能够确定此时的状态
     *
     *
     * */
    public int coinChange(int[] coins, int amount) {
        if (null == coins || coins.length == 0) {
            return -1;
        }
        if (amount < 1) {
            return 0;
        }
        int n = coins.length;
        int[][] dp = new int[n + 1][amount + 1];

        Arrays.fill(dp[n], Integer.MAX_VALUE);
        dp[n][0] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = dp[i+1][j];
                int maxK = j / coins[i];
                for (int k = 1; k <= maxK; k++) {
                    int prev = dp[i + 1][j - k * coins[i]];
                    /*
                    * 这个判断语句一定要加上,如果不加上的话,会出现Integer.MAX_VALUE + k
                    * 出现溢出的情况,这样就会产生问题.
                    * */
                    if(prev < Integer.MAX_VALUE) {
                        dp[i][j] = Math.min(dp[i][j],prev + k);
                    }
                }
            }
        }
        if (dp[0][amount] == Integer.MAX_VALUE){
            return -1;
        } else {
            return dp[0][amount];
        }
    }

    public static void main(String[] arguments) {
        int[] coins = new int[]{2};
        int amount = 3;
        Solution solution = new Solution();
        System.out.println("the output: " + solution.coinChange(coins, amount));
    }
}
