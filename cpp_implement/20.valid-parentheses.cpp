/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.50%)
 * Likes:    4631
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 4.6M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 *
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 *
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 *
 * Example 3:
 * Input: s = "(]"
 * Output: false
 *
 * Example 4:
 * Input: s = "([])"
 * Output: true
 *
 * Constraints:
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 */
#include <iostream>
#include <stack>
#include <string>
// @lc code=start
class Solution {
   public:
    bool isValid(std::string s) {
        std::stack<char> brackets_stack;
        for (char& item : s) {
            if (brackets_stack.empty()) {
                brackets_stack.push(item);
                continue;
            }
            if (match(brackets_stack.top(), item)) {
                brackets_stack.pop();
            } else {
                brackets_stack.push(item);
            }
        }
        return brackets_stack.empty();
    }

   private:
    bool match(char left, char right) {
        if (left == '[' && right == ']') {
            return true;
        } else if (left == '(' && right == ')') {
            return true;
        } else if (left == '{' && right == '}') {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    std::string message = "{()[]{}]";
    Solution solution;
    std::cout << solution.isValid(message) << std::endl;
    return 0;
}