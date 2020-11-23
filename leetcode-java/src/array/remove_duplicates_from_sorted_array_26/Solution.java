/**
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *
 * Example 1:
 *
 * Given nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 *
 * It doesn't matter what you leave beyond the returned length.
 *
 *
 * Example 2:
 *
 * Given nums = [0,0,1,1,1,2,2,3,3,4],
 *
 * Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
 *
 * It doesn't matter what values are set beyond the returned length.
 * Clarification:
 *
 * Confused why the returned value is an integer but your answer is an array?
 *
 * Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
 *
 * Internally you can think of this:
 *
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 *
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len elements.
 * for (int i = 0; i < len; i++) {
 *     print(nums[i]);
 * }
 * */

package array.remove_duplicates_from_sorted_array_26;

public class Solution {
    /**
     * 关键点:
     *      1. 不能分配额外的空间
     *      2. 可以修改原始的数组
     *
     * Runtime: 1 ms, faster than 99.74% of Java online submissions for Remove Duplicates from Sorted Array.
     * Memory Usage: 38.3 MB, less than 99.94% of Java online submissions for Remove Duplicates
     * 开心, 第一次自己提交,直接是最优解法.
     * */
    public int removeDuplicates(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        int ans = 1;
        for (int i = 1; i < nums.length; i++) {
            if(nums[i] != nums[i-1]){
                nums[ans] = nums[i];
                ans++;
            }
        }
        return ans;
    }
    public static void main(String[] arguments){
        int[] nums = {0,0,1,1,1,2,2,3,3,4};
        Solution solution = new Solution();
        System.out.println(solution.removeDuplicates(nums));
    }
}
