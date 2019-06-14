/**
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Example 1:
 *
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * Example 2:
 *
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * Note: Your solution should be in logarithmic time complexity.
 *
 * */
package math.factorial_trailing_zeroes_172;

class Solution {
    public int trailingZeroes(int n) {
        //TODO how to solve this problem

        /**
         * Because all trailing 0 is from factors 5 * 2.
         * But sometimes one number may have several 5 factors, for example, 25 have two 5 factors,
         * 125 have three 5 factors. In the n! operation, factors 2 is always ample.
         * So we just count how many 5 factors in all number from 1 to n.
         *
         * Runtime: 0 ms, faster than 100.00% of Java online submissions for Factorial Trailing Zeroes.
         * Memory Usage: 33.1 MB, less than 39.44% of Java online submissions for Factorial Trailing Zeroes.
         *
         * 直接看答案，感觉这个算法太牛了，解释的也很牛
         * */


        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
}