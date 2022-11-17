/**
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28
 *     ...
 * Example 1:
 *
 * Input: "A"
 * Output: 1
 * Example 2:
 *
 * Input: "AB"
 * Output: 28
 * Example 3:
 *
 * Input: "ZY"
 * Output: 701
 *
 * */
package math.execl_sheet_column_number_171;

public class Solution {
    /**
     * Runtime: 1 ms, faster than 99.92% of Java online submissions for Excel Sheet Column Number.
     * Memory Usage: 35.9 MB, less than 70.60% of Java online submissions for Excel Sheet Column Number.
     *
     * */
    public int titleToNumber(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int n = s.length();
        double ans = s.charAt(n-1) - 'A' + 1;
        for (int i = n-2; i >= 0; i--) {
            ans = ans + (s.charAt(i) - 'A' + 1) * (Math.pow(26, n - 1 -i));
        }
        return (int)ans;
    }
}
