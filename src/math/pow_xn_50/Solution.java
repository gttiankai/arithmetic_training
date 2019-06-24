package math.pow_xn_50;

public class Solution {
    /**
     * 使用 BF 算法
     *
     * 果然 time limit exceeded
     * */
    public double myPow(double x, int n) {
        double ans = 1;
        if (n == 0) {
            return ans;
        }
        boolean negative = n < 0? true: false;
        n = Math.abs(n);
        for (int i = 1; i <= n; i++) {
            ans = ans * x;
        }
        if (negative) {
            return  ans = 1 / ans;
        } else {
            return ans;
        }
    }
}
