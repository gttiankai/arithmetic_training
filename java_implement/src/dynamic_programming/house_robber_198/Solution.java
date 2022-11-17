/**
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
 * the only constraint stopping you from robbing each of them is that adjacent(相邻的) houses have security system connected
 * and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
 * money you can rob tonight without alerting the police.
 *
 * Example 1:
 *
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 * Example 2:
 *
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 *              Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 * unit test: [2, 1, 1, 2]
 * */

package dynamic_programming.house_robber_198;

import java.util.Dictionary;
import java.util.HashMap;
import java.util.Map;

public class Solution {
    private int[][] mem = new int[][]{};
    public static int robBruteForce(int[] nums){
        /**
         * brute force
         *
         * failed pass: [2, 1, 1, 2]
         * */
        int oddSum = 0;
        int evenSum = 0;
        for (int i = 0; i < nums.length; i+=2){
            oddSum += nums[i];
            if (i+1 >= nums.length){
                break;
            }
            evenSum += nums[i+1];
        }
        return oddSum > evenSum ? oddSum : evenSum;
    }
    public static int robDP(int[] nums) {
        /**
         * Time complex: O(n)
         * Space complex : O(n)
         * */
        int len = nums.length;
        if (0 == len) return 0;
        if (1 == len) return nums[1];

        int[] mark = new int[len+1];

        mark[0] = nums[0];
        mark[1] = Math.max(mark[0], nums[1]);
        /**
         * 从这个例子中明白了一点: 动态规划的入手点是遍历nums数组.遍历这个数组就可以了.
         * */
        for (int i = 2; i <= len-1; i++) {
            mark[i] = Math.max(nums[i] + mark[i-2], mark[i-1]);
        }
        return mark[len-1];

    }

    public static int robDPO(int[] nums) {
        int len = nums.length;
        if (0 == len) return 0;
        if (1 == len) return nums[1];

        int now = 0;
        int last = 0;

        for (int i = 0; i < nums.length; i++) {
            int temp = last;
            last = now;
            now = Math.max(last, nums[i] + temp);
        }
        return now;

    }
    public static void main(String[] arguments){
        int[] house = {2, 7, 9, 7, 1};
        System.out.println("the maximum amount: " + robDP(house));
    }
}
