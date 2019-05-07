/**
 * You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -.
 *
 * For each integer, you should choose one from + and - as its new symbol.
 *
 * Find out how many ways to assign symbols to make sum of integers equal to target S.
 *
 * Example 1:
 * Input: nums is [1, 1, 1, 1, 1], S is 3.
 * Output: 5
 * Explanation:
 *
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 *
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * Note:
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * */
package dynamic_programming.target_sum_494;

public class Solution {
    /**
     * brute force 方法不能使用,根据题目中的要求 假设 n = 20, 则时间复杂度为 2^20, 时间太长了.
     *
     * 但是看了答案之后,发现使用 BF 算法也是可以的,也能通过leetcode 的测试集
     *
     * */
    private int count = 0;
    public int findTargetSumWays(int[] nums, int S) {
        if (nums == null || nums.length  == 0) {
            return 0;
        }
        calculate(nums, 0, 0, S);
        return count;
    }

    private void calculate(int[] nums, int index, int sum , int target) {
        if (index == nums.length) {
            if (sum == target) {
                count++;
            }
        } else {
            calculate(nums, index+1, sum - nums[index], target);
            calculate(nums, index+1, sum + nums[index], target);
        }
    }
}
