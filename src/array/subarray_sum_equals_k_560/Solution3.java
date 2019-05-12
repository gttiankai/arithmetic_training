package array.subarray_sum_equals_k_560;

public class Solution3 {
    /**
     * 在第二题的基础上优化空间复杂度
     *
     * */
    public int subarraySum(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int count = 0;
        int n = nums.length;
        for (int start = 0; start < n; start++) {
            int sum = 0;
            for (int end = start; end < n; end++) {
                sum = sum + nums[end];
                if ( sum == k) {
                    count++;
                }
            }

        }
        return count;
    }
    public static void main(String[] arguments) {
        int[] nums = new int[]{1, 1, 1};
        int k = 2;
        Solution3 solution = new Solution3();
        System.out.println(solution.subarraySum(nums, k));
    }
}
