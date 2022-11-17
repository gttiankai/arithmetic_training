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
        // 未优化版本
//        for(int i = index + 1; i <= nums[index] + index ; i++) {
//            if (true == backtrace(nums, i)) {
//                return true;
//            }
//        }
        // 这个版本是优化过得.是从右到左进行,
        for (int i = nums[index]; i > 0; i--) {
            if (true == backtrace(nums, index + i)) {
                return true;
            }
        }


        return false;
    }

    /**
     * 最简单的答案,但是没有弄清楚,
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

    /**
     * dp方法,dp的方法结合了上面的回溯的方法,但是在回溯法的基础上进行了优化
     * 优化的地方: 引入了dp[i], 表示i位置能否jump到最后一个位置.
     * dp[i]的初始化为unknown, 然后使用动态规划的方案进行处理.
     *
     * WARNING: 即使使用了这个动态规划的算法,发现运行时间还是超时了, 需要进一步提高运行效率
     *
     * */
    enum Index {
        GOOD, BAD,UNKNOWN
    }
    public static Index[] memo;

    public static boolean canJumpFailedThirty(int[] nums) {
        memo = new Index[nums.length];
        // initial the memory map
        for (int i = 0; i < memo.length; i++) {
            memo[i] = Index.UNKNOWN;
        }
        // 最后一个节点,本身就已经在最后了,所以肯定能够到达的.
        memo[memo.length - 1] = Index.GOOD;
        return canJumpFromPosition(0, nums);
    }

    public static boolean canJumpFromPosition(int position, int[] nums) {
        if (memo[position] != Index.UNKNOWN) {
            return memo[position] == Index.GOOD ? true : false;
        }

        /**
         * 这个版本是优化前的版本,
         * */
//        int furthestJump = Math.min(position + nums[position], nums.length - 1);
//        for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
//            if (canJumpFromPosition(nextPosition, nums)) {
//                memo[position] = Index.GOOD;
//                return true;
//            }
//        }
        // 当有了memo之后就必须添加这个,因为如果nextPosition会超出memo的大小,造成内存数组越界的问题
        int furthestJump = Math.min(position + nums[position], nums.length - 1);
        for (int nextPosition = furthestJump; nextPosition > position; nextPosition--) {
            // 其实这个里面有一个优化的地方,就是如何消除递归
            if (canJumpFromPosition(nextPosition, nums)) {
                memo[position] = Index.GOOD;
                return true;
            }
        }
        memo[position] = Index.BAD;
        return false;
    }


    /**
     * 接下来要进行进一步的进行效率的优化.
     * 优化的具体的思路就是消除递归,这样才能满足需求.
     * 消除递归的通常的方式: The recursion is usually eliminated by trying to reverse the order of the steps
     *  from the top-down approach.
     *
     *
     * */
    public  Index[] dp;
    public  boolean canJumpDP(int[] nums) {
        if (null == nums || nums.length == 0) {
            return false;
        }
        dp = new Index[nums.length];
        for (Index item:
             dp) {
            item = Index.UNKNOWN;
        }
        dp[nums.length-1] = Index.GOOD;
        for (int i = nums.length - 2; i >= 0; i--){
            int furthestJump = Math.min(nums[i] + i, nums.length-1);
            // 其实这个方案的思想和上一个递归的方案是一致的,但是由于消除了递归,所以速度上会快.能够通过测试.
            for (int j = i + 1; j <= furthestJump; j ++) {
                if (dp[j] == Index.GOOD) {
                    dp[i] = Index.GOOD;
                    break;
                }
            }
        }
        return dp[0] == Index.GOOD;
    }

    /**
     * 通过看答案居然能够使用贪心算法, 太牛了
     *
     * */
    public static boolean canJump(int[] nums) {
        if (nums == null) {
            return false;
        }
        int lastPosition = nums.length - 1;
        for (int i = lastPosition ; i >= 0; i--) {
            //
            if (i + nums[i] >= lastPosition) {
                lastPosition = i;
            }
        }
        return lastPosition == 0;
    }


    public static void main(String[] arguments) {
        int[] nums = {3, 2, 1, 0, 4}; // false
        int[] nums1 = {2, 3, 1, 1, 4};// true
        int[] nums2 = {0, 1}; // false
        int[] nums3 = {2, 0, 1, 0, 1}; // false
        int[] nums4 = {0}; // true
        int[] nums5 = {2,0};
        System.out.printf("" + canJump(nums5));
    }
}
