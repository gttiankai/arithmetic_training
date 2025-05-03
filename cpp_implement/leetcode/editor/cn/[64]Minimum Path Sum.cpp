//Given a m x n grid filled with non-negative numbers, find a path from top 
//left to bottom right, which minimizes the sum of all numbers along its path. 
//
// Note: You can only move either down or right at any point in time. 
//
// 
// Example 1: 
// 
// 
//Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
//Output: 7
//Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// 
//
// Example 2: 
//
// 
//Input: grid = [[1,2,3],[4,5,6]]
//Output: 12
// 
//
// 
// Constraints: 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 200 
// 0 <= grid[i][j] <= 200 
// 
//
// Related Topics 数组 动态规划 矩阵 👍 1816 👎 0
#include <vector>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) {
            return grid[0][0];
        }
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> grid = {{9, 1, 4, 8}};
    Solution solution;
    solution.minPathSum(grid);
}
