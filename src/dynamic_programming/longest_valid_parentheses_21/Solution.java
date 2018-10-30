/**
 * Given a string containing just the characters '(' and ')', find the length of the longest
 * valid (well-formed) parentheses substring.
 *
 * Example 1:
 *
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * Example 2:
 *
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 *
 * unit test: "()(()" 合法的子字符串是()，并不是()
 * */


package dynamic_programming.longest_valid_parentheses_21;

import java.util.Stack;

public class Solution {

    /**
     * my stack solution failed
     *
     * */
    public static int longestValidParentheses(String s, int unused) {
        char[] charArray = s.toCharArray();
        char[] stack = new char[charArray.length];
        int top = 0;
        int max = 0;
        int result = 0;
        int left = 0;
        for (int i = 0; i < charArray.length; i++) {
            if (charArray[i] == '(') {
                // push
                stack[top] = '(';
                top++;
            } else if (charArray[i] == ')') {
                // top > 0 && charArray[i] == ')' && stack[top - 1] == '('

                if (top > 0 && stack[top-1] == '('){
                    // pop
                    top--;
                    max++;
                } else {
                    // invalid ')'
                    result = Math.max(result, max);
                    max = 0;
                    top = 0;
                }
            }
        }
        return max *2;
    }

    /**
     * 下面的算法中有几处比较好的设计，后面可以借鉴下：
     * 1. 在这个题目中，不需要 push 字符串‘（）’，因为这两个值都是确定的，没有必要再进行存储了。
     * 2. 真正应该存储的应该是编号，最后最后的栈中还剩下，也表明了最后剩下的
     * */
    public static int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<Integer>();
        char[] chars = s.toCharArray();
        int n = chars.length;
        int longest = 0;
        for (int i = 0; i < n ; i++) {
            if (chars[i] == '(') {
                stack.push(i);
            } else if (chars[i] == ')') {
                if (!stack.empty()) {
                    if (chars[stack.peek()] == '(') {
                        // valid parentheses
                        stack.pop();
                    } else {
                        stack.push(i);
                    }
                } else {
                    stack.push(i);
                }
            }
        }
        if (stack.empty()) {
            longest = n;
        } else {
            int right = n-1;
            int left = 0;
            while (!stack.empty()) {
                left = stack.pop();
                longest = Math.max(longest, right - left);
                right = left-1;

            }
        }
        return longest;

    }

    public static void main(String[] arguments) {
        String s = "()(()()(()()()";
        System.out.println(longestValidParentheses(s));
    }
}

