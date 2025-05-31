// Given a triangle array, return the minimum path sum from top to bottom.
//
//  For each step, you may move to an adjacent number of the row below. More
// formally, if you are on index i on the current row, you may move to either
// index i or index i + 1 on the next row.
//
//
//  Example 1:
//
//
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
// above).
//
//
//  Example 2:
//
//
// Input: triangle = [[-10]]
// Output: -10
//
//
//
//  Constraints:
//
//
//  1 <= triangle.length <= 200
//  triangle[0].length == 1
//  triangle[i].length == triangle[i - 1].length + 1
//  -10⁴ <= triangle[i][j] <= 10⁴
//
//
//
// Follow up: Could you do this using only
// O(n) extra space, where
// n is the total number of rows in the triangle?
//
//  Related Topics 数组 动态规划 👍 1445 👎 0
#include <__ostream/basic_ostream.h>

#include <iostream>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * N 是 triangle 的行数
     * 时间复杂度: O(N!)
     * 空间复杂度: O(N!)
     ***/
    int minimumTotalComplex(std::vector<std::vector<int>>& triangle) {
        std::vector<std::vector<int>> dp;
        int level_size = triangle.size();
        for (int i = 0; i < level_size; ++i) {
            std::vector<int> level = triangle[i];
            if (i == 0) {
                dp.push_back(level);
                continue;
            }
            std::vector<int> dp_level;
            for (int j = 0; j < level.size(); ++j) {
                if (j == 0) {
                    dp_level.push_back(triangle[i][j] + dp[i - 1][j]);
                } else if (j == level.size() - 1) {
                    dp_level.push_back(triangle[i][j] + dp[i - 1][j - 1]);
                } else {
                    int min = std::min(dp[i - 1][j - 1], dp[i - 1][j]);
                    dp_level.push_back(min + level[j]);
                }
            }
            dp.push_back(dp_level);
        }
        int mini_num = INT_MAX;
        for (int i = 0; i < dp[level_size - 1].size(); ++i) {
            mini_num = std::min(mini_num, dp[level_size - 1][i]);
        }
        return mini_num;
    }
    /**
     * 我的思路是对的,我以为只能使用一个长度为 N 的数组,
     * 但是我看答案中的是使用了两个长度为 N 的数组
     ***/
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int row = triangle.size();
        int n   = triangle[row - 1].size();
        std::vector<std::vector<int>> dp =
            std::vector<std::vector<int>>(2, std::vector<int>(n, INT_MAX));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < row; ++i) {
            auto& level    = triangle[i];
            int level_size = level.size();
            // j == 0
            dp[i % 2][0] = dp[(i - 1) % 2][0] + level[0];
            // j: [1, level_size-2]
            for (int j = 1; j < level_size - 1; ++j) {
                dp[i % 2][j] = level[j] + std::min(dp[(i - 1) % 2][j - 1],
                                                   dp[(i - 1) % 2][j]);
            }
            // j = level.size() - 1
            dp[i % 2][level_size - 1] =
                dp[(i - 1) % 2][level_size - 2] + level[level_size - 1];
        }
        return *std::min_element(dp[(row - 1) % 2].begin(),
                                 dp[(row - 1) % 2].end());
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3},
    };
    Solution solution;
    int mini_nuuum = solution.minimumTotal(triangle);
    std::cout << "Get mini num:" << mini_nuuum << std::endl;
}
