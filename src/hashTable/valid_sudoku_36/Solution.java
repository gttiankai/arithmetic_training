/**
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * <p>
 * Each row must contain the digits 1-9 without repetition.
 * 每一行包含1-9的数字,不能重复
 * Each column must contain the digits 1-9 without repetition.
 * 每一列包含1-9的数组,不能重复
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * 每个 3*3 的子盒子, 必须包含1~9得数字,不重复
 * A partially filled sudoku which is valid.
 * <p>
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * <p>
 * Example 1:
 * <p>
 * Input:
 * [
 * ["5","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * Example 2:
 * <p>
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner being
 * modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 * Note:
 * <p>
 * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.(数独板一定是 9*9)
 */

package hashTable.valid_sudoku_36;

public class Solution {
    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Valid Sudoku.
     * Memory Usage: 43.3 MB, less than 93.90% of Java online submissions for Valid Sudoku.
     * Next challenges:
     *
     * 没想到使用最笨得方法居然是最优解,哈哈,而且居然是我的第一个一次最优解得 medium 题目.
     *
     * */
    public boolean isValidSudoku(char[][] board) {
        int row = 9;
        int col = 9;

        // 行判断

        for (int i = 0; i < col; i++) {
            if (!isValidRow(board[i])) {
                return false;
            }
        }

        // 列判断
        for (int i = 0; i < row; i++) {
            if (!isValidCol(board, i)){
                return false;
            }
        }
        // sub-box 判断
        for (int i = 0; i < row; i +=3) {
            for (int j = 0; j < col; j+= 3 ) {
                if (!isValidSubBox(board, i, j)){
                    return false;
                }
            }
        }

        return true;
    }

    private boolean isValidRow(char[] chars) {
        boolean[] flags = new boolean[chars.length];
        for (int i = 0; i < chars.length; i++) {
            char value = chars[i];
            if (value != '.') {
                boolean flag = flags[value - '1'];
                if (flag == true) {
                    return false;
                } else {
                    flags[chars[i] - '1'] = true;
                }
            }
        }
        return true;
    }
    private boolean isValidCol(char[][] board, int col) {
        boolean[] flags = new boolean[9];
        for (int i = 0; i < 9; i++) {
            char value = board[i][col];
            if (value != '.') {
                boolean flag = flags[value - '1'];
                if (flag == true) {
                    return false;
                } else {
                    flags[value - '1'] = true;
                }
            }
        }
        return true;
    }

    private boolean isValidSubBox(char[][] board, int row, int col) {
        boolean[] flags = new boolean[9];
        for (int i = row; i < 3 + row; i++) {
            for (int j = col; j < 3 + col; j++) {
                char value = board[i][j];
                if (value != '.') {
                    boolean flag = flags[value - '1'];
                    if (flag == true) {
                        return false;
                    } else {
                        flags[value - '1'] = true;
                    }
                }
            }
        }
        return true;
    }

}
