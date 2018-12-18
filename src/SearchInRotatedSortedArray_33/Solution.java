/**
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * <p>
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * <p>
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * <p>
 * You may assume no duplicate exists in the array.
 * <p>
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * <p>
 * Example 1:
 * <p>
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * <p>
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 */
package SearchInRotatedSortedArray_33;

public class Solution {
    public static int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        return binarySearch(nums, target, 0, nums.length - 1);
    }

    /*
    * 参考的文章:    https://blog.csdn.net/linhuanmars/article/details/20525681
    * 有一个很重要的点就是
    * */
    public static int binarySearch(int[] nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        // nums[mid] not equals target
        if (nums[mid] <= nums[right]) {
            // mid ~ right 有序
            if (target > nums[mid] && target <= nums[right]) {
                return binarySearch(nums, target, mid + 1, right);
            } else {
                return binarySearch(nums, target, left, mid - 1);
            }
            // 通过分析发现,如果nums[mid] < nums[right], 则nums[left] < nums[mid]一定成立
        } else if (nums[left] <= nums[mid]) {
            // left ~ right 有序
            if (nums[left] <= target && target < nums[mid]) {
                return binarySearch(nums, target, left, mid - 1);
            } else {
                return binarySearch(nums, target, mid + 1, right);
            }
        }
        return -1;
    }

    public static void main(String[] arguments) {
//        int[] array = {4, 5, 6, 7, 0, 1, 2};
//        int target = 0;
        int[] array = {3, 1};
        int target = 1;
        System.out.printf("the value:" + search(array, target));
    }
}
