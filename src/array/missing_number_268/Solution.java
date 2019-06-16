/**
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 *
 * find the one that is missing from the array.
 *
 * Example 1:
 *
 * Input: [3,0,1]
 * Output: 2
 * Example 2:
 *
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it
 *
 * using only constant extra space complexity?
 *
 */


package array.missing_number_268;

import java.util.Arrays;

public class Solution {
    /**
     * Runtime: 6 ms, faster than 24.30% of Java online submissions for Missing Number.
     * Memory Usage: 39 MB, less than 69.44% of Java online submissions for Missing Number.
     *
     * 排序法
     * */
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i< nums.length; i++) {
            if (i != nums[i]){
                return i;
            }
        }
        return nums.length;
    }

    public static void main(String[] args) {
        int[] nums = new int[] {0};
        Solution solution = new Solution();
        System.out.println(solution.missingNumber(nums));
    }
}
