/**
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process:
 *
 * Starting with any positive integer, replace the number by the sum
 *
 * of the squares of its digits, and repeat the process until the number
 *
 * equals 1 (where it will stay), or it loops endlessly in a cycle which
 *
 * does not include 1. Those numbers for which this process ends in 1 are
 *
 * happy numbers.
 *
 * Example:
 *
 * Input: 19
 * Output: true
 * Explanation:
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * */

package hashTable.happy_number_202;

import java.util.LinkedHashSet;
import java.util.Set;

public class Solution {

    /**
     * 这个题目不会，因为不知道什么时候退出，也就是退出条件是不清晰的。
     *
     * FOCUS:
     *  1. 这个题目的退出条件是通过观察得出来的。也就是说，自己随便找一个数字，进行计算，然后观察结果
     *  2. 如果不是“Happy number”，则在计算过程中，出现重复的数字，这个数字不为 “1”，也就是说会进入dead loop
     *  3. 如果是“Happy number”，则最后肯定会进入 “1” 的计算的 dead loop，这就是“Happy number”
     *
     *  这个算法的时间复杂度还算可以
     *  Runtime: 2 ms, faster than 54.08% of Java online submissions for Happy Number.
     *  Memory Usage: 33.4 MB, less than 18.20% of Java online submissions for Happy Number.
     *
     * */
    public boolean isHappy(int n) {
        Set<Integer> set = new LinkedHashSet<>();
        while (n != 1) {
            int sum = 0;
            while (n != 0) {
                sum += Math.pow(n % 10, 2);
                n = n / 10;
            }
            n = sum;
            if (set.contains(n))  {
                break;
            }
            set.add(n);
        }
        return n == 1;
    }

}
