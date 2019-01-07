/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * <p>
 * Each element in the array represents your maximum jump length at that position.
 * <p>
 * Determine if you are able to reach the last index.
 * <p>
 * Example 1:
 * <p>
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * Example 2:
 * <p>
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 */
package jump_game_55;

public class Solution {
    /**
     * 解决不了一种情况: [2,0,1,0,1]
     * 所以要想其他的办法
     * */
    public static boolean canJumpFailed(int[] nums) {
        if (null == nums || nums.length == 0) {
            return true;
        }
        if (nums.length == 1) {
            return true;
        }
        boolean jump = false;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                break;
            }
            int sum = i + nums[i];
            if (sum < nums.length - 1) {
                if (nums[sum] == 0) {
                    jump = false;
                } else {
                    jump = true;
                }
            } else {
                jump = true;
                break;
            }
        }
        return jump;
    }

    /**
     * 试试回溯法
     *
     * 回溯法可以使用,但是没有经过leetcode 的测试,直接报 time limit exceed!
     *
     * 回溯法针对大型的数据就不行了.
     *
     * */
    public static boolean canJumpFailedAgain(int[] nums) {
        if (null == nums || nums.length == 0) {
            return true;
        }
        return backtrace(nums, 0);
    }

    public static boolean backtrace(int[] nums, int index) {
        if (index >= nums.length - 1) {
            return true;
        }
        if (nums[index] == 0) {
            return false;
        }
        for (int i = nums[index]; i > 0; i--) {
            if (true == backtrace(nums, index + i)) {
                return true;
            }
        }
        return false;
    }

    /**
     * 最简单的答案,但是没有弄清楚
     * */

    public static boolean canJumpUnknown(int[] nums) {
        int max = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > max) {
                return false;
            }
            max = Math.max(nums[i] + i, max);
        }
        return true;
    }

    enum Index {
        GOOD, BAD,UNKNOWN
    }
    Index[] memo;

    public boolean canJumpFromPosition(int position, int[] nums) {
        if (memo[position] != Index.UNKNOWN) {
            return memo[position] == Index.GOOD ? true : false;
        }

        int furthestJump = Math.min(position + nums[position], nums.length - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                memo[position] = Index.GOOD;
                return true;
            }
        }

        memo[position] = Index.BAD;
        return false;
    }

    public boolean canJump(int[] nums) {
        memo = new Index[nums.length];
        // initial the memory map
        for (int i = 0; i < memo.length; i++) {
            memo[i] = Index.UNKNOWN;
        }
        memo[memo.length - 1] = Index.GOOD;
        return canJumpFromPosition(0, nums);
    }


    public static void main(String[] arguments) {
        int[] nums = {3, 2, 1, 0, 4}; // false
        int[] nums1 = {2, 3, 1, 1, 4};// true
        int[] nums2 = {0, 1};
        int[] nums3 = {2, 0, 1, 0, 1};
        int[] nums4 = {0};
        System.out.printf("" + canJump(nums));
    }
}
