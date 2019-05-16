/**
 * Given a string, your task is to count how many palindromic substrings in this string.
 *
 * The substrings with different start indexes or end indexes are counted as different
 *
 * substrings even they consist of same characters.
 *
 * Example 1:
 *
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 *
 * Example 2:
 *
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 *
 * Note:
 *
 * The input string length won't exceed 1000.
 *
 * */

package dynamic_programming.palindromic_substrings_647;

public class Solution {
    /**
     * Runtime: 83 ms, faster than 14.13% of Java online submissions for Palindromic Substrings.
     *
     * */
    public int countSubstrings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int ans = 0;
        int n = s.length();
        for (int window = 1; window <= n; window++) {
            for (int i = 0; i + window <= n; i++) {
                if (isPalindromic(s.substring(i, i + window))){
                    ans++;
                }
            }
        }
        return ans;

    }
    private boolean isPalindromic(String s) {
        int n = s.length();
        int half = n / 2;
        for (int i = 0; i <= half; i++) {
            if (s.charAt(i) != s.charAt(n-1-i)){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] arguments) {
        String s = "aaabb";
        Solution solution = new Solution();
        System.out.println(solution.countSubstrings(s));
    }
}
