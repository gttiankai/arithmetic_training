/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * <p>
 * Example 1:
 * <p>
 * Input:
 * [
 * [ 1, 2, 3 ],
 * [ 4, 5, 6 ],
 * [ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * Example 2:
 * <p>
 * Input:
 * [
 * [1, 2, 3, 4],
 * [5, 6, 7, 8],
 * [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

package spiral_matrix_54;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    public static List<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> res = new ArrayList();
        if (matrix == null || matrix.length == 0) {
            return res;
        }
        int rowBegin = 0;
        int rowEnd = matrix.length - 1;
        int colBegin = 0;
        int colEnd = matrix[0].length - 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int j = colBegin; j <= colEnd; j++) {

                res.add(matrix[rowBegin][j]);
            }
            rowBegin++;
            // 每一步结束之后,都要对目前的结果进行判断
            // 一开始就没有这一步就出错了
            if (rowBegin > rowEnd) {
                break;
            }

            for (int i = rowBegin; i <= rowEnd; i++) {

                res.add(matrix[i][colEnd]);
            }
            colEnd--;
            if (colBegin > colEnd) {
                break;
            }

            for (int j = colEnd; j >= colBegin; j--) {

                res.add(matrix[rowEnd][j]);
            }
            rowEnd--;

            if(rowBegin > rowEnd) {
                break;
            }


            for (int i = rowEnd; i >= rowBegin; i--) {
                res.add(matrix[i][colBegin]);
            }
            colBegin++;
            if (colBegin > colEnd) {
                break;
            }
        }
        return res;
    }

    public static void main(String[] arguments) {
        int[][] matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
        System.out.printf("" + spiralOrder(matrix));
    }
}
