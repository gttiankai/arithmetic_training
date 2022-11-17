/**
 * Given an array of size n, find the majority element. The majority element is the element
 * <p>
 * that appears more than ⌊ n/2 ⌋ times.
 * <p>
 * You may assume that the array is non-empty and the majority element always exist in the
 * <p>
 * array.
 * <p>
 * Example 1:
 * <p>
 * Input: [3,2,3]
 * Output: 3
 * <p>
 * <p>
 * Example 2:
 * <p>
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 */

package array.majority_element_169;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;

public class Solution {
    // 直接使用现有的 hash表,就可以直接解决问题了
    public static int majorityElementHash(int[] nums) {
        // 不用判断数组是否为空,因为题目中已经说明了
        int length = nums.length;
        if (length == 1) {
            return nums[0];
        }
        // 4/2 = 2
        // 5/2 = 2.5
        int thresHold = length / 2;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int item : nums) {
            if (map.containsKey(item)) {
                int value = map.get(item);
                if (value + 1 > thresHold) {
                    return item;
                }
                map.put(item, value + 1);

            } else {
                map.put(item, 1);
            }
        }
        return -1;
    }

    // 2 3 3        1
    // 1 1 2        1
    // 1 1 1 2      2
    // 1 2 2 2      2

    public static int majorityElementSort(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }

    public static void main(String[] arguments) {
        int[] nums = {2,2,2,2,4,5,6,7};
        Random rand = new Random();

        System.out.printf("" + majorityElementSort(nums));
    }
}
