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

    public int findUnsortedSubarray(int[] nums) {
        return 0;
    }
    public static void main(String[] arguments) {
        Solution solution = new Solution();
        int[] nums = {1, 2, 5, 3, 4};
        System.out.printf(""+solution.findUnsortedSubarray(nums));
    }
}
