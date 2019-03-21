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
    public boolean exist(char[][] board, String word) {
        if(null == board || null == word || board[0].length == 0) {
            return false;
        }
        int m = board.length;
        int n = board[0].length;
        if (m*n < word.length()) {
            return false;
        }
        for (int i = 0; i < word.length(); i++) {

        }
    }
    
}
