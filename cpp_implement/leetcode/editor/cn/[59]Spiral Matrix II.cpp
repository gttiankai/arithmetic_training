// Given a positive integer n, generate an n x n matrix filled with elements
// from 1 to n² in spiral order.
//
//
//  Example 1:
//
//
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
//
//
//  Example 2:
//
//
// Input: n = 1
// Output: [[1]]
//
//
//
//  Constraints:
//
//
//  1 <= n <= 20
//
//
//  Related Topics 数组 矩阵 模拟 👍 1450 👎 0
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        std::vector<std::vector<bool>> flags(n, std::vector<bool>(n, false));
        std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
        int total = n * n;
        int i = 0;
        int j = 0;
        int direction_index = 0;
        for (int c = 0; c < total; c++) {
            ans[i][j] = c + 1;
            flags[i][j] = true;
            int next_i = direction[direction_index][0] + i;
            int next_j = direction[direction_index][1] + j;
            if (next_i >=n || next_j >= n || next_i < 0 || next_j < 0||flags[next_i][next_j]) {
                direction_index = (direction_index + 1) % 4;
            }
            i = direction[direction_index][0] + i;
            j = direction[direction_index][1] + j;
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
