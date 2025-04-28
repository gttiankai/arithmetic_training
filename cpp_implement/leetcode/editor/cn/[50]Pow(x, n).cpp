// Implement pow(x, n), which calculates x raised to the power n (i.e., xⁿ).
//
//
//  Example 1:
//
//
// Input: x = 2.00000, n = 10
// Output: 1024.00000
//
//
//  Example 2:
//
//
// Input: x = 2.10000, n = 3
// Output: 9.26100
//
//
//  Example 3:
//
//
// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2⁻² = 1/2² = 1/4 = 0.25
//
//
//
//  Constraints:
//
//
//  -100.0 < x < 100.0
//  -2³¹ <= n <= 2³¹-1
//  n is an integer.
//  Either x is not zero or n > 0.
//  -10⁴ <= xⁿ <= 10⁴
//
//
//   Related Topics 递归 数学 👍 1454 👎 0

#include <cstdlib>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 实现了一个很慢的版本,有没有办法进行加速
     ***/
    double myPow(double x, int n) {
        double power  = 1;
        bool negative = n < 0 ? true : false;
        n             = std::abs(n);
        for (int i = 0; i < n; i++) {
            power = power * x;
        }
        if (negative) {
            power = 1 / power;
        }
        return power;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
