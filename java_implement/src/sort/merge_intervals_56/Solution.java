/**
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * Example 1:
 *
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * Example 2:
 *
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * NOTE: input types have been changed on April 15, 2019. Please reset to default code
 * definition to get new method signature.
 *
 * */
package sort.merge_intervals_56;

import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;

import java.util.*;

public class Solution {
    /**
    * Runtime: 5 ms, faster than 94.38% of Java online submissions for Merge Intervals.
    * Memory Usage: 42.4 MB, less than 55.34% of Java online submissions for Merge Intervals.
    *
    * */
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0 || intervals[0].length == 0) {
            return intervals;
        }
        List<int[]> ans = new ArrayList<int[]>();

        Comparator<int[]> com = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        };
        Arrays.sort(intervals, com);
        ans.add(intervals[0]);
        int j = 1;
        for (int i = 1; i < intervals.length;i++) {
            // FOCUS: 下面这行代码,也需要注意
            int[] pre = ans.get(j-1);
            int[] cur = intervals[i];
            if (pre[1] < cur[0]) {
                ans.add(cur);
                j++;
            } else {
                //FOCUS: 这个地方也是一个坑
                //pre[1] = cur[1];
                pre[1] = pre[1] > cur[1]? pre[1]:cur[1];
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }

    public static void main(String[] args) {
        int[][] intervals = {{1, 4},{0, 2}, {3, 5}};
        Solution solution = new Solution();
        int[][] ans = solution.merge(intervals);
        for (int[] item : ans) {
            System.out.println("[" + item[0] + "," + item[1] + "]");
        }
    }
}
