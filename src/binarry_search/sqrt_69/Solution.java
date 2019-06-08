/**
 * implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and only the integer
 *
 * part of the result is returned.
 *
 * Example 1:
 *
 * Input: 4
 * Output: 2
 * Example 2:
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 *              the decimal part is truncated, 2 is returned.
 *
 * */

package binarry_search.sqrt_69;

public class Solution {
    /*
    * 直接中招了，注意题目中给出的条件，x 是非负整数，也就是说 x 的范围是 [- 2^31 , 2^31-1]
    *
    * 我题目中的解法是从 1 开始遍历，由于我的解法中是判断 i*i 和 （i+1）*（i+1）,此时肯定存在一种情况
    *
    * i*i在 int 型的取值范围内，但是 (i+1)*(i+1)超出了 int 型的取值返回，当超出 int 型的取值范围后，
    * java 会直接截取有效的位数，丢失多余的位数，这就造成我们算法的失败。
    * */
    public int mySqrt(int x) {
        if (x == 1 || x == 0) {
            return x;
        }
        int half = x / 2;
        int i =0;
        for (; i <= half; i++) {
            if (i*i == x) {
                return i;
            } else if (i * i < x && (i+1)*(i+1) > x){
                return i;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        int x = 2147483647;
        Solution solution = new Solution();
        System.out.println(solution.mySqrt(x));
    }
}
