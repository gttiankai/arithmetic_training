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

public class Solution {
    /**
     * 这个题目特别象环形打印的题目
     */
    public static void rotate(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return;
        }
        int rowBegin = 0;
        int rowEnd = matrix.length - 1;
        int colBegin = 0;
        int colEnd = matrix[0].length - 1;
        rotateOne(matrix, rowBegin, rowEnd, colBegin, colEnd);
    }

    public static void rotateOne(int[][] matrix, int rowBegin, int rowEnd, int colBegin, int colEnd) {
        if (rowBegin >= rowEnd) {
            return;
        }
        int pre = 0;
        int tmp = 0;
        int k = 0;
        int l = 0;
        boolean first = true;
        // 这个题目的难点是关于循环次数的确定.
        // 目前使用的是递归的方式, 将数组拆解成多个"回"字形, 然后将每个"回"字形进行打印.
        for (int count = 0; count < rowEnd - rowBegin ; count++) {
            int up = rowBegin;
            int down = rowEnd;
            int left = colBegin;
            int right = colEnd;
            for (int j =  left; j <=  right; j++) {
                if (first) {
                    pre = matrix[up][j];
                    k = up;
                    l = j;
                    first = false;
                    continue;
                }
                tmp = matrix[up][j];
                matrix[up][j] = pre;
                pre = tmp;
            }
            up++;
            // 每一步结束之后,都要对目前的结果进行判断
            // 一开始就没有这一步就出错了

            for (int i = up; i <= down; i++) {
                tmp = matrix[i][right];
                matrix[i][right] = pre;
                pre = tmp;
            }
            right--;


            for (int j = right; j >= left; j--) {
                tmp = matrix[down][j];
                matrix[down][j] = pre;
                pre = tmp;
            }
            down--;


            for (int i = down; i >= up; i--) {
                tmp = matrix[i][left];
                matrix[i][left] = pre;
                pre = tmp;
            }
            //left++;
            matrix[k][l] = pre;
        }
        rotateOne(matrix, rowBegin+1, rowEnd-1, colBegin+1, colEnd -1);
        return;
    }

    public static void main(String[] arguments) {
        int[][] matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
        rotate(matrix);
        for (int[] item :
                matrix) {
            for (int a :
                    item) {
                System.out.printf(" " + a);
            }
            System.out.println("");
        }
    }

}
