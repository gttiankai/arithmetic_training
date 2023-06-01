/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.cn/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (22.20%)
 * Likes:    1122
 * Dislikes: 0
 * Total Accepted:    209.3K
 * Total Submissions: 942.7K
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division, and mod operator.
 *
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, 8.345 would be truncated to 8, and -2.7335
 * would be truncated to -2.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * Note: Assume we are dealing with an environment that could only store
 * integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this
 * problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31
 * - 1, and if the quotient is strictly less than -2^31, then return -2^31.
 *
 *
 * Example 1:
 *
 *
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = 3.33333.. which is truncated to 3.
 *
 *
 * Example 2:
 *
 *
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= dividend, divisor <= 2^31 - 1
 * divisor != 0
 *
 *
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <ostream>
#include <vector>
/**
 * 下面的解法超时了
 * */
class SolutionSlow {
 public:
  int divide(int dividend, int divisor) {
    /**
     * 这个题目的主要限制是系统支持存储 32 bite 数据,所以一定要处理溢出的情况
     * 另外还有一处需要特别注意: INT_MIN: -2^31; INT_MAX: (2^31 - 1),这两个数在数轴上是不对称的,
     * 考虑到需要往 0 的位置截断,
     * */
    if (dividend == INT_MIN) {
      if (divisor == -1) {
        // quotient: 2^31, overflow
        return INT_MAX;
      } else if (divisor == 1) {
        return INT_MIN;
      } else {
        return compute(dividend, divisor);
      }
    }
    if (divisor == INT_MIN) {
      if (dividend == INT_MIN) {
        return 1;
      } else {
        return 0;
      }
    }
    return compute(dividend, divisor);
  }

 private:
  int compute(int dividend, int divisor) {
    bool flag_equal = true;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
      flag_equal = false;
    }
    // WARNING: 由于 INT_MIN 的存在,要往负轴的方向处理
    dividend     = -std::abs(dividend);
    divisor      = -std::abs(divisor);
    int quotient = 0;
    while (dividend <= divisor) {
      quotient++;
      dividend -= divisor;
    }
    if (flag_equal) {
      return quotient;
    } else {
      return -quotient;
    }
  }
};
// @lc code=start
class Solution {
 public:
  int divide(int dividend, int divisor) {}
};
// @lc code=end

int main(int argc, char *argv[]) {
  Solution solution;
  std::vector<int> test_case;
  test_case.push_back(INT_MIN);
  test_case.push_back(-1);
  test_case.push_back(10);
  test_case.push_back(3);
  test_case.push_back(7);
  test_case.push_back(-3);
  test_case.push_back(INT_MAX);
  test_case.push_back(2);
  test_case.push_back(1);
  test_case.push_back(1);
  test_case.push_back(INT_MIN);
  test_case.push_back(1);
  test_case.push_back(INT_MIN);
  test_case.push_back(2);
  for (int i = 0; i < test_case.size(); i += 2) {
    std::cout << test_case[i] << " divide " << test_case[i + 1] << " = "
              << solution.divide(test_case[i], test_case[i + 1]) << std::endl;
  }
  return 0;
}
