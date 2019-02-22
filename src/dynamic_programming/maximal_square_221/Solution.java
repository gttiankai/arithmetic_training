/**
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest
 *
 * square containing only 1's and return its area.
 *
 * Example:
 *
 * Input:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * Output: 4
 * */

package dynamic_programming.maximal_square_221;

public class Solution {
    /**
     * if matrix[i][j]  
     *  : = 0;  -> dp[i][j] = 0
     *  : = 1;  -> dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
     * 
     * dp(i,j) : represents the side length of the maximum square whose bottom right corner is the cell with index(i,j)
     *
     * in the original matrix.
     *
     * */
    public int maximalSquare(char[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return 0;
        }
        int rows = matrix.length;
        int cols = rows > 0 ? matrix[0].length: 0;
        int[][] dp = new int[rows + 1][cols + 1];
        int maxArea = 0;
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= cols; j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = Math.min(Math.min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                    maxArea = Math.max(maxArea, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        // 最终求出来的是长度
        return maxArea*maxArea;
    }
    public int maximalSquareBetter(char[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return 0;
        }
        int rows = matrix.length;
        int cols = rows > 0 ? matrix[0].length: 0;
        int[] dp = new int[cols + 1];
        int maxArea = 0;
        int prev = 0;
        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= cols; j++) {
                int temp = dp[j];
                if (matrix[i-1][j-1] == '1') {
                    // 因为 dp[j]是复用的,所以 dp[j]其实是上一个循环留下的值
                    dp[j] = Math.min(Math.min(dp[j - 1], prev), dp[j]) + 1;
                    maxArea = Math.max(maxArea, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        // 最终求出来的是长度
        return maxArea*maxArea;
    }
}
