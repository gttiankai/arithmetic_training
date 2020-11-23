package backtracking.subsets2_90;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Solution1 {

    /**
     * 这次还是参考了别人的解法, 自己的解法是怎么样的?
     * */
    public List<List<Integer>> subsetsWithDup(int[] nums) {

        if (nums == null || nums.length == 0) {
            return new ArrayList<>();
        }
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        backTrack(ans, new ArrayList<>(), nums, 0);

        return ans;
    }


    private void backTrack(List<List<Integer>> ans, ArrayList<Integer> tmp, int[] nums, int index){
        ans.add(new ArrayList<>(tmp));
        for (int i = index; i < nums.length; i++) {
            if (i > index && nums[i] == nums[i-1]) {
                continue;
            }
            tmp.add(nums[i]);
            backTrack(ans, tmp, nums, i+1);
            tmp.remove(tmp.size()-1);
        }


    }

    private boolean isValid(List<List<Integer>> ans, List<Integer> list) {
        for (List<Integer> item : ans) {
            if (Arrays.equals(item.toArray(), list.toArray())) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] arguments) {
        int[] nums = new int[]{1, 2, 3};
        Solution1 solution = new Solution1();
        List<List<Integer>> ans = solution.subsetsWithDup(nums);
        System.out.println("Hello Leetcode!");
    }
}
