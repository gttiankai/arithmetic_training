package array.find_median_sorted_arrays_4;

public class Solution1 {

    /**
     * O(m + n)
     * */
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int m = nums1.length;
        int n = nums2.length;
        int len = m + n;
        int pre = -1;
        int cur = -1;
        int aStart = 0;
        int bStart = 0;
        for (int i = 0; i <= (len / 2); i++) {

            pre = cur;
            /**
             * 这个判断条件,没有一定的功力是写不出来的
             * */
            if (aStart < m && (bStart >= n || nums1[aStart] < nums2[bStart])) {
                cur = nums1[aStart++];
            } else {
                cur = nums2[bStart++];
            }

        }
        if ((len & 1) == 0) {
            return (pre + cur) / 2.0;
        } else {
            return cur;
        }
    }
}
