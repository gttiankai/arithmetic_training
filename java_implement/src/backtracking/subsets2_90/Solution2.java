package backtracking.subsets2_90;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Solution2 {
    /**
     * Runtime: 31 ms, faster than 5.42% of Java online submissions for Subsets II.
     * Memory Usage: 37.3 MB, less than 97.53% of Java online submissions for Subsets II.
     *
     * 题目虽然简单,但是还是有一些地方值得去注意的的
     * */
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        if (nums == null || nums.length == 0) {
            return new ArrayList<>();
        }
        List<List<Integer>> ans = new ArrayList<>();
        /*
         * WARNING: 这个方案还有一个坑,就是nums 必须是排序的.
         *          如果不排序的话,会发现有很多很多顺序不同,但是里面的元素相同的数组.
         *          根据题目要求是要求的集合,所以所以顺序不能作为盘算的依据
         *
         * {1, 2, 3} 和 {3, 2, 1}是相同的.
         */

        Arrays.sort(nums);
        backTrack(ans, new ArrayList<>(), nums, 0);
        return ans;
    }


    private void backTrack(List<List<Integer>> ans, ArrayList<Integer> tmp, int[] nums, int index){
        if (isValid(ans, tmp)) {
            ans.add(new ArrayList<>(tmp));
        }
        for (int i = index; i < nums.length; i++) {
            tmp.add(nums[i]);
            backTrack(ans, tmp, nums, i+1);
            tmp.remove(tmp.size()-1);
        }
    }
    /**
     *
     * */
    private boolean isValid(List<List<Integer>> ans, List<Integer> list) {
        for (List<Integer> item : ans) {
            if (Arrays.equals(item.toArray(), list.toArray())) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] arguments) {
        int[] nums = new int[]{4,4,4,1,4};
        Solution2 solution = new Solution2();
        List<List<Integer>> ans = solution.subsetsWithDup(nums);
        System.out.println(ans);
    }
}
