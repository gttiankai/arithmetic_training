package array.find_median_sorted_arrays_4;

public class Solution2 {

    /**
     * 使用 find k min element
     *
     * 这个方案, 我感觉挺好的, 能够满足题目中的时间复杂度O(log(m+n)), 并且能够又在能够理解的范围内
     *
     * */
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int m = nums1.length;
        int n = nums2.length;
        int left = ( m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        /*
        * 学到一个技巧:
        * 就是 left 和 right
        *
        * */
        int leftValue = getKth(nums1, 0, nums2, 0, left);
        int rightValue = getKth(nums1, 0, nums2, 0, right);
        return (leftValue + rightValue) / 2;


    }

    private int getKth(int[] nums1, int start1, int[] nums2, int start2, int key) {
        int len1 = nums1.length - start1;
        int len2 = nums2.length - start2;

        /*
         *
         * */
        if (len1 > len2) return getKth(nums2, start2, nums1, start1, key);

        if (len1 == 0) return nums2[start2 + key -1];

        if (key == 1) return Math.min(nums1[start1], nums2[start2]);

        /*
        * 为了解决,当 k/2 大于 某个数组的长度,然后出现数组越界的问题
        * 表达式中的-1, 是为了直接转化为数组的 index
        * */
        int i = start1 + Math.min(len1, key/2) -1;
        int j = start2 + Math.min(len2, key/2) -1;

        if (nums1[i] < nums2[j]) {
            return getKth(nums1, i+1, nums2, start2, key/2);
        }else {
            return getKth(nums1, i, nums2, j+1, key/2);
        }
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2};
        int[] nums2 = {3, 4};
        Solution2 solution = new Solution2();
        System.out.println(solution.findMedianSortedArrays(nums1, nums2));
    }
}
