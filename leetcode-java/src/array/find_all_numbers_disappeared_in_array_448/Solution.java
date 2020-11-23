/**
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 *
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 *
 * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [5,6]
 *
 * */

package array.find_all_numbers_disappeared_in_array_448;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
    // 重点是除了返回的list外,不准有其他的额外的内存空间的占用,并且只遍历一遍数组
    /**
     * 使用哈希表法, 能够解决问题,但是空间复杂度比较大, 时间复杂度O(n)
     * */
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        if (nums == null || nums.length == 0) {
            return list;
        }
        for (int i = 0; i < nums.length; i++) {
            map.put(i+1, 0);
        }
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], map.get(nums[i]) + 1);
        }
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if(entry.getValue() == 0) {
                list.add(entry.getKey());
            }
        }
        return list;
    }
    /**
     * 由于时间复杂度是O(n),所以所有的基于排序的算法都是不能成功的.
     * 学习到一种很有用的方法, 我取名为翻转法
     *
     * */
    public List<Integer> findDisappearedNumbersOp(int[] nums){
        List<Integer> list = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return list;
        }
        for (int i = 0; i < nums.length; i++) {
            int position = Math.abs(nums[i])-1;
            if (nums[position] > 0 ) {
                nums[position] = - nums[position];
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                list.add(i+1);
            }
        }
        return list;
    }
}
