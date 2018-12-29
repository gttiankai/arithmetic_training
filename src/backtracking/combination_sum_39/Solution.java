/**
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of times.
 *
 * Note:
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * Example 1:
 *
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 *   [7],
 *   [2,2,3]
 * ]
 * Example 2:
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 *   [2,2,2,2],
 *   [2,3,3],
 *   [3,5]
 *
 * */

package backtracking.combination_sum_39;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {

    /*
    * 解决的思路如下:
    *   1. 首先找到所有的组合
    *   2. 然后在这些组合中查看是否能够组成target值
    *
    *   这种方式会造成很大的性能问题,因为当candidates数组比较大时,会很慢,并且需要很大的内存空间
    * */
    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(candidates);
        ArrayList<Integer> tempList = new ArrayList<>();
        backTrack(list, tempList, candidates, target, 0);
        return list;
    }
    public static void backTrack(List<List<Integer>> list, ArrayList<Integer> tempList,
                          int[] candidates, int target, int start) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            // TODO: 研究清楚Java的值传递
            // 这两种方式有什么不同, 是因为Java中的值传递的原因吗?
            // 确实是这个原因,这是因为后面还要对tempList进行操作,操作的时候会对tempList中的内容进行处理
            list.add(new ArrayList<>(tempList));
            //list.add(tempList);
        } else {
            for (int i = start; i < candidates.length; i++) {
                tempList.add(candidates[i]);
                backTrack(list, tempList, candidates, target-candidates[i], i);// not i + 1 because we can reuse same elements
                // 删除元素是从index开始索引的
                tempList.remove(tempList.size()-1);
            }
        }
        return;
    }
    public static void main(String[] arguments) {
        int[] candidates = {2, 3, 6, 7};
        System.out.printf("the value: " + combinationSum(candidates, 7));
    }
}
