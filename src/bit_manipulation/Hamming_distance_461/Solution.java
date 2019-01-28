/**
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 ≤ x, y < 231.
 *
 * Example:
 *
 * Input: x = 1, y = 4
 *
 * Output: 2
 *
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑
 *
 * The above arrows point to positions where the corresponding bits are different.
 *
 * */

package bit_manipulation.Hamming_distance_461;

public class Solution {
    /*
    * 这个题目很简单,使用异或的方式,直接达到了 faster than 98.90%
    *
    * */
    public int hammingDistance(int x, int y) {
        // x 异或 y
        int tmp = x ^ y;
        int res = 0;
        while (tmp > 0) {
            if (tmp % 2 == 1) {
                res++;
            }
            tmp = tmp / 2;
        }
        return res;
    }
    public static void main(String[] arguments) {
        Solution solution = new Solution();
        System.out.printf("" + solution.hammingDistance(1, 4));
    }
}
