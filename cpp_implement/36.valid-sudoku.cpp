/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.cn/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (63.05%)
 * Likes:    1108
 * Dislikes: 0
 * Total Accepted:    375.6K
 * Total Submissions: 595.7K
 * Testcase Example:
 '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 *
 * Note:
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 *
 * Example 1:
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 *
 * Example 2:
 *
 * Input: board =
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.

 * Constraints:
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit 1-9 or '.'.
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>

// @lc code=start
class Solution {
 public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::vector<std::vector<bool>> row_flag(9, std::vector<bool>(9, false));
    std::vector<std::vector<bool>> col_flag(9, std::vector<bool>(9, false));
    std::vector<std::vector<bool>> square_flag(9, std::vector<bool>(9, false));
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '1';
          if (row_flag[i][num]) {
            return false;
          } else {
            row_flag[i][num] = true;
          }
          if (col_flag[num][j]) {
            return false;
          } else {
            col_flag[num][j] = true;
          }
          int square_num = GetSquareNumber(i, j);
          if (square_flag[square_num][num]) {
            return false;
          } else {
            square_flag[square_num][num] = true;
          }
        }
      }
    }
    return true;
  }
 private:
  int GetSquareNumber(int m, int n) {
    if (n < 3) {
      // 0 ~ 2
      if (m < 3) {
        return 0;
      } else if (m < 6) {
        return 1;
      } else {
        return 2;
      }
    } else if (n < 6) {
      // 3 ~ 5
      if (m < 3) {
        return 3;
      } else if (m < 6) {
        return 4;
      } else {
        return 5;
      }
    } else {
      // 6 ~ 8
      if (m < 3) {
        return 6;
      } else if (m < 6) {
        return 7;
      } else {
        return 8;
      }
    }
  }
};

// @lc code=end

int main(int argc, char* argv[]) {
  Solution solution;
  std::cout << "do nothing for unit test" << std::endl;
  return 0;
}
