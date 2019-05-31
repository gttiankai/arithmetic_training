package backtracking.GenerateParentheses_22;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution1 {
    /**
     * Runtime: 5 ms, faster than 6.84% of Java online submissions for Generate Parentheses.
     */
    public List<String> generateParenthesis(int n) {
        if (n == 0) {
            return new ArrayList<>();
        }
        ArrayList<String> ans = new ArrayList<>();
        backTrace(ans, new StringBuilder('('), 0, n);
        return ans;
    }

    private void backTrace(ArrayList<String> ans, StringBuilder tmpString, int index, int slots) {
        if (index == slots * 2) {
            ans.add(tmpString.toString());
            return;
        }

        if (isValid(tmpString.append('(').toString(), slots)) {
            backTrace(ans, tmpString, index + 1, slots);
        }
        tmpString.deleteCharAt(tmpString.length() - 1);

        if (isValid(tmpString.append(')').toString(), slots)) {
            backTrace(ans, tmpString, index + 1, slots);
        }
        tmpString.deleteCharAt(tmpString.length() - 1);
    }

    private boolean isValid(String string, int slots) {
        if (string == null || string.length() == 0) {
            return true;
        }
        int left = 0;
        int right = 0;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < string.length(); i++) {
            if (string.charAt(i) == '(') {
                left++;
                if (left > slots) {
                    return false;
                }
            }
            if (string.charAt(i) == ')') {
                right++;
                if (right > slots) {
                    return false;
                }
            }
            if (stack.size() == 0) {
                if (string.charAt(i) == ')') {
                    return false;
                }
                stack.push(string.charAt(i));
            } else {
                if (stack.peek() == '(' && string.charAt(i) == ')') {
                    stack.pop();
                } else {
                    stack.push(string.charAt(i));
                }
            }
            if (stack.size() > slots) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] arguments) {
        int n = 3;
        Solution1 solution = new Solution1();
        List<String> ans = solution.generateParenthesis(n);
        System.out.println(ans);
    }
}
