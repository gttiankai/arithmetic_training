package DFS.surrounded_regions_130;

import java.util.LinkedList;
import java.util.Queue;

public class SolutionBFS {
    /**
     *
     * Runtime: 2 ms, faster than 53.08% of Java online submissions for Surrounded Regions.
     * Memory Usage: 47 MB, less than 23.79% of Java online submissions for Surrounded Regions.
     * 
     * */
    public void solve(char[][] board) {

        if (board == null || board.length == 0 || board[0].length == 0) {
            return;
        }
        int m = board.length;
        int n = board[0].length;
        for (int j = 0; j < n ; j++) {
            if (board[0][j] == 'O') {
                BFS(board, 0, j);
            }
            if (board[m-1][j] == 'O'){
                BFS(board, m - 1, j);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O'){
                BFS(board, i, 0);
            }
            if (board[i][n-1] == 'O') {
                BFS(board, i, n - 1);
            }
        }

        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < n ; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '$') {
                    board[i][j] = 'O';
                }
            }
        }

    }

    private void BFS(char[][] board, int row, int col) {
        int m = board.length;
        int n = board[0].length;
        board[row][col] = '$';
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{row,col});

        while (!queue.isEmpty()) {
            int[] item = queue.poll();
            int i = item[0];
            int j = item[1];

            if (i > 0 && board[i-1][j] == 'O') {
                board[i-1][j] = '$';
                queue.add(new int[]{ i-1, j});
            }
            if (i < m-1 && board[i+1][j] == 'O') {
                board[i+1][j] = '$';
                queue.add(new int[]{ i+1, j});
            }
            if (j > 0 && board[i][j-1] == 'O') {
                board[i][j-1] = '$';
                queue.add(new int[]{ i, j-1});
            }
            if (j < n-1 && board[i][j+1] == 'O') {
                board[i][j+1] = '$';
                queue.add(new int[]{ i, j+1});
            }
        }
    }
}
