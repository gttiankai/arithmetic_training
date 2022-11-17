/**
 * Given an array with n objects colored red, white or blue, sort them in-place so that
 *
 * objects of the same color are adjacent, with the colors in the order red, white
 *
 * and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white,
 *
 * and blue respectively.
 *
 * Note: You are not suppose to use the library's sort function for this problem.
 *
 * Example:
 *
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Follow up:
 *
 * A rather straight forward solution is a two-pass algorithm using counting sort.
 *
 * First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array
 *
 * with total number of 0's, then 1's and followed by 2's.
 *
 * Could you come up with a one-pass algorithm using only constant space?
 *
 * */

package array.sort_colors_75;

public class Solution {
    /**
     *
     * 这种算法可以起一个名字,就叫做计数法
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Sort Colors.
     * */
    public void sortColors(int[] nums) {
        if (nums == null || nums.length == 0) {
            return;
        }
        int zeroNumber = 0;
        int oneNumber = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroNumber++;
            } else if (nums[i] == 1) {
                oneNumber++;
            }
        }
        int j = 0;

        for (; j < zeroNumber; j++) {
            nums[j] = 0;
        }
        for (; j < zeroNumber + oneNumber; j++) {
            nums[j] = 1;
        }
        for (; j < n; j++) {
            nums[j] = 2;
        }
        return;
    }
}
