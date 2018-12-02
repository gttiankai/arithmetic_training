/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * <p>
 * For example, given n = 3, a solution set is:
 * <p>
 * [
 * "((()))",
 * "(()())",
 * "(())()",
 * "()(())",
 * "()()()"
 * ]
 */


package backtracking.GenerateParentheses_22;


import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static List<String> generateParenthesis(int n) {
        List<String> combinations = new ArrayList<>();
        generateAll(new char[2 * n], 0, combinations);
        return combinations;
    }

    public static void generateAll(char[] current, int pos,
                            List<String> result) {
        if (pos == current.length) {
            if (valid(current)) {
                result.add(new String(current));
            }

        } else {
            current[pos] = '(';
            generateAll(current, pos + 1, result);
            current[pos] = ')';
            generateAll(current, pos + 1, result);
        }
    }

    public static boolean valid(char[] current) {
        int balance = 0;
        for (char c : current) {
            if (c == '(') {
                balance++;
            } else {
                balance--;
            }
            if (balance < 0) {
                return false;
            }
        }
        return (balance == 0);
    }


    /**
     * 使用回溯法进行求解
     *
     *
     * */
    public static List<String> generateParenthesisDFS(int n) {
        List<String> res = new ArrayList();
        backtrack(res, "", 0, 0, n);
        return res;
    }

    private static void backtrack(List<String> res, String cur, int open, int close, int max){
        if (cur.length() == max * 2) {
            res.add(cur);
            return;
        }
        if (open < max)
            backtrack(res, cur+"(", open+1, close, max);
        if (close < open)
            backtrack(res, cur+")", open, close+1, max);
    }





    public static void main(String[] arguments) {
        System.out.println(generateParenthesisDFS(3));
    }
}
