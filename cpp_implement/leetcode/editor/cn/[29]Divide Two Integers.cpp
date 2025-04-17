// Given two integers dividend and divisor, divide two integers without using
// multiplication, division, and mod operator.
//
//  The integer division should truncate toward zero, which means losing its
// fractional part. For example, 8.345 would be truncated to 8, and -2.7335
// would be truncated to -2.
//
//  Return the quotient after dividing dividend by divisor.
//
//  Note: Assume we are dealing with an environment that could only store
// integers within the 32-bit signed integer range: [−2³¹, 2³¹ − 1]. For this
// problem, if the quotient is strictly greater than 2³¹ - 1, then return 2³¹ -
// 1, and if the quotient is strictly less than -2³¹, then return -2³¹.
//
//
//  Example 1:
//
//
// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333.. which is truncated to 3.
//
//
//  Example 2:
//
//
// Input: dividend = 7, divisor = -3
// Output: -2
// Explanation: 7/-3 = -2.33333.. which is truncated to -2.
//
//
//
//  Constraints:
//
//
//  -2³¹ <= dividend, divisor <= 2³¹ - 1
//  divisor != 0
//
//
//    Related Topics 位运算 数学 👍 1281 👎 0

#include <__ostream/basic_ostream.h>

#include <iostream>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int divide(int dividend, int divisor) {}
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char *argv[]) {
    Solution solution;
    std::vector<int> dividend_array = {10, 10, -10};
    std::vector<int> divisor_array  = {3, -3, 3};
    for (int i = 0; i < dividend_array.size(); ++i) {
        int dividend = dividend_array[i];
        int divisor  = divisor_array[i];
        int quotient = solution.divide(dividend, divisor);
        std::cout << dividend << " / " << divisor << " = " << quotient
                  << std::endl;
    }
    return 0;
}
