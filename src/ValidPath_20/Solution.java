/**
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 * Input: "()"
 * Output: true
 * Example 2:
 *
 * Input: "()[]{}"
 * Output: true
 * Example 3:
 *
 * Input: "(]"
 * Output: false
 * Example 4:
 *
 * Input: "([)]"
 * Output: false
 * Example 5:
 *
 * Input: "{[]}"
 * Output: true
 * */

package ValidPath_20;

import java.util.Stack;

public class Solution {

    public boolean isValid(String s) {
        if (null == s || s.length() % 2 != 0) {
            return false;
        }
        Stack<Character> stack = new Stack();
        // 加入一个 guard，减少程序的复杂度
        stack.push('$');
        for(int i = 0; i < s.length(); i++) {
            char item = s.charAt(i);
            if ( '{' == item || '[' == item || '(' == item) {
                stack.push(item);
            } else {
                if (match(stack.peek(), item)) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        if (stack.size() == 1) {
            return true;
        } else {
            return false;
        }
    }
    public boolean match(char left, char right) {
        if (left == '[' && right == ']') {
            return true;
        } else if (left == '{' && right == '}') {
            return true;
        } else if (left == '(' && right == ')') {
            return true;
        } else {
            return false;
        }
    }
}
