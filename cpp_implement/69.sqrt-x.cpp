/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.cn/problems/sqrtx/description/
 *
 * algorithms
 * Easy (38.46%)
 * Likes:    1341
 * Dislikes: 0
 * Total Accepted:    739.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '4'
 *
 * Given a non-negative integer x, return the square root of x rounded down to
 * the nearest integer. The returned integer should be non-negative as well.
 *
 * You must not use any built-in exponent function or operator.
 *
 *
 * For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: x = 4
 * Output: 2
 * Explanation: The square root of 4 is 2, so we return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since we round it down
 * to the nearest integer, 2 is returned.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= x <= 2^31 - 1
 *
 *
 */
#include <cmath>
#include <iostream>
#include <vector>

/**
 * 当时 for 循环能解决问题的时候，如果想提高性能，自然而然的思路就是使用二分查找提高效率
 *
 * */
class SolutionSlow {
 public:
  int mySqrt(int x) {
    long target = x;
    long i      = 0;
    for (; i <= target; ++i) {
      if (i * i <= target && (i + 1) * (i + 1) > target) {
        return i;
      }
    }
    return (int)i;
  }
};
// @lc code=start
class Solution {
 public:
  int mySqrt(int x) {
    int ans   = 0;
    int left  = 0;
    int right = x;
    while (left <= right) {
      // mid 有可能溢出，需要使用更好的办法
      // int mid     = (left + right) / 2;
      int mid     = left  + (right - left) /2;
      long long square = (long long )mid * mid;
      if (square <= x) {
        ans  = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  std::vector<int> cases = {8, 1, 0, 128, 2147395599};
  //std::vector<int> cases = {2147395599};
  for (const auto& item : cases) {
    Solution solution;
    std::cout << "math.sqrt(" << item << "):" << std::sqrtf(item) << " vs " << solution.mySqrt(item) << std::endl;
  }
  return 0;
}
