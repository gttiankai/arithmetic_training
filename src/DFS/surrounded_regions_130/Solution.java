/**
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded region.
 *
 * Example:
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * Explanation:
 *
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the
 *
 * board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an
 *
 * 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells
 *
 * connected horizontally or vertically.
 *
 * */
package DFS.surrounded_regions_130;

public class Solution {
    /**
     * 没有理解清楚题意, 对题目是联通的,没有理解深刻
     * */
    public void solve(char[][] board) {
        if (board == null || board.length == 0||board[0].length == 0) {
            return;
        }
        int m = board.length;
        int n = board[0].length;
        boolean[][] flags = new boolean[m][n];
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (surrounded(board, i, j)) {
                    flags[i][j] = true;
                }
            }
        }
        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (flags[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    private boolean surrounded(char[][] board, int row, int col) {
        int m = board.length;
        int n = board[0].length;
        boolean up = false;
        boolean down = false;
        boolean left = false;
        boolean right = false;
        int i = 1;
        // left
        while (col - i >= 0) {
            if (board[row][col - i] == 'X') {
                left = true;
                break;
            }
            i++;

        }
        i = 1;
        // rigth
        while (col + i < n) {
            if (board[row][col + i] == 'X') {
                right = true;
                break;
            }
            i++;

        }
        // up
        i = 1;
        while (row - i >= 0) {
            if (board[row - i][col] == 'X') {
                up = true;
                break;
            }
            i++;
        }
        // down
        i = 1;
        while (row + i < m) {
            if (board[row + i][col] == 'X') {
                down = true;
                break;
            }
            i++;

        }
        if (left && right && up && down) {
            return true;
        } else {
            return false;
        }


    }
}
