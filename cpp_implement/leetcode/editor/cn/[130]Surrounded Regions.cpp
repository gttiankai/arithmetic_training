// You are given an m x n matrix board containing letters 'X' and 'O', capture
// regions that are surrounded:
//
//
//  Connect: A cell is connected to adjacent cells horizontally or vertically.
//  Region: To form a region connect every 'O' cell.
//  Surround: The region is surrounded with 'X' cells if you can connect the
// region with 'X' cells and none of the region cells are on the edge of the
// board.
//
//
//  To capture a surrounded region, replace all 'O's with 'X's in-place within
// the original board. You do not need to return anything.
//
//
//  Example 1:
//
//
//  Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X",
//"O","X","X"]]
//
//
//  Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X",
//"X"]]
//
//  Explanation:
//
//  In the above diagram, the bottom region is not captured because it is on the
// edge of the board and cannot be surrounded.
//
//  Example 2:
//
//
//  Input: board = [["X"]]
//
//
//  Output: [["X"]]
//
//
//  Constraints:
//
//
//  m == board.length
//  n == board[i].length
//  1 <= m, n <= 200
//  board[i][j] is 'X' or 'O'.
//
//
//  Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 1217 👎 0

#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    void solve(std::vector<std::vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        std::vector<std::vector<bool>> flags(m, std::vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            UpdateFlags(board, flags, i, 0);
            UpdateFlags(board, flags, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            UpdateFlags(board, flags, 0, j);
            UpdateFlags(board, flags, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (flags[i][j] != true) {
                    board[i][j] = 'X';
                }
            }
        }
    }

   private:
    /**
     * 广度优先遍历
     ***/
    void UpdateFlags(std::vector<std::vector<char>>& board,
                     std::vector<std::vector<bool>>& flags, int row, int col) {
        if (board[row][col] != 'O') {
            return;
        }
        flags[row][col] = true;
        int m = board.size(), n = board[0].size();
        // update
        if (check(m, n, row - 1, col) && flags[row - 1][col] == false) {
            UpdateFlags(board, flags, row - 1, col);
        }
        // down
        if (check(m, n, row + 1, col) && flags[row + 1][col] == false) {
            UpdateFlags(board, flags, row + 1, col);
        }
        // left
        if (check(m, n, row, col + 1) && flags[row][col + 1] == false) {
            UpdateFlags(board, flags, row, col + 1);
        }
        if (check(m, n, row, col - 1) && flags[row][col - 1] == false) {
            UpdateFlags(board, flags, row, col - 1);
        }
    }
    bool check(const int m, const int n, int i, int j) {
        if (0 <= i && i < m && 0 <= j && j < n) {
            return true;
        } else {
            return false;
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    // std::vector<std::vector<char>> board = {{'O', 'O'}, {'O', 'O'}};
    std::vector<std::vector<char>> board = {
        {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X'},
    };
    solution.solve(board);
}
