/**
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * <p>
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * <p>
 * If the target is not found in the array, return [-1, -1].
 * <p>
 * Example 1:
 * <p>
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * <p>
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 */

package find_first_and_last_position_34;

public class Solution {
    public static int[] searchRange(int[] nums, int target) {
        if (null == nums || nums.length == 0) {
            return new int[]{-1, -1};
        }
        return binarySearch(nums, target, 0, nums.length - 1);
    }

    // 核心思想还是采用二分查找
    public static int[] binarySearch(int[] nums, int target, int left, int right) {
        // 二分查找时的条件,千万不要忘记
        if (left > right) {
            return new int[]{-1, -1};
        }
        int mid = (left + right) / 2;

        int firstPosition = -1, lastPosition = -1;

        if (nums[mid] == target) {
            // i j 以及firstPosition lastPosition 是为了进行位置的记录
            int i = mid;
            int j = mid;
            while (i > -1) {
                if (nums[i] == target) {
                    firstPosition = i;
                    i--;
                } else {
                    // 最后调整位置
                    break;
                }
            }
            while (j < nums.length) {
                if (nums[j] == target) {
                    lastPosition = j;
                    j++;
                } else {
                    break;
                }
            }
        } else if (target < nums[mid]) {
            return binarySearch(nums, target, left, mid - 1);
        } else {
            return binarySearch(nums, target, mid + 1, right);
        }
        return new int[]{firstPosition, lastPosition};
    }

    public static void main(String[] arguments) {
//        int[] nums = {5,7,7,8,8,10};
//        int target = 6;

        int[] nums = {1};
        int target = 1;

        int[] result =searchRange(nums, target);
        System.out.printf("the value:" + result[0] + " " +result[1]);
    }
}
