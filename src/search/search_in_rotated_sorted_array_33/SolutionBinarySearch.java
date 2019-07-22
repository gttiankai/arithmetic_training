public class SolutionBinarySearch {

    /*
      Runtime: 0 ms, faster than 100.00% of Java online submissions for Search in Rotated Sorted Array.
      Memory Usage: 40.7 MB, less than 5.17% of Java online submissions for
      Search in Rotated Sorted Array.
      解题思路: 使用优化过的二分查找方式将数组遍历的时间复杂度从 O(n) 降低到
      O(log(n)) 的纬度,满足题目的要求
     */
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        int n = nums.length;
        int left = 0;
        int right = n -1;
        return binarySearchOpt(nums, left, right, target);

    }

    private int binarySearchOpt(int[] nums, int left, int right, int target) {
        // XXX: left < right ---> left <= right
        while(left <= right) {
            int median = (left + right) / 2;
            if (nums[median] == target) {
                return median;
            }
            // XXX: nums[left] < nums[median]  ---> nums[left] <= nums[median]
            if (nums[left] <= nums[median]) {
                // 左边有序
                if ( target < nums[left] || target > nums[median]) {
                    left = median+1;
                } else {
                    right = median -1;
                }
                // XXX: nums[median] < nums[right] ---> nums[median] <= nums[right]
            } else if (nums[median] <= nums[right]) {
                // 右边有序
                if ( target < nums[median] || target > nums[right]) {
                    right = median -1;
                } else {
                    left = median + 1;
                }
            }
        }
        return -1;
    }


}
