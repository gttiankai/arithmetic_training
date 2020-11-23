/**
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 * <p>
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * <p>
 * Note:
 * <p>
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like . or *.
 * Example 1:
 * <p>
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * Example 2:
 * <p>
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * Example 3:
 * <p>
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * Example 4:
 * <p>
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
 * Example 5:
 * <p>
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 *
 * unite test:
 * s ="ab"
 * p =".*c"
 * Output: false
 * TODO: Think why ?
 */

package RegularExpressionMatching_10;

public class Solution {
    public static boolean isMatchOlder(String s, String p) {
        if (s == null || p == null) {
            return false;
        }
        int stringLen = s.length();
        int patternLen = p.length();
        int window = stringLen;
        if (patternLen < stringLen) {
            return false;
        }
        for (int i = 0; i + window <= patternLen; i++) {
            int j = 0;
            for (; j < window; j++) {

                if (s.charAt(j) == p.charAt(i + j)
                        || p.charAt(i + j) == '.'
                        || p.charAt(i + j) == '*') {
                    continue;
                } else {
                    break;// end inner loop
                }
            }// end of inner loop
            if (j == window) {
                return true;
            }
        }// end of outer loop
        return false;
    }

    public static boolean isMatch(String text, String pattern) {
        if (pattern.isEmpty()) {
            return true;
        }

        boolean firstMatch = (!text.isEmpty() &&
                (pattern.charAt(0) == text.charAt(0)
                        || pattern.charAt(0) == '.'));
        if (pattern.length() >= 2 && pattern.charAt(1) == '*') {
            return (isMatch(text, pattern.substring(2)) ||
                    (firstMatch && isMatch(text.substring(1), pattern)));
        } else {
            return firstMatch && isMatch(text.substring(1), pattern.substring(1));
        }

    }


    /* *
    * 看题目中可以通过 DP 的思路去解决，思考一下
    *
    *
    *
    * */

    public static void main(String[] arguments) {
//        String s = "mississippi";
//        String p = "mis*is*p*.";
        String s = "aab";
        String p = "c*a*b";

        System.out.println("output " + String.valueOf(isMatch(s, p)));
    }

}
