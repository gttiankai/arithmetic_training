/**
 * Given a collection of integers that might contain duplicates, nums,
 *
 * return all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 * Input: [1,2,2]
 * Output:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 *
 *
 *
 *
 * */
package backtracking.subsets2_90;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

public class Solution {
    /**
     * Unit test:
     * [[],[1],[2],[3],[1,2],[2,3],[1,2,3]]
     * [[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]
     *  no pass
     *
     *  和上次一样除了同样的问题,使用窗口法,会导致某些情况不能拿到
     *
     * */
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        if (nums == null || nums.length == 0) {
            return new LinkedList<>();
        }
        List<List<Integer>> ans = new LinkedList<>();
        ans.add(new ArrayList<>());
        for (int window = 1; window <= nums.length; window++){
            for (int i = 0; i + window <= nums.length; i++) {
                int[] tmp = Arrays.copyOfRange(nums, i, i+window);
                List<Integer> tmpList = new ArrayList<Integer>(Arrays.stream(tmp)
                        .boxed()
                        .collect(Collectors.toList()));
                if (isValid(ans, tmpList)){
                    ans.add(tmpList);
                }
            }
        }
        return ans;
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
        int[] nums = new int[]{1, 2, 2};
        Solution solution = new Solution();
        List<List<Integer>> ans = solution.subsetsWithDup(nums);
        System.out.println("Hello Leetcode!");
    }
}
