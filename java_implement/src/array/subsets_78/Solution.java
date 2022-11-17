/**
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 * */

package array.subsets_78;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Solution {
    // 滑动窗口的解法失败了，因为没有考虑到 不相邻元素的组合的情况。
    public List<List<Integer>> subsetsFailed(int[] nums) {
        List ans = new ArrayList();
        if (nums == null || nums.length == 0) {
            return ans;
        }
        int n = nums.length;
        // add empty list
        ans.add(new ArrayList<>());
        Set<List> set = new HashSet<>();
        for (int window = 1; window <= n; window++) {
            for (int i = 0; i <= n - window; i++) {
                List tmp = new ArrayList();
                for (int j = i; j < i+ window; j++){
                    tmp.add(nums[j]);
                }
                set.add(tmp);
            }
        }
        for (List item:set ) {
            ans.add(item);
        }
        return ans;
    }
    /**
     * 还是对回溯的算法掌握的不够，感觉还是有问题
     * */
    public List<List<Integer>> subsets(int[] nums) {
        List ans = new ArrayList();
        if (nums == null || nums.length == 0) {
            return ans;
        }
        backtrack(ans, new ArrayList<>(), nums, 0);
        return ans;
    }

    //TODO: 复习backtrack算法
    private void backtrack(List<List<Integer>> ans, List<Integer> tmpList, int[] nums, int start) {
        ans.add(new ArrayList<>(tmpList));
        for (int i = start; i < nums.length; i++) {
            tmpList.add(nums[i]);
            backtrack(ans, tmpList, nums, i+1);
            //去掉刚刚进去的一个
            tmpList.remove(tmpList.size() -1);
        }
        return;
    }


    public static void main(String[] argument) {
        int[] nums = new int[]{1, 2, 3};
        Solution solution = new Solution();
        solution.subsets(nums);
    }
}
