/**
 * 4-queens:
 */

package backtracking.FourQueens;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Solution {

    public static List<List<String>> solveFourQueens(int n) {
        char[][] map = new char[n][n];
        // 初始化
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = '.';
            }
        }
        List<List<String>> res = new ArrayList<List<String>>();
        dfs(map, 0, res);
        return res;
    }

    private static void dfs(char[][] map, int colIndex, List<List<String>> res) {
        // 一行一行的放置，直到最后一行也放好了 queen
        if (colIndex == map.length) {
            res.add(construct(map));
            return;
        }
        // 按照行进行处理
        for (int i = 0; i < map.length; i++) {
            if (valid(map, i, colIndex)) {
                map[i][colIndex] = 'Q';
                // 递归
                dfs(map, colIndex + 1, res);
                map[i][colIndex] = '.';
            }
        }
    }

    private static boolean valid(char[][] board, int x, int y) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < y; j++) {
                if (board[i][j] == 'Q' && (x + j == y + i || x + y == i + j || x == i)) {
                    return false;
                }
            }
        }

        return true;
    }

    private static List<String> construct(char[][] board) {
        List<String> res = new LinkedList<String>();
        for (int i = 0; i < board.length; i++) {
            String s = new String(board[i]);
            res.add(s);
        }
        return res;
    }

    public static void main(String[] arguments) {
        System.out.println(solveFourQueens(8).size());
    }

}
