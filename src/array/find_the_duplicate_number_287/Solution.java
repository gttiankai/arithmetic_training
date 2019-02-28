/**
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
 *
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
 *
 * find the duplicate one.
 *
 * Example 1:
 *
 * Input: [1,3,4,2,2]
 * Output: 2
 * Example 2:
 *
 * Input: [3,1,3,4,2]
 * Output: 3
 * Note:
 *
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 *
 * */

package array.find_the_duplicate_number_287;

public class Solution {
    /**
     * 题目中有要求：
     *      1. 数组不可更改
     *      2. 空间复杂度是： O(n)
     *      3. 时间复杂度是: O(n)
     *      如果抛开上面的限制，其实有很多好的解法
     *      1. 排序法
     *      2. 集合法，或者Hash冲突发，都可以的。
     * */
    public int findDuplicate(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int sum = 0;
        int n = nums.length-1;
        for (Integer item: nums) {
            sum = sum + item;
        }
        int res = sum - n*(n-1)/2;
        return res;
    }

}
