package backtracking.permutations_II_47;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    /**
     * Runtime: 3 ms, faster than 42.89% of Java online submissions for Permutations II.
     * Memory Usage: 37 MB, less than 99.80% of Java online submissions for Permutations II.
     *
     * 看到这个答案之后,说明还有可以优化的地方
     *
     * */
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return ans;
        }
        Arrays.sort(nums);
        boolean[] visited = new boolean[nums.length];
        backTrack(ans, new ArrayList<Integer>(), nums, 0, visited);
        return ans;
    }

    private void backTrack(List<List<Integer>> ans, List<Integer> tmpList, int[] nums, int index,boolean[] visited) {
        if (tmpList.size() == nums.length) {
            ans.add(new ArrayList<>(tmpList));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (visited[i] ){
                continue;
            }
            /**
             *
             * 这个判断条件是最重要的,因为有这个判断条件,就过滤了重复的内容.
             * */
            if (i > 0 && nums[i] == nums[i-1] && visited[i-1]) {
                continue;
            }
            tmpList.add(nums[i]);
            visited[i] = true;
            backTrack(ans, tmpList, nums, i+1, visited);
            tmpList.remove(tmpList.size()-1);
            visited[i] = false;
        }
    }
    public static void main(String[] argument) {
        int[] nums = {1, 1, 2};
        //int[] nums = {1, 2, 3};
        Solution solution = new Solution();
        System.out.println(solution.permuteUnique(nums));
    }
}
