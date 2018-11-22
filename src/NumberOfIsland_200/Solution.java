/**
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and
 * <p>
 * is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all
 * <p>
 * surrounded by water.
 * <p>
 * Example 1:
 * <p>
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * <p>
 * Output: 1
 * <p>
 * Example 2:
 * <p>
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * <p>
 * Output: 3
 *
 * 这个题目中最重要的地方在于解题的方式：采用的是消除法，消除所有的应用。
 */

package NumberOfIsland_200;

public class Solution {
    /**
     * 采用消除的方式进行求解
     *
     * */
    public static int numIslands(char[][] grid) {
        int row = grid.length;
        if (row == 0) {
            return 0;
        }
        int column = grid[0].length;
        if (column == 0) {
            return 0;
        }

        int count = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    marking(grid, i, j);
                }
            }
        }
        return count;

    }

    // 将 grid[i][j]附近的所有陆地清除
    // 递归的清除
    private static void marking(char[][] grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        marking(grid, i, j - 1);
        marking(grid, i, j + 1);
        marking(grid, i - 1, j);
        marking(grid, i + 1, j);
    }
    public static void main(String[] arguments) {
        char[][] grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
        System.out.println(numIslands(grid));
    }

}
