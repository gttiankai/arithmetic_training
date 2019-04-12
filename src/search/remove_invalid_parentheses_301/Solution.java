/**
 * Remove the minimum number of invalid parentheses in order to make the input string valid.
 *
 * Return all possible results.
 *
 * Note: The input string may contain letters other than the parentheses ( and ).
 *
 * Example 1:
 *
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 * Example 2:
 *
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 * Example 3:
 *
 * Input: ")("
 * Output: [""]
 *
 * */
package search.remove_invalid_parentheses_301;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    /**
     * 这个题目还是有一定的难度的,我是直接参考:
     * https://zxi.mytechroad.com/blog/searching/leetcode-301-remove-invalid-parentheses/
     * 博客中讲解的方法如下所示:
     */
    public List<String> removeInvalidParentheses(String s) {

        char[] list = s.toCharArray();

        // count the l and r
        int r = 0;
        int l = 0;
        // 这一部分的逻辑,我自己写的话,就不一定写出来
        for (char c : list) {
            if (c == '(') {
                l++;
            }
            if (l == 0) {
                // 当前字符左边的所有字符都是合法的.
                if (c == ')') {
                    r++;
                }
            } else {
                if (c == ')') {
                    // 有对应的字符,将 l 减去一
                    l--;
                }
            }
        }
        ArrayList<String> ans = new ArrayList<>();
        dfs(s, 0, l, r, ans);
        return ans;
    }

    /**
     * 这个方法的逻辑是最复杂的.
     */
    private void dfs(String s, int start, int l, int r,
                     List<String> ans) {
        if (l == 0 && r == 0) {
            if (isValid(s)) {
                ans.add(s);
            } else {
                return;
            }
        }
        for (int i = start; i < s.length(); i++) {
            //
            if (i != start && s.charAt(i) == s.charAt(i - 1)) {
                // 这一步说白了,是为了减少运行的步数,如果当前字符和前一个字符是一致的
                // 就不用再进行重复的计算了,都是不对的.
                continue;
            }
            if (s.charAt(i) == '(' || s.charAt(i) == ')') {
                // 过滤掉不是括号的字符.
                String curr = s.substring(0, i) + s.substring(i + 1);
                if (r > 0 && s.charAt(i) == ')') {
                    // 先删除有括号
                    dfs(curr, i, l, r - 1, ans);
                } else {
                    dfs(curr, i, l - 1, r, ans);
                }
            }

        }
    }

    /**
     * 这个方法很厉害的地方,是使用一个变量 count 直接表示了如何进行括号是否匹配的判断
     * 比以前使用栈之类的算法,高效的多.
     **/
    private boolean isValid(String s) {
        char[] list = s.toCharArray();
        int count = 0;
        for (char c : list) {
            if (c == '(') {
                count++;
            }
            if (c == ')') {
                count--;
            }
            if (count < 0) {
                return false;
            }
        }
        return count == 0;
    }
}
