// You are given an array of strings tokens that represents an arithmetic
// expression in a Reverse Polish Notation.
//
//  Evaluate the expression. Return an integer that represents the value of the
// expression.
//
//  Note that:
//
//
//  The valid operators are '+', '-', '*', and '/'.
//  Each operand may be an integer or another expression.
//  The division between two integers always truncates toward zero.
//  There will not be any division by zero.
//  The input represents a valid arithmetic expression in a reverse polish
// notation.
//  The answer and all the intermediate calculations can be represented in a 32-
// bit integer.
//
//
//
//  Example 1:
//
//
// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
//
//
//  Example 2:
//
//
// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
//
//
//  Example 3:
//
//
// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22
//
//
//
//  Constraints:
//
//
//  1 <= tokens.length <= 10⁴
//  tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the
// range [-200, 200].
//
//
//  Related Topics 栈 数组 数学 👍 1012 👎 0

#include <iostream>
#include <ostream>
#include <stack>
#include <string>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int evalRPN(std::vector<std::string>& tokens) {
        if (tokens.empty()) {
            return 0;
        }
        if (tokens.size() == 1) {
            return std::stoi(tokens[0]);
        }
        std::stack<int> stack;
        for (auto& token : tokens) {
            if (isOperator(token)) {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                int c = compute(a, b, token);
                stack.push(c);
            } else {
                stack.push(std::stoi(token));
            }
        }
        return stack.top();
    }

   private:
    int compute(int a, int b, std::string op) {
        switch (op[0]) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                return 0;
        }
    }
    bool isOperator(std::string token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            return true;
        }
        return false;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
    Solution solution;
    std::cout << solution.evalRPN(tokens) << std::endl;
}
