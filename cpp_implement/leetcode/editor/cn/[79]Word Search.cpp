// Given an m x n grid of characters board and a string word, return true if
// word exists in the grid.
//
//  The word can be constructed from letters of sequentially adjacent cells,
// where adjacent cells are horizontally or vertically neighboring. The same
// letter cell may not be used more than once.
//
//
//  Example 1:
//
//
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
// =
//  "ABCCED"
// Output: true
//
//
//  Example 2:
//
//
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
// =
//  "SEE"
// Output: true
//
//
//  Example 3:
//
//
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
// =
//  "ABCB"
// Output: false
//
//
//
//  Constraints:
//
//
//  m == board.length
//  n = board[i].length
//  1 <= m, n <= 6
//  1 <= word.length <= 15
//  board and word consists of only lowercase and uppercase English letters.
//
//
//
//  Follow up: Could you use search pruning to make your solution faster with a
// larger board?
//
//  Related Topics 深度优先搜索 数组 字符串 回溯 矩阵 👍 1994 👎 0
#include <string>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        std::vector<std::vector<bool>> flags =
            std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    flags[i][j] = true;
                    if (BackTracking(board, flags, i, j, word, 1)) {
                        return true;
                    }
                    flags[i][j] = false;
                }
            }
        }
        return false;
    }

    bool BackTracking(std::vector<std::vector<char>>& board,
                      std::vector<std::vector<bool>>& flags, int i, int j,
                      std::string& word, int start) {
        int m = board.size();
        int n = board[0].size();
        if (start == word.size()) {
            return true;
        }
        if (i - 1 >= 0 && !flags[i - 1][j] && board[i - 1][j] == word[start]) {
            flags[i - 1][j] = true;
            if (BackTracking(board, flags, i - 1, j, word, start + 1)) {
                return true;
            }
            flags[i - 1][j] = false;
        }
        if (i + 1 < m && !flags[i + 1][j] && board[i + 1][j] == word[start]) {
            flags[i + 1][j] = true;
            if (BackTracking(board, flags, i + 1, j, word, start + 1)) {
                return true;
            }
            flags[i + 1][j] = false;
        }
        if (j - 1 >= 0 && !flags[i][j - 1] && board[i][j - 1] == word[start]) {
            flags[i][j - 1] = true;
            if (BackTracking(board, flags, i, j - 1, word, start + 1)) {
                return true;
            }
            flags[i][j - 1] = false;
        }
        if (j + 1 < n && !flags[i][j + 1] && board[i][j + 1] == word[start]) {
            flags[i][j + 1] = true;
            if (BackTracking(board, flags, i, j + 1, word, start + 1)) {
                return true;
            }
            flags[i][j + 1] = false;
        }
        return false;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
