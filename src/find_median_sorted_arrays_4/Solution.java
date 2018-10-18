/**
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
 * <p>
 * 请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
 * <p>
 * 你可以假设 nums1 和 nums2 不同时为空。
 * <p>
 * 示例 1:
 * <p>
 * nums1 = [1, 3]
 * nums2 = [2]
 * <p>
 * 中位数是 2.0
 * 示例 2:
 * <p>
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * <p>
 * 中位数是 (2 + 3)/2 = 2.5
 **/
package find_median_sorted_arrays_4;

public class Solution {
    /**
     * 该方案的时间复杂度是O（m + n），并没有达到O(log(m + n))
     * */
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // 1. 现将两个数组排序
        int arrayLength = nums1.length + nums2.length;
        int[] nums3 = new int[arrayLength];
        int p = 0, q = 0;
        int i = 0;
        while (p < nums1.length  && q < nums2.length) {
            if (nums1[p] <= nums2[q]) {
                nums3[i] = nums1[p];
                i++;
                p++;
            } else {
                nums3[i] = nums2[q];
                i++;
                q++;
            }
        }
        if (p < nums1.length) {
            System.arraycopy(nums1, p, nums3, i, nums1.length - p);
        }
        if (q < nums2.length) {
            System.arraycopy(nums2, q, nums3, i, nums2.length - q);
        }
        // 2. 求中位数
        double median = 0;
        if (arrayLength % 2 == 0) {
            median = ((double) nums3[arrayLength / 2] + (double) nums3[arrayLength / 2 - 1]) / 2;
        } else {
            median = (double) nums3[arrayLength / 2];
        }
        return median;
    }

    public static void main(String[] arguments) {
        int[] sum1 = {1, 2};
        int[] sum2 = {3, 4};
        System.out.println("the Median value: " + findMedianSortedArrays(sum1, sum2));
    }
}
