/**
 * 给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 *
 * 你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
 *
 * 示例:
 *
 * 给定 nums = [2, 7, 11, 15], target = 9
 *
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 **/
package two_sum_1;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Hashtable;

public class Solution {
    /*
      return the index of int array
    */
    public int[] twoSum(int[] nums, int target) {
        int length = nums.length;
        int[] result = new int[2];
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (target == nums[i] + nums[j]) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
        throw new IllegalArgumentException("no two sum solution");
    }
    public int[] twoSumHash(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }
        for (int j = 0; j < nums.length; j++) {
            int needNumber = target - nums[j];
            if (map.get(needNumber) != null && map.get(needNumber) != j){
                return new int[] {j , map.get(needNumber)};
            }
        }
        throw new IllegalArgumentException("no two sum solution");
    }

    public int[] twoSumHashQuick(int[] nums, int target){
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++){
            int complete = target - nums[i];
            if (map.containsKey(complete)) {
                return new int[] {map.get(complete), i};
            }
            map.put(nums[i], i);
        }
        throw  new IllegalArgumentException("no two sum solution");
    }


    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 14;
        int[] nums1 = {3,2,4};
        int target1 = 6;
        Solution solution = new Solution();
        int[] result = solution.twoSumHashQuick(nums1, target1);
        System.out.println("the result is " + result[0] + " and " + result[1]);
    }
}
