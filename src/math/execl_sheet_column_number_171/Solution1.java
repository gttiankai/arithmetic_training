package math.execl_sheet_column_number_171;

public class Solution1 {

    /**
     * 本来想优化一下，结果没有成功还是 99.92%
     * Runtime: 1 ms, faster than 99.92% of Java online submissions for Excel Sheet Column Number.
     * Memory Usage: 35.8 MB, less than 70.60% of Java online submissions for Excel Sheet Column Number.
     * */
    public int titleToNumber(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int n = s.length();
        int ans = 0;
        int[] map = new int[256];
        map[0] = 1;
        for (int i = 1; i < n; i++) {
            map[i] = map[i-1] * 26;
        }
        for (int i = n-1; i >= 0; i--) {
            ans = ans + (s.charAt(i) - 'A' + 1) * map[n - 1 - i];
        }
        return ans;
    }
}
