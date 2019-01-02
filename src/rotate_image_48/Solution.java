/**
 * You are given an n x n 2D matrix representing an image.
 * <p>
 * Rotate the image by 90 degrees (clockwise).
 * <p>
 * Note:
 * <p>
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 * <p>
 * Example 1:
 * <p>
 * Given input matrix =
 * [
 * [1,2,3],
 * [4,5,6],
 * [7,8,9]
 * ],
 * <p>
 * rotate the input matrix in-place such that it becomes:
 * [
 * [7,4,1],
 * [8,5,2],
 * [9,6,3]
 * ]
 * Example 2:
 * <p>
 * Given input matrix =
 * [
 * [ 5, 1, 9,11],
 * [ 2, 4, 8,10],
 * [13, 3, 6, 7],
 * [15,14,12,16]
 * ],
 * <p>
 * rotate the input matrix in-place such that it becomes:
 * [
 * [15,13, 2, 5],
 * [14, 3, 4, 1],
 * [12, 6, 8, 9],
 * [16, 7,10,11]
 * ]
 */

package rotate_image_48;

import java.util.ArrayList;

public class Solution {
    /**
     * 这个题目特别象环形打印的题目
     */
    public static void rotate(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return;
        }
        int i = 1;
        while (i < matrix.length) {
            rotateOne(matrix);
            i++;
        }
    }

    public static void rotateOne(int[][] matrix) {

        int rowBegin = 0;
        int rowEnd = matrix.length - 1;
        int colBegin = 0;
        int colEnd = matrix[0].length - 1;
        int pre = 0;
        int tmp = 0;
        int k = 0;
        int l = 0;
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            boolean first = true;
            for (int j = colBegin; j <= colEnd; j++) {
                if (first) {
                    pre = matrix[rowBegin][j];
                    k = rowBegin;
                    l = j;
                    first = false;
                    continue;
                }
                tmp = matrix[rowBegin][j];
                matrix[rowBegin][j] = pre;
                pre = tmp;
            }
            rowBegin++;
            // 每一步结束之后,都要对目前的结果进行判断
            // 一开始就没有这一步就出错了



            for (int i = rowBegin; i <= rowEnd; i++) {
                tmp = matrix[i][colEnd];
                matrix[i][colEnd] = pre;
                pre = tmp;
            }
            colEnd--;


            for (int j = colEnd; j >= colBegin; j--) {
                tmp = matrix[rowEnd][j];
                matrix[rowEnd][j] = pre;
                pre = tmp;
            }
            rowEnd--;


            for (int i = rowEnd; i >= rowBegin; i--) {
                tmp = matrix[i][colBegin];
                matrix[i][colBegin] = pre;
                pre = tmp;
            }
            colBegin++;
            matrix[k][l] = pre;
        }
        return;
    }

    public static void main(String[] arguments) {
        int[][] matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
        //rotate(matrix);
        rotateOne(matrix);
        rotateOne(matrix);
        rotateOne(matrix);
        for (int[] item:
             matrix) {
            for (int a:
                 item) {
                System.out.printf(" " + a);
            }
            System.out.println("");
        }
    }

}
