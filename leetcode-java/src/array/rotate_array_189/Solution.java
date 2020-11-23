/**
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 *
 * Example 1:
 *
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * Example 2:
 *
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation:
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * Note:
 *
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 *
 * */

package array.rotate_array_189;

public class Solution {

    /**
     * 第一种解法：
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Rotate Array.
     * Memory Usage: 37.3 MB, less than 66.32% of Java online submissions for Rotate Array.
     * */
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        int[] tmp = new int[nums.length];
        // 下面的判断很重要，因为这个题目，在编写代码的时候，少考虑了一种情况，
        // 当k > n的时候，如何处理
        if ( k > n) {
            k = (k % n);
        }
        System.arraycopy(nums, n-k ,tmp , 0, k);
        System.arraycopy(nums, 0, tmp, k, n-k);
        System.arraycopy(tmp, 0, nums, 0, n);
    }

    /**
     * 第二种解法：
     * 使用一个笨办法试一试
     * 我们真的去写循环语句，去进行翻转，这个方案的优点是空间复杂度是 O(1),达到了题目的要求
     * Runtime: 84 ms, faster than 18.08% of Java online submissions for Rotate Array.
     * Memory Usage: 37 MB, less than 66.44% of Java online submissions for Rotate Array.
     * */
    public void rotate1(int[] nums, int k) {
        int n = nums.length;
        int[] tmp = new int[nums.length];
        // 下面的判断很重要，因为这个题目，在编写代码的时候，少考虑了一种情况，
        // 当k > n的时候，如何处理
        if ( k > n) {
            k = (k % n);
        }
        for (int i = 0; i < k; i++) {
            int guard = nums[n-1];
            for (int j = n-1; j > 0; j--) {
                nums[j] = nums[j-1];
            }
            nums[0] = guard;
        }
    }
    /**
     * 第三种解法：（参考答案）
     * Runtime: 0 ms, faster than 100.00% of Java online submissions for Rotate Array.
     * Memory Usage: 37.5 MB, less than 66.25% of Java online submissions for Rotate Array.
     *
     * 
     * */
    public void rotate2(int[] nums, int k) {
      if(nums == null || nums.length < 2) {
          return;
      }
      int n = nums.length;
      k = k % n;
      reverse(nums, 0, n -k - 1);
      reverse(nums, n - k, n - 1);
      reverse(nums, 0, n -1);
    }

    private void reverse(int[] nums, int i, int j) {
        int tmp = 0;
        while(i < j) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
    }
}
