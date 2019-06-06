/**
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a string.
 *
 *
 *
 * Example 1:
 *
 * Input: 1
 * Output: "1"
 * Example 2:
 *
 * Input: 4
 * Output: "1211"
 * */

package string.count_and_say_38;

public class Solution {
    /**
     * Runtime: 1 ms, faster than 99.11% of Java online submissions for Count and Say.
     * Memory Usage: 34 MB, less than 100.00% of Java online submissions for Count and Say.
     *
     * 第一次编写就写成了最优解，说明算法的基本功有进步。
     *
     * */
    public String countAndSay(int n) {
        if (n < 1) {
            return "";
        }
        String[] countSay = new String[n];
        countSay[0] = "1";
        for (int i = 1; i < n; i++) {
            countSay[i] = count(countSay[i - 1]);
        }
        return countSay[n - 1];
    }

    private String count(String preString) {
        StringBuilder str = new StringBuilder();
        int i = 0;
        while (i < preString.length()) {
            char say = preString.charAt(i);
            int j = i+1;
            while (j < preString.length() && say == preString.charAt(j)) {
                j++;
            }
            int count = j - i;
            str.append(count).append(say);
            i = j;
        }
        return str.toString();
    }

    public static void main(String[] arguments) {
        int n = 5;
        Solution solution = new Solution();
        System.out.println(solution.countAndSay(5));
    }
}
