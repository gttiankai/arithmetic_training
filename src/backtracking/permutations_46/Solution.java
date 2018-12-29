/**
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 *
 * */
package backtracking.permutations_46;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static List<List<Integer>> permute(int[] nums) {
        if ( null == nums || nums.length == 0) {
            return null;
        }
        ArrayList<List<Integer>> res = new ArrayList<>();
        backTrack(res, new ArrayList<>(), nums);
        return res;
    }
    public static void backTrack(List<List<Integer>> lists, List<Integer> tmpList, int[] nums) {
        if (tmpList.size() == nums.length) {
            lists.add(new ArrayList<>(tmpList));
            return;
        } else {
            for (int i = 0; i < nums.length; i++) {
                if (tmpList.contains(nums[i])) {
                    continue;
                }
                tmpList.add(nums[i]);
                backTrack(lists, tmpList, nums);
                tmpList.remove(tmpList.size() - 1);
            }
            return;
        }

    }
    public static void main(String[] arguments) {
        int[] list = new int[]{1, 2, 3};
        System.out.printf("the value: " + permute(list));
    }
}
