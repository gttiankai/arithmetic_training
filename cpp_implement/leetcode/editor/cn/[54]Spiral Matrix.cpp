// Given an m x n matrix, return all elements of the matrix in spiral order.
//
//
//  Example 1:
//
//
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
//  Example 2:
//
//
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//
//
//
//  Constraints:
//
//
//  m == matrix.length
//  n == matrix[i].length
//  1 <= m, n <= 10
//  -100 <= matrix[i][j] <= 100
//
//
//  Related Topics 数组 矩阵 模拟 👍 1921 👎 0
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int m     = matrix.size();
        int n     = matrix[0].size();
        int total = m * n;
        int i     = 0;
        int j     = 0;
        std::vector<int> ans;
        std::vector<std::vector<bool>> flags(m, std::vector<bool>(n, false));
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction_index = 0;
        for (int num = 0; num < total; ++num) {
            ans.push_back(matrix[i][j]);
            flags[i][j] = true;
            // next_i 和 next_j  存在的意义就是判断是否需要拐弯了,
            // 如果只使用 i 和 j 进行判断的话,代码实现起来就会比较麻烦
            int next_i  = i + direction[direction_index][0];
            int next_j  = j + direction[direction_index][1];
            if (next_j >= n || next_i >= m || next_i < 0 || next_j < 0 ||
                flags[next_i][next_j]) {
                // 这个地方要进行模运算,当 m 和 n 的次数比较大时,会拐弯多次,
                direction_index = (direction_index + 1) % 4;
            }
            i += direction[direction_index][0];
            j += direction[direction_index][1];
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> matrix = {{7}, {9}, {6}};
    auto ans = solution.spiralOrder(matrix);
}
