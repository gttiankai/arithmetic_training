// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
// validated according to the following rules:
//
//
//  Each row must contain the digits 1-9 without repetition.
//  Each column must contain the digits 1-9 without repetition.
//  Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
// without repetition.
//
//
//  Note:
//
//
//  A Sudoku board (partially filled) could be valid but is not necessarily
// solvable.
//  Only the filled cells need to be validated according to the mentioned rules.
//
//
//
//
//  Example 1:
//
//
// Input: board =
//[["5","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
// Output: true
//
//
//  Example 2:
//
//
// Input: board =
//[["8","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner
// being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
// is invalid.
//
//
//
//  Constraints:
//
//
//  board.length == 9
//  board[i].length == 9
//  board[i][j] is a digit 1-9 or '.'.
//
//
//   Related Topics 数组 哈希表 矩阵 👍 1330 👎 0
#include <unordered_map>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 下面的实现就是完全按照定义实现的,所以性能有点慢
     * 需要遍历数组三次,下面的优化思路是减少遍历次数,是否可以只遍历一遍就可以解决
     * 问题?
     ***/
    bool isValidSudokuSlow(std::vector<std::vector<char>>& board) {
        // check every row
        for (int i = 0; i < 9; i++) {
            std::unordered_map<char, int> board_map;
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                if (board_map.find(c) != board_map.end()) {
                    return false;
                }
                board_map[c]++;
            }
        }
        for (int i = 0; i < 9; i++) {
            std::unordered_map<char, int> board_map;
            for (int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c == '.') {
                    continue;
                }
                if (board_map.find(c) != board_map.end()) {
                    return false;
                }
                board_map[c]++;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::unordered_map<char, int> board_map;
                for (int m = i * 3; m < i * 3 + 3; m++) {
                    for (int n = j * 3; n < j * 3 + 3; n++) {
                        char c = board[m][n];
                        if (c == '.') {
                            continue;
                        }
                        if (board_map.find(c) != board_map.end()) {
                            return false;
                        }
                        board_map[c]++;
                    }
                }
            }
        }
        return true;
    }

    /**
     * 只遍历一次数组就要解决问题
     **/
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // 这个题目居然错在了数组的定义上了, 此处需要注意
        int rows[9][9]       = {0};
        int columns[9][9]    = {0};
        int sub_box[3][3][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int index = c - '1';
                rows[i][index]++;
                if (rows[i][index] > 1) {
                    return false;
                }
                columns[j][index]++;
                if (columns[j][index] > 1) {
                    return false;
                }
                // 此处的 index 其实就是数值,并不是要找到该值对应的下表
                sub_box[i / 3][j / 3][index]++;
                if (sub_box[i / 3][j / 3][index] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
