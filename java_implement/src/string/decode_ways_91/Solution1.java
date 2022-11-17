package string.decode_ways_91;

public class Solution1 {
    /**
     * Runtime: 2 ms, faster than 51.07% of Java online submissions for Decode Ways.
     * Memory Usage: 36 MB, less than 69.83% of Java online submissions for Decode Ways.
     * 思路很好,但是还不是最快的解法
     *
     * */

    public int numDecodings(String s) {

        if (s == null || s.length() == 0) {
            return 0;
        }
        int n = s.length();
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = s.charAt(0) != '0'?1:0;
        for (int i = 2; i <= n; i++) {
            int first = Integer.valueOf(s.substring(i-1, i));
            int seconde = Integer.valueOf(s.substring(i-2, i));

            if (first >0 && first < 10) {
                dp[i] += dp[i-1];
            }
            if (seconde > 9 && seconde < 27) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
}
