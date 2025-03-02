// Given a non-negative integer x, return the square root of x rounded down to
// the nearest integer. The returned integer should be non-negative as well.
//
//  You must not use any built-in exponent function or operator.
//
//
//  For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
//
//
//  Example 1:
// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
//
//
//  Example 2:
// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since we round it down
// to the nearest integer, 2 is returned.
//
//  Constraints:
//  0 <= x <= 2³¹ - 1
//
//  Related Topics 数学 二分查找
//  👍 1630 👎 0
#include <iostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int mySqrt(int x) {
        int ans = 0;
        int left = 0;
        int right = x;
        while (left <= right) {
            // overflow
            // int mid = (left + right) / 2;
            // 下面的代码是一个小技巧
            int mid = left + (right - left) / 2;
            int64_t square = (int64_t)(mid * mid);
            if (square < x) {
                left = mid + 1;
                ans = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char const *argv[]) {
    Solution solution;
    std::vector<int> test = {6, 0, 1, 2, 3, 4, 6, 8, 9,INT_MAX - 1};
    for (auto &item : test) {
        std::cout <<"Sqrt(" << item << ")="<<solution.mySqrt(item) << std::endl;
    }
    return 0;
}
