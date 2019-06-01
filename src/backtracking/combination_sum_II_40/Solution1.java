package backtracking.combination_sum_II_40;

import java.util.*;

public class Solution1 {
    /**
     *  Runtime: 2 ms, faster than 99.95% of Java online submissions for Combination Sum II.
     *  从后往前比从前往后快
     * */
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        if (candidates == null || candidates.length == 0) {
            return ans;
        }
        Arrays.sort(candidates);
        backTrack(ans, new ArrayList<>(), candidates, 0, target);
        return ans;
    }
    private void backTrack(List<List<Integer>> ans, List<Integer> tmpList, int[] candidates, int index, int target){
        if (target < 0) {
            return;
        }
        if (target == 0) {
            ans.add(new ArrayList<>(tmpList));
            return;
        }
        for (int i = index; i < candidates.length ; i++) {
            /*
            * 这个代码是我写的,但是还是没有太搞清楚是因为什么?
            * */
            if ( i > index && candidates[i] == candidates[i-1]) {
                continue;
            }
            if (target >= candidates[i]) {
                tmpList.add(candidates[i]);
                backTrack(ans, tmpList, candidates, i+1, target-candidates[i]);
                tmpList.remove(tmpList.size()-1);
            }
        }
    }
    public static void main(String[] arguments) {
        int[] candidates = {10,1,1,2,7,6,1,5};
        int target = 8;
        Solution1 solution = new Solution1();
        List<List<Integer>> ans = solution.combinationSum2(candidates, target);
        System.out.println(ans);
    }
}
