/**
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent"
 *
 * cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * Example:
 *
 * board =
 * [
 *   ['A','B','C','E'],
 *   ['S','F','C','S'],
 *   ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
 * */
package array.word_search_79;

import java.util.Hashtable;

public class Solution {
    /**
     * 这个方法是失败的,失败的原因是题目中有个要求:
     * "The same letter cell may not be used more than once." 也就是说每个元素之后用一次.
     *  test: ABCB 这个测试例是过不去的.
     *
     *  解决这个问题其实有一个很简单的做法,就是在每个数组中添加一个属性,标记是否已经访问过,但是这个解法,
     *  不符合 leetcode 的要求.
     *
     *  这个地方可以换一个比较好的办法,就是添加一个全局的变量,记录已经遍历过的节点(哎,怎么但是没有想到呢)
     * */
    public boolean exist(char[][] board, String word) {
        if(null == board || null == word || board[0].length == 0) {
            return false;
        }
        int m = board.length;
        int n = board[0].length;
        if (m*n < word.length()) {
            return false;
        }
        boolean[][] visited = new boolean[m][n];
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.charAt(0)) {
                    if (true == backtrack(board, i, j, word, 1, visited) ) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    private boolean backtrack(char[][] board, int i, int j,
                              String word, int start,
                              boolean[][] visited) {
        int m = board.length;
        int n = board[0].length;
        visited[i][j] = true;
        if (start == word.length()) {
            return true;
        }
        if (i - 1 >= 0 && board[i-1][j] == word.charAt(start) && !visited[i-1][j]) {
            if(backtrack(board, i-1, j, word, start+1, visited)){
                return true;
            }
        }
        if (i + 1 < m && board[i+1][j] == word.charAt(start) && !visited[i+1][j]) {
           if ( backtrack(board, i+1, j, word, start+1, visited)) {
               return true;
           }
        }
        if (j - 1 >= 0 && board[i][j-1] == word.charAt(start) && !visited[i][j-1]) {
            if (backtrack(board, i, j - 1, word, start+1, visited)) {
                return true;
            }
        }
        if (j + 1 < n && board[i][j+1] == word.charAt(start) && !visited[i][j+1]) {
            if (backtrack(board, i, j + 1, word, start+1, visited)) {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }

    public static void main(String[] arguments) {
        char[][] board = {
                {'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'}};
        String word = "ABCB";
        Solution solution = new Solution();
        System.out.printf("" + solution.exist(board, word));
    }
    
}
