package math.pow_xn_50;

public class Solution2 {
    /**
     * 这个算法还是比较好的,需要注意的点还是很多得.
     * 有一个难点就是关于 INTEGER_MINVALUE 的溢出的处理
     */
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        double half = myPow(x, n / 2);

        if (n % 2 != 0) {
            //奇数
            return n < 0 ? (1 / x) * half * half : x * half * half;
        } else {
            return half * half;
        }
    }

    public static void main(String[] args) {
        double x = 2;
        int n = -2147483648;
        Solution2 solution2 = new Solution2();
        System.out.println(solution2.myPow(x, n));
    }
}
