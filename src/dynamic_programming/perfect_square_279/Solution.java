/**
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * Example 1:
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 *
 * Example 2:
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 *
 * */
package dynamic_programming.perfect_square_279;

public class Solution {

    /**
     * 这个思路不能解决所有的问题:
     *
     * 例如 n = 13
     *      12 = 9 + 1 + 1 +1
     *      12 = 4 + 4 + 4
     * 按照本题目的逻辑,是解决不了这个问题的
     * */
    public int numSquaresFailed(int n) {
        if (n <= 0) {
            return 0;
        }
        int count = 0;
        while (n != 0) {
            count++;
            int quo = (int)Math.sqrt(n);
            System.out.println("" + quo);
            n = (int) (n - Math.pow(quo,2));
        }
        return count;
    }

    /**
     * 子问题:
     *  i: 是 sum,也就是需要求 perfect square的 正整数
     *  dp[i] 是要求的 perfect square 的数目
     *
     *  dp[i] = min(dp[i - j^2]) 其中 j 是从 1 到 (j^2 <= i)
     * */
    public int numSquaresdp(int n) {
        if (n <= 0) {
            return 0;
        }
        int[] dp = new int[n+1];
        dp[0] = 0;
        for (int i = 1; i < n+1; i++) {
            dp[i] = Integer.MAX_VALUE;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = Math.min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }

    public static void main(String[] arguments) {
        Solution solution = new Solution();
        System.out.printf("" + solution.numSquaresdp(12));
    }
}
