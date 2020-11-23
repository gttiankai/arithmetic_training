/**
 *  假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 *
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 *
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 *
 * 你可以假设数组中不存在重复的元素。
 *
 * 你的算法时间复杂度必须是 O(log n) 级别。
 *
 * 示例 1:
 *
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 示例 2:
 *
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 *
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 *
 *
 * */
package search.search_in_rotated_sorted_array_33;

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
