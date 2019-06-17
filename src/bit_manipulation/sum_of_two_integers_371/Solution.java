/**
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
 * */

package bit_manipulation.sum_of_two_integers_371;

class Solution {
    // TODO:
    //  write a blog for this problem in future
    //  这个题目挺不错得,说明了如何进行移位操作
    //  Runtime: 0 ms, faster than 100.00% of Java online submissions for Sum of Two Integers.
    //  Memory Usage: 33 MB, less than 12.33% of Java online submissions for Sum of Two Integers.
    public int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }
        if (b == 0) {
            return a;
        }
        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
}
