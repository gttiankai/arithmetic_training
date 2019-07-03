package string.decode_ways_91;

public class Solution2 {
    /**
     * Runtime: 1 ms, faster than 98.64% of Java online submissions for Decode Ways.
     * Memory Usage: 34.5 MB, less than 99.22% of Java online submissions for Decode Ways.
     *
     * */
    public int numDecodings(String s) {

        if (s == null || s.length() == 0) {
            return 0;
        }
        int n = s.length();
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = (isValidS(s, 0)? 1:0);
        for (int i = 2; i <= n;i++) {
            if (isValidS(s, i-1)) {
                dp[i] += dp[i-1];
            }
            if (isValidD(s, i-1)) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
    private boolean isValidS(String s, int index) {
        int value = s.charAt(index) - '0';
        if (value > 0 && value < 27) {
            return true;
        } else {
            return false;
        }
    }
    private boolean isValidD(String s, int index){
        if (!isValidS(s, index-1)) {
            return false;
        }
        int value = (s.charAt(index-1) - '0' ) * 10 + (s.charAt(index) - '0');
        if (value < 27) {
            return true;
        } else {
            return false;
        }
    }
}
