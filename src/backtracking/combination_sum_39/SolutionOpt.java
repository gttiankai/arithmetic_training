package backtracking.combination_sum_39;

import java.util.List;
import java.util.Arrays;
import java.util.LinkedList;

public class SolutionOpt {

    /*
      Runtime: 3 ms, faster than 78.18% of Java online submissions for Combination Sum.
      Memory Usage: 36.6 MB, less than 99.89% of Java online submissions for
      Combination Sum.
      比几个月之前,已经好很多了,实际上这个方法已经比上次写的方法优化了
     */
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        // 第一步先排序
        Arrays.sort(candidates);
        List ans = new LinkedList<List<Integer>>();
        backtrack(ans, new LinkedList<Integer>(), candidates, 0, target);
        return ans;
    }

    private void backtrack(List<List<Integer>> ans, List<Integer> tmpList, int[] candidates, int index,int target) {

        if (target == 0) {
            ans.add(new LinkedList(tmpList));
        }
        for (int i = index; i < candidates.length; i++) {
            if (target - candidates[i] >= 0) {
                tmpList.add(candidates[i]);
                backtrack(ans, tmpList, candidates, i, target - candidates[i]);
                tmpList.remove(tmpList.size()-1);
            } else {
                // 能够优化的地方: 提高了 +10ms
                // 因为已经排序过了, 当前的值大于 target 之后,后面的元素就不要在
                // 继续了判断了
                return ;
            }
        }
    }
}
