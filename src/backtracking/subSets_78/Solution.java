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
 *
 * */

package backtracking.subSets_78;


import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static List<List<Integer>> subsets(int[] nums) {
        if (nums == null) {
            return null;
        }
        ArrayList<List<Integer>> result = new ArrayList<List<Integer>>();
        if (nums.length == 0) {
            return result;
        }
        int start = 0;
        List<Integer> tmpList = new ArrayList<>();
        backtrack(result, tmpList, nums, start);
        return result;
    }
    private static void backtrack(List<List<Integer>> list,List<Integer>  tempList, int[] nums, int start) {
        list.add(new ArrayList<>(tempList));
        for(int i = start; i < nums.length; i++){
            tempList.add(nums[i]);
            backtrack(list, tempList, nums, i + 1);
            tempList.remove(tempList.size() - 1);
        }
    }
    public static void main(String[] arguments) {
        int[] nums = {1, 2, 3, 4};
        System.out.printf("result: " + subsets(nums));
    }
}
