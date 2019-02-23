/**
 * Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product
 *
 * of all the elements of nums except nums[i].
 *
 * Example:
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * Note: Please solve it without division and in O(n).
 *
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose
 *
 * of space complexity analysis.)
 *
 * */

package array.product_of_array_execpt_self_238;

public class Solution {
    /**
     * BF, 这个方法太粗暴了,需要优化
     * */
    public int[] productExceptSelfBF(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }
        int[] ans = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            ans[i] = 1;
            for (int j = 0; j < nums.length; j++) {
                if (i != j) {
                    ans[i] = ans[i] * nums[j];
                }
            }
        }
        return ans;
    }

    /**
     * 下面的这个奇丑无比的算法,主要是要处理很多的情况,处理完特殊情况之后, 就很快.
     *
     * congratulations:
     * Runtime: 1 ms, faster than 100.00% of Java online submissions for Product of Array Except Self.
     *
     * 不过: 题目中要求不能使用除法,所以还要想其他的办法
     * */
    public int[] productExceptSelfDivid(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }
        int product = 0;
        int[] ans = new int[nums.length];
        int count = 0;
        boolean zero = false;
        for (int item: nums) {
            if (item != 0) {
                if (product == 0) {
                    product = item;
                } else {
                    product *= item;
                }
            } else {
                count++;
                zero = true;
            }
        }
        if (count>1) {
            return ans;
        }
        for (int i = 0; i < nums.length; i++) {
            if (zero) {
                if (nums[i] == 0) {
                    ans[i] = product;
                }else {
                    ans[i] = 0;
                }
            } else {
                ans[i] = product / nums[i];
            }
        }
        return ans;
    }
    /**
     * 这个题目有启发意义, res[i]的值是左边所有数字的乘积乘以右边所有数字的乘积
     * */
    public int[] productExceptSelf(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        int n = nums.length;
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = 1;
        }
        int left = 1;
        for (int i = 0; i < n; i++) {
            res[i] = res[i] * left;
            left = left*nums[i];
        }
        int right = 1;
        for (int j = n-1; j >= 0; j--) {
            res[j] = res[j] * right;
            right = right * nums[j];
        }
        return res;
    }
}
