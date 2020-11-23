package DFS.surrounded_regions_130;

public class SolutionDFS {
    /**
     * 思路: 遍历 board 的四周的四条边,如果是'O',则进行 DFS,找到所有与边界上的'O'相连的并且值是'O'的位置,并将该位置
     * 标记成为特殊的符号'$', 当四条边遍历完成完成之后,再对除了四条边的位置进行遍历,所有值为'$'都标记为'X',遍历完成之后
     * 的就是最终的结果.
     *
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Surrounded Regions.
     * Memory Usage: 46.1 MB, less than 39.62% of Java online submissions for Surrounded Regions.
     *
     */
    public void solve(char[][] board) {

        if (board == null || board.length == 0 || board[0].length == 0) {
            return;
        }
        int m = board.length;
        int n = board[0].length;
        for (int j = 0; j < n ; j++) {
            if (board[0][j] == 'O') {
                DFS(board, 0, j);
            }
            if (board[m-1][j] == 'O'){
                DFS(board, m - 1, j);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O'){
                DFS(board, i, 0);
            }
            if (board[i][n-1] == 'O') {
                DFS(board, i, n - 1);
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

    /**
     * DFS 进行遍历,
     */
    private void DFS(char[][] board, int row, int col) {
        int m = board.length;
        int n = board[0].length;

        board[row][col] = '$';

        if (row > 0 && board[row -1][col] == 'O') {
            DFS(board, row-1, col);
        }
        if (row < m-1 && board[row+1][col] == 'O') {
            DFS(board, row +1, col);
        }
        if (col > 0 && board[row][col -1] == 'O'){
            DFS(board, row, col-1);
        }
        if (col < n-1 && board[row][col +1] == 'O') {
            DFS(board, row, col+1);
        }
    }

    public static void main(String[] args) {
        char[][] board = {
                {'O','X','X','O','X'},
                {'X','O','O','X','O'},
                {'X','O','X','O','X'},
                {'O','X','O','O','O'},
                {'X','X','O','X','O'}
        };
        SolutionDFS solution = new SolutionDFS();

        solution.solve(board);
    }


}
