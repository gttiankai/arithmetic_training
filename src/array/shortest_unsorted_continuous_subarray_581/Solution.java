/**
 * Given an integer array, you need to find one continuous subarray that if you only sort this subarray
 *
 * in ascending order, then the whole array will be sorted in ascending order, too.
 *
 * You need to find the shortest such subarray and output its length.
 *
 * Example 1:
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
 * Note:
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means <=.
 *
 * unit test: {1, 3, 2, 2, 2}
 * unit test: {1, 2, 5, 3, 4}
 * */

package array.shortest_unsorted_continuous_subarray_581;

import java.util.Arrays;

public class Solution {
    /**
     * two pointer 的方式是不对的, 不能完成这个任务
     *
     * */
    public int findUnsortedSubarrayFailed(int[] nums) {
        if (nums == null || nums.length == 1) {
            return 0;
        }
        int i = 0;
        int j = nums.length-1;
        boolean left = true;
        boolean right = true;
        while (i < j) {
            if (left) {
                if (nums[i] > nums[i+1]) {
                    left = false;
                } else {
                    i++;
                }
            }
            if (nums[i] > nums[j]) {
                break;
            }
            if (right) {
                if (nums[j-1] > nums[j]) {
                    right = false;
                } else {
                    j--;
                }
            }
            if (nums[i] > nums[j]) {
                break;
            }
            if (!left && !right) {
                break;
            }
        }
        if (i == j) {
            return 0;
        } else {
            return (j - i + 1);
        }
    }

    /**
     * 根据提示可以知道可以通过排序的方式进行解决
     * TODO: 是不是大部分的 array 的题目都可以通过排序的方式进行解决?
     * */
    public int findUnsortedSubarray(int[] nums) {
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);
        int i = 0;
        int j = nums.length-1;
        boolean left = true;
        boolean right = true;

        /*
        * 这一部分是根据我的逻辑进行编写的
        * */
        while (i < j) {
            if (left) {
                if (nums[i] != sortedNums[i]) {
                    left = false;
                } else {
                    i++;
                }
            }
            if (right) {
                if (nums[j] != sortedNums[j]) {
                    right = false;
                } else {
                    j--;
                }
            }

            if (!left && !right) {
                break;
            }
        }
        if (i == j) {
            return 0;
        } else {
            return (j - i + 1);
        }

    }


    public int findUnsortedSubarray2(int[] nums) {
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);
        int start = sortedNums.length, end = 0;
        for (int i = 0; i < nums.length; i++) {
            // 这个循环比较巧妙解决了我上面的代码过多的问题
            // 每个元素都会参与循环,但是是通过比较最大值和最小值的方式的
            if (sortedNums[i] != nums[i]) {
                start = Math.min(start, i);
                end = Math.max(end, i);
            }
        }
        return end - start >= 0? end - start +1:0;

    }

    public int findUnsortedSubarrayStack(int[] nums) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        boolean flag = false;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i-1] > nums[i]) {
                flag = true;
            }
            if (flag) {
                min = Math.min(min, nums[i]);
            }
        }
        flag = false;
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                flag = true;
            }
            if (flag){
                max = Math.max(max, nums[i]);
            }
        }
        int l, r;
        for (l = 0; l < nums.length; l++) {
            if (min < nums[l]) {
                break;
            }
        }
        for (r = nums.length - 1; r >= 0; r--) {
            if (max > nums[r]) {
                break;
            }
        }
        return r - l < 0 ? 0 : r - l + 1;
    }




    public static void main(String[] arguments) {
        Solution solution = new Solution();
        int[] nums = {1, 2, 5, 3, 4};
        System.out.printf(""+solution.findUnsortedSubarrayStack(nums));
    }
}
