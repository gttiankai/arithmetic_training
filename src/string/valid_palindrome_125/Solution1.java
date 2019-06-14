package string.valid_palindrome_125;

public class Solution1 {
    /**
     * 看到一个好玩的解法，代码量真的超级简单，
     * 但是效率不是很高.
     *
     * Runtime: 25 ms, faster than 7.46% of Java online submissions for Valid Palindrome.
     * Memory Usage: 37.3 MB, less than 74.12% of Java online submissions for Valid Palindrome.
     */

    public boolean isPalindrome(String s) {
         String str = s.replaceAll("[^a-z^A-Z^0-9]", "").toLowerCase();
         String reverseStr = new StringBuilder(str).reverse().toString();
         return str.equals(reverseStr);
    }

    public static void main(String[] args) {
        String s = "1a2";
        Solution1 solution = new Solution1();
        System.out.println(solution.isPalindrome(s));
    }
}
