package array.subarray_sum_equals_k_560;

import java.util.Arrays;

public class Solution1 {
    /**
     * 果然不出所料:使用 BF 方案直接 Time Limit Exceeded
     *
     * 时间复杂度 O(n^3)
     *
     * */

    public int subarraySum(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int count = 0;
        for (int window = 1; window <= nums.length; window++) {
            for (int i = 0; i + window <= nums.length; i++) {
                int[] tmp = Arrays.copyOfRange(nums, i, i + window);
                if (equal(tmp, k)) {
                    count++;
                }
            }
        }
        return count;
    }

    private boolean equal(int[] nums, int target) {
        int sum = 0;
        for (Integer item : nums) {
            sum += item;
        }
        return sum == target;
    }
    public static void main(String[] arguments) {
        int[] nums = new int[]{1, 1, 1};
        int k = 2;
        Solution1 solution1 = new Solution1();
        System.out.println(solution1.subarraySum(nums, k));
    }
}
