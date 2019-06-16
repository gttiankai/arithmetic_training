package array.contains_duplicate_217;

import java.util.Arrays;

public class Solution1 {
    /**
     * Runtime: 5 ms, faster than 91.78% of Java online submissions for Contains Duplicate.
     * Memory Usage: 42.2 MB, less than 68.77% of Java online submissions for Contains Duplicate.
     *
     * 这个目前是最快的算法了。
     * */
    public boolean containsDuplicate(int[] nums) {

        Arrays.sort(nums);
        for (int i =1; i < nums.length; i++) {
            if (nums[i-1] == nums[i]) {
                return true;
            }
        }
        return false;
    }
}
