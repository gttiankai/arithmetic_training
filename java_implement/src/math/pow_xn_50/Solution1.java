package math.pow_xn_50;

public class Solution1 {
    /**
     * 这个算法很好用,但是特殊得情况没有处理好.
     * unite test:
     *  input: 2.00000   -2147483648
     *  output: 1.0
     *  expected: 0.0
     * */
    public double myPow(double x, int n) {
        double ans = 1;
        if (n == 0) {
            return ans;
        }
        boolean negative = n < 0 ? true : false;
        n = Math.abs(n);
        if (negative) {
            x = 1/ x;
        }
        double lastPow = x;
        while (n > 0) {
            if ((n & 1) != 0) {
                ans = ans * lastPow;
            }
            n = n >> 1;
            lastPow = lastPow * lastPow;
        }
        return ans;
    }
}
