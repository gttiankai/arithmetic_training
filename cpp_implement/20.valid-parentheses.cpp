/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start

#include <iostream>
#include <stack>
#include <string>

/**
 * 使用 stack 一次性通过
 *
 * */
class Solution {
 public:
  bool isValid(std::string s) {
    std::stack<char> stack;
    for (int i = 0; i < s.size(); ++i) {
      if (stack.empty()) {
        stack.push(s[i]);
        continue;
      }

      if (Match(stack.top(), s[i])) {
        stack.pop();
      } else {
        stack.push(s[i]);
      }
    }
    return stack.empty();
  }

 private:
  bool Match(char left, char right) {
    if (left == '(') {
      return right == ')';
    } else if (left == '{') {
      return right == '}';
    } else if (left == '[') {
      return right == ']';
    } else {
      return false;
    }
  }
};

int main(int argc, char* argv[]) {
  std::string message = "{()[]{}]";
  Solution solution;
  std::cout << solution.isValid(message) << std::endl;
  return 0;
}
// @lc code=end
