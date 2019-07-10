package DFS.number_of_island_200;

public class SolutionDFS {


    /**
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Number of Islands.
     * Memory Usage: 40.7 MB, less than 98.88% of Java online submissions for Number of Islands.
     *
     * */
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }

        int count = 0;
        int m = grid.length;
        int n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    DFS(grid, i, j);
                }
            }
        }
        return count;

    }

    // 将 grid[i][j]附近的所有陆地清除
    // 递归的清除
    private void DFS(char[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        DFS(grid, i, j - 1);
        DFS(grid, i, j + 1);
        DFS(grid, i - 1, j);
        DFS(grid, i + 1, j);
    }
    public static void main(String[] arguments) {
        char[][] grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
        SolutionDFS solutionDFS = new SolutionDFS();
        System.out.println(solutionDFS.numIslands(grid));
    }
}
