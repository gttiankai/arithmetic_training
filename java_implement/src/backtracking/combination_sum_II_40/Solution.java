/**
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note:
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * Example 1:
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 * Example 2:
 *
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 *   [1,2,2],
 *   [5]
 * ]
 *
 * */

package backtracking.combination_sum_II_40;

import java.util.*;

public class Solution {
    /**
     * Runtime: 8 ms, faster than 44.46% of Java online submissions for Combination Sum II.
     * Memory Usage: 36.9 MB, less than 99.61% of Java online submissions for Combination Sum II.
     *
     *
     * */
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        if (candidates == null || candidates.length == 0) {
            return ans;
        }
        Arrays.sort(candidates);
        backTrack(ans, new ArrayList<>(), candidates, candidates.length-1, target);
        return ans;
//        // TODO: 集合
//        Set<List<Integer>> set = new HashSet<>();
//        for (List<Integer> list: ans) {
//            if (!set.contains(list)) {
//                set.add(list);
//            }
//
//        }
//        List<List<Integer>> result  = new ArrayList<>();
//        for (List<Integer> list: set) {
//            result.add(list);
//        }
//        return result;
    }
    private void backTrack(List<List<Integer>> ans, List<Integer> tmpList, int[] candidates, int index, int target){
        if (target < 0) {
            return;
        }
        if (target == 0) {
            ans.add(new ArrayList<>(tmpList));
            return;
        }
        for (int i = index; i >=0 ; i--) {
            /**
             * 这个不能用,如果有重复的元素的话,就会产生问题.
             * 例如:
             *      {10,1,2,7,6,1,5} target = 8.
             *      解: {1, 1, 6}这个解就会忽略
             *
             * */
//            if (i> 0 && candidates[i] == candidates[i-1]){
//                continue;
//            }


            /**
             * 要用下面的算法
             * */
            if ( i < index && candidates[i] == candidates[i+1]) {
                continue;
            }
            if (target >= candidates[i]) {
                tmpList.add(candidates[i]);
                backTrack(ans, tmpList, candidates, i-1, target-candidates[i]);
                tmpList.remove(tmpList.size()-1);
            }
        }
    }
    public static void main(String[] arguments) {
        int[] candidates = {10,1, 1,2,7,6,1,5};
        int target = 8;
        Solution solution = new Solution();
        List<List<Integer>> ans = solution.combinationSum2(candidates, target);
        System.out.println(ans);
    }
}
