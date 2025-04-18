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

#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    // 仔细的思考题目,你会发现由于是正数除法,发生溢出的情况比较少见,目前只有一种
    // 情况会发生溢出: INT_MIN / -1,出现这种情况下才会发生溢出
    int divide(int dividend, int divisor) {
        bool same_sign = CheckSign(dividend, divisor);
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int ans = 0;
        if (dividend > 0) {
            dividend = -dividend;
        }
        if (divisor > 0) {
            divisor = -divisor;
        }
        while (dividend <= divisor) {
            // 变成减法的原因是 INT 的负数值域比正数的值域大一个,用于处理 INT_MIN 的情况
            ans--;
            dividend -= divisor;
        }
        if (same_sign) {
            // 由于上面的 ans 是减法,所以符号相同时,需要添加负号
            return -ans;
        }
        return ans;
    }

   private:
    bool CheckSign(int dividend, int divisor) {
        if ((dividend >= 0 and divisor > 0) || (dividend <= 0 && divisor < 0)) {
            return true;
        } else {
            return false;
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char *argv[]) {
    Solution solution;
    std::vector<int> dividend_array = {10, 10, -10, INT_MIN, INT_MIN, INT_MAX};
    std::vector<int> divisor_array  = {3, -3, 3, -1, 1, -1};
    for (int i = 0; i < dividend_array.size(); ++i) {
        int dividend = dividend_array[i];
        int divisor  = divisor_array[i];
        int quotient = solution.divide(dividend, divisor);
        std::cout << dividend << " / " << divisor << " = " << quotient
                  << std::endl;
    }
    return 0;
}
