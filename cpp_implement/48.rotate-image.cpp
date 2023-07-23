/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.cn/problems/rotate-image/description/
 *
 * algorithms
 * Medium (74.77%)
 * Likes:    1677
 * Dislikes: 0
 * Total Accepted:    466.3K
 * Total Submissions: 623.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image, rotate the image by
 * 90 degrees (clockwise).
 *
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[7,4,1],[8,5,2],[9,6,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 *
 *
 *
 * Constraints:
 *
 *
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
// @lc code=start
/**
 * Matrix shape: [N, N]
 * Matrix[m][n] -> Matrix[n][N - 1 - m]
 *
 * 经过分析: Matrix 经过两次翻转就可以实现 90 度旋转矩阵的目的
 * */
class Solution {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    // 水平翻转
    int N = matrix.size();
    for (int i = 0; i < N / 2; ++i) {
      for (int j = 0; j < N; ++j) {
        // swap
        int temp             = matrix[i][j];
        matrix[i][j]         = matrix[N - 1 - i][j];
        matrix[N - 1 - i][j] = temp;
      }
    }
    // 对角线翻转
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= i; ++j) {
        int temp     = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
      }
    }
    return;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  return 0;
}
