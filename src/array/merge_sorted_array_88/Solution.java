/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 * Note:
 *
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
 *
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold
 *
 * additional elements from nums2.
 *
 * Example:
 *
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 *
 * Output: [1,2,2,3,5,6]
 * */
package array.merge_sorted_array_88;

import java.io.OutputStream;

import com.sun.org.apache.xml.internal.serializer.ElemDesc;

public class Solution {
    /**
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Merge Sorted Array.
     * Memory Usage: 36.3 MB, less than 99.97% of Java online submissions for Merge Sorted Array.
     * @param nums1
     * @param m
     * @param nums2
     * @param n
     */
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] ans = new int[m+n];
        int p1 = 0;
        int p2 = 0;

        for (int i = 0; i < m+n; i++) {
            if (p1 < m && p2 < n) {
                if (nums1[p1] <= nums2[p2]) {
                    ans[i] = nums1[p1];
                    p1++;
                } else {
                    ans[i] = nums2[p2];
                    p2++;
                }
            } else if (p1 < m) {
                ans[i] = nums1[p1];
                p1++;
            } else if (p2 < n) {
                ans[i] = nums2[p2];
                p2++;
            }
        }
        System.arraycopy(ans, 0, nums1, 0, m+n);
    }
    public static void main(String[] args) {
        /**
         * nums1 = [1,2,3,0,0,0], m = 3
         * nums2 = [2,5,6],       n = 3
         */
        int[] nums1 = new int[]{1,2,3,0,0,0};
        int[] nums2 = new int[]{2, 5, 6};
        int m = 3;
        int n = 3;
        Solution solution = new Solution();
        solution.merge(nums1, m, nums2, n);
        for (Integer var : nums1) {
            System.out.println(var);
        }
    }
}
