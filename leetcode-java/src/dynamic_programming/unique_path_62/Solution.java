/**
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right
 *
 * corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 * Example 2:
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 * Unit test:
 * Input: m = 1, n = 1
 * Output: 1
 * */

package dynamic_programming.unique_path_62;

public class Solution {
    public static int uniquePaths(int m, int n) {
        /**
         * sub problem: dp[i][j] 是到这个节点的所有所有的路劲，
         * 这个子问题的假设就很简单，你只需要缩小问题的规模就可以，并不需要假设其他的问题
         * */
        int[][] dp = new int[m][n];
        dp[0][0] = 1;
        /*
        * 另外一个需要注意的点：就是需要对一部分内容进行初始化的操作。不要太死脑筋。
        * */
        for (int i = 1; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    public static void main(String[] arguments) {
        System.out.println(uniquePaths(3, 2));
    }

}
