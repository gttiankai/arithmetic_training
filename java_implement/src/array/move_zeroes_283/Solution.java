/**
 * Given an array nums, write a function to move all 0's to the end of it while maintaining
 * <p>
 * the relative order of the non-zero elements.
 * <p>
 * Example:
 * <p>
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * <p>
 * Note:
 * <p>
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */


package array.move_zeroes_283;

public class Solution {
    /**
     * 使用复制的方式是可以解决这个问题的,但是空间复杂度是 O(n), leetcode 也能通过
     * <p>
     * 但是题目中要求不能这么做,要想其他办法
     * <p>
     * 其中这种思路再稍微优化一下,就可以直接有标准答案了
     */
    public void moveZeroesCopy(int[] nums) {
        if (nums == null || nums.length == 0) {
            return;
        }
        int[] res = new int[nums.length];
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                res[j] = nums[i];
                j++;
            }
        }
        for (; j < nums.length; j++) {
            res[j] = 0;
        }
        System.arraycopy(res, 0, nums, 0, nums.length);
    }


    /**
     * 使用类似于冒泡排序的算法,可以直接解决这个问题
     * <p>
     * 空间复杂度 O(1)
     * 时间复杂度 O(n^2)
     */
    public void moveZeroesBubbleSort(int[] nums) {
        if (nums == null || nums.length == 0) {
            return;
        }
        int hasZerors = 0;
        for (int i = nums.length; i > 0; i--) {
            for (int j = 0; j < i - 1; j++) {
                if (nums[j] == 0) {
                    int tmp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = tmp;
                }
            }
        }
    }

    /**
     * 还有一种办法,两个指针的办法解决这个问题
     * <p>
     * two pointer
     */
    public void moveZeroesTwoPointer(int[] nums) {
        if (nums == null || nums.length == 0) {
            return;
        }
        int lastNotZerors = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                nums[lastNotZerors] = nums[i];
                lastNotZerors++;
            }
        }
        for (; lastNotZerors < nums.length; lastNotZerors++) {
            nums[lastNotZerors] = 0;
        }
    }
}
