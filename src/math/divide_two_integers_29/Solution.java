/**
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2

Note:

1. Both dividend and divisor will be 32-bit signed integers.
2. The divisor will never be 0.
3. Assume we are dealing with an environment which could only store integers within the 32-bit signed integer 
    range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 2^31 − 1 when
    the division result overflows.

 * */

package math.divide_two_integers_29;

class Solution {
    /**
     *  unite test:
     *  input : -2147483648 -1
     *  output: 0
     *  expected: 2147483647
     *  解决了上面得特殊情况之后,还有另外一个特殊情况
     *
     *  unite test:
     *  -2147483648
     *  1
     *
     *  针对这些特殊得情况,不好处理
     *  感觉这个题目得解题思路有点问题
     * */
    public int divide(int dividend, int divisor){
        if (dividend == Integer.MIN_VALUE && divisor == -1) return Integer.MAX_VALUE;
        if (divisor == 1) return dividend;
        boolean flag = isNegitive(dividend, divisor);
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
        if (dividend < divisor) {
            return 0;
        }
        int remainder = dividend - divisor;
        int ans = 1;
        while( remainder >= divisor) {
           remainder = remainder -divisor; 
           ans++; 
        }
        return  flag ? ans: -ans;
    }

    private boolean isNegitive(int dividend, int divisor) {
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            return true;
        } else {
            return false;
        }
    }

    public static void main (String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.divide(-2147483648,2));
    }
}
