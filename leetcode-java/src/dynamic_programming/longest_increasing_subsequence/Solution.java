package dynamic_programming.longest_increasing_subsequence;

public class Solution {
    /**
     * 5 3 4 1 2 3 4 1 4
     * 这个算法是有问题,只能处理连续的最长非降序子序列.
     * 但是子序列的的定义没有要求一定连续.
     * 例如: [10,9,2,5,3,7,101,18] 输出结果是:4
     *
     * */
    public static int longestNumber(int[] nums) {
        if (nums == null) {
            return 0;
        }
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        int[] map = new int[len + 1];

        map[0] = 0;
        map[1] = 1;
        for (int i = 2; i < len ; i++) {
            if (nums[i-1] <= nums[i]) {
                map[i] = map[i-1] + 1;
            } else {
                // 这个代码的问题是这个位置
                // 对子序列的理解不深入
                map[i] = 1;
            }
        }
        int result = 0;
        for (int i = 0;i < len +1; i++) {
            if (result < map[i]){
                result = map[i];
            }
        }
        return result;
    }
    public static int longestNumberDp(int[] nums) {
        int len = nums.length;
        if (len == 0) {
            return 0;
        }
        int[] map = new int[len];
        if (nums == null) {
            return 0;
        }
        int result = 0;
        for (int i = 0; i < len; i++){
            map[i] = 1;
            for (int j = 0; j < i; j++) {
                if ( nums[j] <  nums[i] && map[i] < map[j] + 1) {
                    map[i] = map[j] + 1;
                }
            }
            if (result < map[i]) {
                result = map[i];
            }
        }
        return result;
    }

    public static void main(String[] arguments) {
        int[] nums = {5, 3, 0, 1, 2, 3, 4, 1, 4};
        int[] nums1= {2,2};
        System.out.println(longestNumberDp(nums1));
    }
}
