/**
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if needle
 *
 * is not part of haystack.
 *
 * Example 1:
 *
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 *
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great question to
 *
 * ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty string.
 *
 * This is consistent to C's strstr() and Java's indexOf().
 * */
package string.implement_strstr_28;

public class Solution {

    /**
     * Runtime: 1 ms, faster than 79.42% of Java online submissions for Implement strStr().
     * Memory Usage: 37.8 MB, less than 68.89% of Java online submissions for Implement strStr().
     *
     * 踩了好几个坑，终于完成了，
     *
     * 这个题目一开始没有做出来的原因是有一些特殊的情况没有考虑清楚。
     * 目前写代码存在的问题，就是有思维的盲点，没有想清楚就写了代码，
     * 造成一定的错误
     *
     * */
    public int strStr(String haystack, String needle) {
        if (needle == null || needle.isEmpty()) {
            return 0;
        }
        if (haystack == null || haystack.isEmpty() || needle.length() > haystack.length() ||
                (needle.length() == haystack.length() && !haystack.equals(needle))) {
            return -1;
        }

        int left = 0;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack.length() - i < needle.length()) {
                return -1;
            }
            if (haystack.charAt(i) == needle.charAt(left)) {
                for (int j = 0; j < needle.length(); j++) {
                    if (haystack.charAt(i + j) != needle.charAt(j)) {
                        break;
                    }
                    if (j == needle.length() - 1) {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
    public static void main(String[] arguments) {
        String haystack = "mississippi", needle = "issip";
        Solution solution = new Solution();
        System.out.println(solution.strStr(haystack, needle));
    }
}
