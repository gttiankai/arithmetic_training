package string.decode_ways_91;

public class Solution {
    /**
     * 需要特殊处理的有两类:
     * 1. 超过26的
     * 2. 含有0的状况
     *
     * Runtime: 1 ms, faster than 98.64% of Java online submissions for Decode Ways.
     * Memory Usage: 34.4 MB, less than 96.60% of Java online submissions for Decode Ways.
     *
     * 虽然自己的算法可以解决这个问题,但是感觉算法太丑了, special case 太多了,肯定会有比较简单的接法.
     * */
    public int numDecodings(String s) {

        if (s == null || s.length() == 0) {
            return 0;
        }
        int n = s.length();
        if (n < 2) {
            return  isValidS(s, 0)? 1:0;
        }
        int[] dp = new int[n];
        dp[0] = isValidS(s, 0)? 1:0;
        if (isValidS(s, 1)) {
            dp[1] = dp[0] + (isValidD(s, 1) ? 1 : 0);
        } else {
            if (isValidD(s, 1)) {
                dp[1] = dp[0];
            } else {
                return 0;
            }
        }
        for (int i = 2; i < n; i++) {
            if (isValidS(s,i)) {
                if (isValidD(s, i)) {
                    dp[i] = dp[i - 2] + dp[i-1];
                } else {
                    dp[i] = dp[i - 1];
                }
            }else  if (isValidD(s, i)) {
                dp[i] = dp[i-2];
            } else {
                return 0;
            }

        }
        return dp[n - 1];
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

    public static void main(String[] args) {
        String s = "";
        Solution solution = new Solution();
        System.out.println(solution.numDecodings(s));
    }
}
