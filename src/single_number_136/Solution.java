/**
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 * Example 1:
 *
 * Input: [2,2,1]
 * Output: 1
 * Example 2:1
 *
 * Input: [4,1,2,1,2]
 * Output: 4
 * 要求: 时间复杂度 O(n), 空间复杂度:不适用额外的内存
 *
 * */
package single_number_136;

import java.util.Arrays;A

public class Solution {
    // 第一个办法是排序, 但是时间复杂度会高一点,及时使用优秀的排序算法,但是也不会达到O(n)
    public int singleNumberSort(int[] nums) {
        // 由于题目中一定提到,是非空的序列,所以不用在做校验了
//        if (nums == null || nums.length == 0) {
//            return
//        }
        Arrays.sort(nums);
        //  这样写的目的是为了更好的处理
        for (int i = 1; i < nums.length; i += 2) {
            if (nums[i-1] != nums[i]){
                return nums[i-1];
            }
        }
        return nums[nums.length-1];
    }

    public int singleNumberSort(int[] nums)
}
