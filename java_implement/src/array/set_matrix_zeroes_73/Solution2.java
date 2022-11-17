package array.set_matrix_zeroes_73;

public class Solution2 {
    /**
     * 这个题目主要考察的是如何优化空间复杂度的问题
     *
     * */
    public void setZeroes(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        /**
         * 第一个元素要特殊处理
         * unite test:
         * [1, 2, 3, 0], [5, 6, 7, 8], [9, 10 , 11, 12]
         * unite test:
         * [1, 1, 1],[0, 1, 2]
         * */
        boolean isCol = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                isCol = true;
            }
            /**
             * 从 j = 1开始,排除掉第一列对 matrix[0][0]的影响,
             * 因为如果第0 行 和 第0 列都影响 matrix[0][0]的话,后面处理的时候,就不能判断了.
             * */
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (isCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }

    public static void main(String[] args) {
        int[][] matrix = new int[][]{{1, 1, 1}, {0, 1, 2}};
        Solution2 solution = new Solution2();
        solution.setZeroes(matrix);
    }
}
