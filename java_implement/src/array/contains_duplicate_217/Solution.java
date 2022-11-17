/**
 * Given an array of integers, find if the array contains any duplicates.
 *
 * Your function should return true if any value appears at least twice in the array,
 *
 * and it should return false if every element is distinct.
 *
 * Example 1:
 *
 * Input: [1,2,3,1]
 * Output: true
 * Example 2:
 *
 * Input: [1,2,3,4]
 * Output: false
 * Example 3:
 *
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 * */
package array.contains_duplicate_217;

import java.util.HashSet;
import java.util.Set;

public class Solution {
    /**
     * Runtime: 10 ms, faster than 19.86% of Java online submissions for Contains Duplicate.
     * Memory Usage: 44.3 MB, less than 37.18% of Java online submissions for Contains Duplicate.
     * */
    public boolean containsDuplicate(int[] nums) {
        if (nums == null) {
            return false;
        }
        final Set<Integer> set = new HashSet<>(nums.length);
        for (Integer num: nums) {
            if (set.contains(num)) {
                return true;
            }
            set.add(num);
        }
        return false;
    }

    public static void main(String[] args) {
        int[] nums = new int[] {1,2,3,1};
        Solution solution = new Solution();
        System.out.println(solution.containsDuplicate(nums));
    }
}
