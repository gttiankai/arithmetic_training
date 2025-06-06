// You are given an n x n 2D matrix representing an image, rotate the image by
// 90
//  degrees (clockwise).
//
//  You have to rotate the image in-place, which means you have to modify the
// input 2D matrix directly. DO NOT allocate another 2D matrix and do the
// rotation.
//
//
//  Example 1:
//
//
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
//
//
//  Example 2:
//
//
// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
//
//
//
//  Constraints:
//
//
//  n == matrix.length == matrix[i].length
//  1 <= n <= 20
//  -1000 <= matrix[i][j] <= 1000
//
//
#include <algorithm>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 由于题目中要求不能使用额外的空间对数组进行存储,只能 in-place 的进行处理,
     * 解法如下:
     * 1. 按照行,从中间行水平翻转
     * 2. 按照左上到右下的对角线进行翻转
     * 下面的解法也可以
     * 1. 将二维数组根据中间的列进行翻转
     * 2. 将二维数组按照左下到右上的对角线进行对调
     */
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n   = matrix[0].size();
        int mid = n / 2;
        // 按照行号进行翻转
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < n; j++) {
                std::swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
        // 按照对角线进行翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
