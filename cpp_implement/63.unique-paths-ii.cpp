/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.cn/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (41.05%)
 * Likes:    1051
 * Dislikes: 0
 * Total Accepted:    373.2K
 * Total Submissions: 909K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * You are given an m x n integer array grid. There is a robot initially
 * located at the top-left corner (i.e., grid[0][0]). The robot tries to move
 * to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only
 * move either down or right at any point in time.
 *
 * An obstacle and space are marked as 1 or 0 respectively in grid. A path that
 * the robot takes cannot include any square that is an obstacle.
 *
 * Return the number of possible unique paths that the robot can take to reach
 * the bottom-right corner.
 *
 * The testcases are generated so that the answer will be less than or equal to
 * 2 * 10^9.
 *
 *
 * Example 1:
 *
 *
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 *
 *
 * Example 2:
 *
 *
 * Input: obstacleGrid = [[0,1],[0,0]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] is 0 or 1.
 *
 *
 */
#include <iostream>
#include <vector>

// @lc code=start
class Solution {
 public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    int M    = obstacleGrid.size();
    int N    = obstacleGrid[0].size();
    auto dp  = std::vector<std::vector<int>>(M, std::vector<int>(N));
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
      if (obstacleGrid[0][i] == 1) {
        for (int j = i; j < N; ++j) {
          dp[0][i] = 0;
        }
        break;
      }
      dp[0][i] = 1;
    }
    for (int i = 0; i < M; ++i) {
      if (obstacleGrid[i][0] == 1) {
        for (int j = i; j < M; ++j) {
          dp[i][0] = 0;
        }
        break;
      }
      dp[i][0] = 1;
    }
    for (int i = 1; i < M; ++i) {
      for (int j = 1; j < N; ++j) {
        if (obstacleGrid[i][j] == 0) {
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        } else {
          dp[i][j] = 0;
        }
      }
    }
    return dp[M - 1][N - 1];
  }
};
// @lc code=end
int main(int argc, char* argv[]) {
  std::vector<std::vector<int>> obstacle_grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  Solution solution;
  std::cout << solution.uniquePathsWithObstacles(obstacle_grid) << std::endl;

  return 0;
}
