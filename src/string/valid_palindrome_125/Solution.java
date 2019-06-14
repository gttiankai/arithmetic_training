/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid palindrome.
 *
 * Example 1:
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * Example 2:
 *
 * Input: "race a car"
 * Output: false
 *
 * */

package string.valid_palindrome_125;

public class Solution {
    /**
     * Runtime: 20 ms, faster than 15.14% of Java online submissions for Valid Palindrome.
     * Memory Usage: 39.6 MB, less than 15.13% of Java online submissions for Valid Palindrome.
     *
     * 题目记录：
     * 1. 忘记了特殊条件，字符串为 1 的情况
     * 2. 还有对题目的理解有问题，题目中是指针对字符和数字，结果搞成了只比对字母
     * 3. 方案还有待优化的地方，
     *
     * */
    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return true;
        }
        s = s.replaceAll("[^a-z^A-Z^0-9]", "").toLowerCase();
        if (s.length() == 0 || s.length() == 1) {
            return true;
        }
        int left = 0;
        int right = s.length()-1;
        while (left <= right) {
            if (s.charAt(left) != s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    public static void main(String[] args) {
        String s = "0P";
        Solution solution = new Solution();
        System.out.println(solution.isPalindrome(s));
    }

}
