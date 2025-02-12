/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.cn/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (56.30%)
 * Likes:    2954
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 3.1M
 * Testcase Example:  '121'
 *
 * Given an integer x, return true if x is a palindrome, and false
 * otherwise.
 *
 * Example 1:
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 *
 * Example 2:
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 *
 * Example 3:
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 *
 * Constraints:
 *
 * -2^31 <= x <= 2^31 - 1
 *
 * Follow up: Could you solve it without converting the integer to a string?
 */

#include <iostream>

// @lc code=start
class Solution {
   public:
    /**
     * 关键点:
     *    1. reverse 大于 INT_MAX 之后如何处理, 这个地方也是忽略的点
     *    2. 这个题目之所以能够比较好的解决,还有赖于之前对整数的处理的几个题目
     * */
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int back_up    = x;
        long remainder = 0;
        while (x > 0) {
            remainder = remainder * 10 + x % 10;
            x         = x / 10;
        }
        return back_up == remainder;
    }
};
// @lc code=end
int main(int argc, char const *argv[]) {
    Solution solution;
    std::vector<int> nums = {121, -121, 10, 1, 1234567899};
    for (int item : nums) {
        auto ans = solution.isPalindrome(item);
        std::cout << item << ":" << ans << std::endl;
    }
}
