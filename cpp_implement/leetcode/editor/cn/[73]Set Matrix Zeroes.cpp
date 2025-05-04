// Given an m x n integer matrix matrix, if an element is 0, set its entire row
// and column to 0's.
//
//  You must do it in place.
//
//
//  Example 1:
//
//
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
//
//
//  Example 2:
//
//
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
//
//
//
//  Constraints:
//
//
//  m == matrix.length
//  n == matrix[0].length
//  1 <= m, n <= 200
//  -2³¹ <= matrix[i][j] <= 2³¹ - 1
//
//
//
//  Follow up:
//
//
//  A straightforward solution using O(mn) space is probably a bad idea.
//  A simple improvement uses O(m + n) space, but still not the best solution.
//  Could you devise a constant space solution?
//
//
//  Related Topics 数组 哈希表 矩阵 👍 1205 👎 0

#include <unordered_set>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    void setZeroesLargeSpace(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::unordered_set<int> row_set;
        std::unordered_set<int> col_set;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row_set.insert(i);
                    col_set.insert(j);
                }
            }
        }
        for (auto row : row_set) {
            for (int j = 0; j < n; ++j) {
                matrix[row][j] = 0;
            }
        }
        for (auto col : col_set) {
            for (int i = 0; i < m; ++i) {
                matrix[i][col] = 0;
            }
        }
    }


    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int m         = matrix.size();
        int n         = matrix[0].size();
        bool flag_row = false;
        bool flag_col = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                flag_row = true;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                flag_col = true;
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 第一行和第一列充当了标志位的作用,所以此时不能进行对第一行和第一列进行赋值,如果进行
        // 了赋值,标志位就改变了, 所以下标必须从 1 开始
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_row) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (flag_col) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
    }

    void setZeroesO1(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 第一列是否存在 0
        bool flag = false;
        for (int i = 0; i < m; i++) {
            // 下面两个判断的顺序非常重要
            if (matrix[i][0] == 0) {
                flag = true;
            }
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (flag) {
                matrix[i][0] = 0;
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
