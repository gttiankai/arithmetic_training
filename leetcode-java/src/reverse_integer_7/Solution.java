/**
 *  Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 * Input: 123
 * Output: 321
 * Example 2:
 *
 * Input: -123
 * Output: -321
 * Example 3:
 *
 * Input: 120
 * Output: 21
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit
 * signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your
 * function returns 0 when the reversed integer overflows.
 *
 * */

package reverse_integer_7;

import java.util.ArrayList;
import java.util.List;

public class Solution {

    public static int reverse(int x) {
        if (x > Integer.MAX_VALUE || x <  Integer.MIN_VALUE ) {
            return 0;
        }
        ArrayList<Integer> list = new ArrayList<Integer>();
        // 余数
        int remainder;
        // 商
        int quotient;
        boolean negative ;

        if (x > 0) {
            /*
            * x 大于 0 的情况
            * */
            negative = false;

        } else {
            /*
            * x 小于 0 的情况
            * */
            negative = true;
        }
        x = Math.abs(x);
        while ( x != 0) {
            quotient = x / 10;
            remainder = x % 10;
            x = quotient;
            list.add(remainder);
        }
        double result = 0;
        for (int i = 0; i < list.size(); i++) {
            result = result * 10  + list.get(i);
        }
        // 需要注意的也就是说这一部分，因为你处在32位的计算机中，如果结果超出了32的限制，
        // 也需要进行处理
        if (result > Integer.MAX_VALUE || result <  Integer.MIN_VALUE ) {
            return 0;
        }
       return negative ? -(int)result: (int) result;
    }

    public static void main(String[] arguments) {
        System.out.println(reverse(1534236469));
    }
    /**
     * 0x5B729735
     * 0x7fffffff
     * */
}
