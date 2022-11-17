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
     *
     * 这个只能用一种算法解决:Floyd 判圈算法.
     * 这个算法可以用于三个方面:
     *      1. 判断链表中是否有环
     *      2. 求链表中环的长度
     *      3. 求链表中环的起点
     *
     *TODO: 关于 Floyd判圈算法,可以写一篇博客,并且将相关的问题,可以都做一遍.
     * */
    public int findDuplicate(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        } while (true);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }

}
