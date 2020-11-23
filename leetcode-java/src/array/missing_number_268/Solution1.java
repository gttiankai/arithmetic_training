package array.missing_number_268;

public class Solution1 {

    public int missingNumber(int[] nums) {
        /**
         * Runtime: 0 ms, faster than 100.00% of Java online submissions for Missing Number.
         * Memory Usage: 39 MB, less than 69.48% of Java online submissions for Missing Number.
         * 这个位操作真的很精髓,学到了一种非常好的算法.
         * */
        int missing = nums.length;
        for (int i = 0; i < nums.length; i++) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
}
