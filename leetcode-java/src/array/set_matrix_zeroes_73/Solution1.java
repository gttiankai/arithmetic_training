package array.set_matrix_zeroes_73;

import java.util.ArrayList;
import java.util.List;

public class Solution1 {

    /**
     * if cell[i][j] == 0 {
     *     cell[i][0] = 0
     *     cell[0][j] = 0
     * }
     *
     * 思路是对的,但是没有考虑到特殊的情况,不能处理第一行和第一列
     * */
    public void setZeroes(int[][] matrix) {
            if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
                return;
            }
            int m = matrix.length;
            int n = matrix[0].length;
            for (int i = 0; i < m; i++) {
                for ( int j = 0; j < n; j++) {
                    if (matrix[i][j] == 0 ) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            for (int i = 0; i < m; i++) {
                if(matrix[i][0] == 0) {
                    for (int j = 1; j < n; j++) {
                        matrix[i][j]= 0;
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                if(matrix[0][j] == 0) {
                    for (int i = 1; i < m; i++) {
                        matrix[i][j]= 0;
                    }
                }
            }
    }

    public static void main(String[] args) {
        int[][] matrix = new int[][] {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

        Solution1 solution1 = new Solution1();
        solution1.setZeroes(matrix);

    }
}
