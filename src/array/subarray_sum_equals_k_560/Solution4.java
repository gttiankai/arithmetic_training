package array.subarray_sum_equals_k_560;

import java.util.HashMap;

public class Solution4 {
    public static void main(String[] arguments) {
        int[] nums = new int[]{1, 1, 1};
        int k = 2;
        Solution4 solution = new Solution4();
        System.out.println(solution.subarraySum(nums, k));
    }

    /**
     * 这个方法返回值永远是 0,
     * */
    private int subarraySum(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int count = 0;
        int sum = 0;
        int n = nums.length;
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        // (0, 1): 知道是 sum - k = 0 的情况,也就是说 sum = k的情况
        hashMap.put(0, 1);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            /* ? 为啥是 sum -k
             * 一开始我写的是 k - sum, 结果就一直不对
             * 这个是因为 sum 是从左到右一直加上来的.
             */
            int adjust = k - sum ;
            if (hashMap.containsKey(adjust)) {
                count += hashMap.get(adjust);
            }
            hashMap.put(sum, hashMap.getOrDefault(sum, 0) + 1);

        }
        return count;
    }
}
