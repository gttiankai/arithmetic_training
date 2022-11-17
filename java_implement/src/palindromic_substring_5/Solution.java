/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * Example 2:
 *
 * Input: "cbbd"
 * Output: "bb"
 * **/

/**
 * unit test:
 *      1. ""
 *      2. "a"
 *      3. "abc"
 *
 * **/

package palindromic_substring_5;

public class Solution {

    public static int lo, maxLen;

    /*
    * 时间复杂度是O(n^2)
    * */

    public static String longestPalindrome1(String s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }
        for (int i = 0; i < len -1; i++) {
            extendPalindrome(s, i , i);
            extendPalindrome(s, i,i + 1);

        }
        return s.substring(lo, lo + maxLen);
    }
    /**
     *  这种算法最精妙之处就是对回文字符串的判断
     * **/
    private static void extendPalindrome(String s, int j, int k) {
        while (j >= 0 && k < s.length() && s.charAt(j) == s.charAt(k)) {
            j --;
            k++;
        }
        if (maxLen < k - j -2 +1) {
            lo = j + 1;
            maxLen = k -j - 2 +1;
        }
    }


    /**
     * 本方法是暴力法，时间复杂度：O(n^3)
     * **/
    public static String longestPalindrome(String s) {
        if (s.length() == 0) {
            return "";
        }
        if (s.length() == 1) {
            return s;
        }
        int window = 1;
        int longest = 0;
        String longestSubstr = s.substring(0,1);
        char[] array = s.toCharArray();
        for (; window <= array.length; window++) {
            for(int i = 0; i + window <= array.length; i++) {
                if ( isPalindromic(s.substring(i, i + window))) {
                    if (longest < window) {
                        longestSubstr = s.substring(i , i + window);
                    }
                }
            }
        }
        return longestSubstr;
    }

    private static boolean isPalindromic(String str){
        if (str.length() == 1) {
            return true;
        }
        char[] array = str.toCharArray();
        for (int i = 0; i < array.length / 2; i ++) {
            if (array[i] != array[array.length -i-1]){
                return false;
            }
        }
        return true;
    }

    public String longestPalindromic(String s) {
        /**
         * dp(i, j) = (s[i] == s[j]) && dp[i+1, j -1]
         * **/
        int n = s.length();
        String res = null;

        boolean[][] dp = new boolean[n][n];

        for (int i = n-1; i >= 0; i--){
            for (int j = i; j < n; j ++) {
                /**
                 *  比较精髓的是 j - i < 3的判定是处理特殊情况: a, aa , aba,这三种情况代表的回文子字符串的情况
                 * */
                dp[i][j] = (s.charAt(i) == s.charAt(j) && (j - i < 3 || dp[i+1][j-1]));
                /**
                 * 更新res，res保存的是最长的回文子字符串
                 * */
                if (dp[i][j] && (res == null || j - i +1 > res.length())) {
                    res = s.substring(i , j+1);
                }
            }
        }
        return res;
    }


    public static String longestPalindromeDynamicProgramming(String s) {
        return null;
    }

    public static void main(String[] arguments) {
        String s1 = "babad";
        String s2 = "abacdfgdcaba";
        String s3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        System.out.println("the longest palindromic substring :"
                + longestPalindrome(s2));
    }
}
