/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 *
 * Example 1:
 *
 * Input:
 * [
 *   [1,1,1],
 *   [1,0,1],
 *   [1,1,1]
 * ]
 * Output:
 * [
 *   [1,0,1],
 *   [0,0,0],
 *   [1,0,1]
 * ]
 * Example 2:
 *
 * Input:
 * [
 *   [0,1,2,0],
 *   [3,4,5,2],
 *   [1,3,1,5]
 * ]
 * Output:
 * [
 *   [0,0,0,0],
 *   [0,4,5,0],
 *   [0,3,1,0]
 * ]
 * Follow up:
 *
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 *
 * */

package array.set_matrix_zeroes_73;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;


public class Solution {
    /**
     * Runtime: 1 ms, faster than 98.78% of Java online submissions for Set Matrix Zeroes.
     * Memory Usage: 49.2 MB, less than 17.71% of Java online submissions for Set Matrix Zeroes.
     *
     * */
    public void setZeroes(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        List<int[]> list = new ArrayList<int[]>();
        for (int i = 0; i < m; i++) {
            for ( int j = 0; j < n; j++) {
                if (matrix[i][j] == 0 ) {
                    int[] tmpList = new int[2];
                    tmpList[0] = i;
                    tmpList[1] = j;
                    list.add(tmpList);
                }
            }
        }
        for(int[] item: list) {
            setValue(matrix, item[0], item[1]);
        }
    }
    private void setValue(int[][] matrix, int m , int n) { 
        int row = matrix.length;
        int col = matrix[0].length;
        for(int i = 0; i < col; i++) {
            matrix[m][i] = 0;
        }
        for(int i = 0; i < row; i++) {
            matrix[i][n] = 0;
        }
    } 

}
