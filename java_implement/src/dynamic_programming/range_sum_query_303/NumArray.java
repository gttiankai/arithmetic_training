/**
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j),
 * inclusive.
 * <p>
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * <p>
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 */
package dynamic_programming.range_sum_query_303;


import java.util.HashMap;
import java.util.Map;

public class NumArray {
    private int[] map;
    private int[] array;

    public NumArray(int[] nums) {
        int len = nums.length;
        this.map = new int[len + 1];
        for (int i = 0; i < nums.length; i++) {
            map[i + 1] = map[i] + nums[i];
        }
    }

    public int sumRange(int i, int j) {
        return map[j + 1] - map[i];
    }

    public int sumRangeBurteForce(int i, int j) {
        if (i > j) return 0;
        int result = 0;
        for (int count = i; count <= j; count++) {
            result += array[count];
        }
        return result;
    }
    public static void main(String[] arguments) {
        int[] array = {-2, 0, 3, -5, 2, -1};
        NumArray obj = new NumArray(array);
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length; j++) {
                int param_1 = obj.sumRange(i, j);
                System.out.printf("the result: sumRange(%d,%d):%d\n", i, j, param_1);
            }
        }

    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
