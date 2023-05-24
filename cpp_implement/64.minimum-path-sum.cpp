/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.cn/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (69.50%)
 * Likes:    1504
 * Dislikes: 0
 * Total Accepted:    484.6K
 * Total Submissions: 697.3K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 200
 *
 *
 */
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

// @lc code=start
/*
1. dp(m, n) = min(dp(m-1, n) + grid[m][n] , dp(m, n-1) + grid[m][n])

 */
class Solution {
 public:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    int M = grid.size();
    int N = grid[0].size();
    std::vector<std::vector<int>> dp(M, std::vector<int>(N));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < N; ++i) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < M; ++i) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < M; ++i) {
      for (int j = 1; j < N; ++j) {
        dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
    return dp[M - 1][N - 1];
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  Solution solution;
  std::cout << solution.minPathSum(grid) << std::endl;
  return 0;
}
