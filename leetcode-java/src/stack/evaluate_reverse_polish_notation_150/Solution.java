/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always 
evaluate to a result and there won"t be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 */


package stack.evaluate_reverse_polish_notation_150;

import java.util.Stack;

class Solution {

    /**
     * Runtime: 7 ms, faster than 26.29% of Java online submissions for Evaluate Reverse Polish Notation.
     * Memory Usage: 37.6 MB, less than 87.62% of Java online submissions for Evaluate Reverse Polish Notation.
     * 使用最简单的方式就能解决这个逆波兰式
     * */
    public int evalRPN(String[] tokens) {
        if (tokens == null || tokens.length == 0) {
            //throw  Exception("invalid RPN");
            return -1;
        }
        Stack<String> stack = new Stack<String>();
        int N = tokens.length;
        for (int i = 0; i < N; i++) {
            if (isValidOp(tokens[i])) {
                if (stack.size() == 0) {
                    //throw Exception("invalid RPN");
                    return -1;
                }
                stack.push(calculate(stack.pop(), stack.pop(), tokens[i]));
            } else {
                stack.push(tokens[i]);
            }
        }
        return Integer.valueOf(stack.pop());
    }

    private boolean isValidOp(String token) {
        if (token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")) {
            return true;
        }
        return false;
    }

    private String calculate(String a, String b, String op) {
        switch (op) {
            case "+":
                return String.valueOf(Integer.valueOf(b) + Integer.valueOf(a));
            case "-":
                return String.valueOf(Integer.valueOf(b) - Integer.valueOf(a));
            case "*":
                return String.valueOf(Integer.valueOf(a) * Integer.valueOf(b));
            default:
                return String.valueOf(Integer.valueOf(b) / Integer.valueOf(a));
        }
    }

    public static void main(String[] args) {
        String[] tokens = new String[] {"2","1","+","3","*"};
        Solution solution = new Solution();
        System.out.println(solution.evalRPN(tokens));
    }
}