/**
Given an integer, write a function to determine if it is a power of three.
Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false

Follow up:
Could you do it without using any loop / recursion?
 * */
package math.power_of_three_326;

class Solution {
    // Time limit Exceeded
    // FOCUS:
    // 修改了下面得有可能产生溢出得问题,这个代码就可以生效了.
    // Runtime: 11 ms, faster than 56.03% of Java online submissions for Power of Three.
    // Memory Usage: 35.7 MB, less than 16.75% of Java online submissions for Power of Three.
    public boolean isPowerOfThree(int n ) {
        if (n == 1) {
            return true;
        }
        if ( n == 2) {
            return false;
        }
        double tmp = 3;
        // 这个地方有可能发生溢出,然后就造成死循环了,虽然这个方案超时了,但是也
        // 能掩饰这 bug,修复 bug 得方式很简单,只要 tmp 设置为 double 就可以了.
        while(tmp < n){
            tmp = tmp *3;
        }

        return tmp == n;
    }
}
