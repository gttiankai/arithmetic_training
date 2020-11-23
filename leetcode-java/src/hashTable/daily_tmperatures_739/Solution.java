/**
 * Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many
 *
 * days you would have to wait until a warmer temperature. If there is no future day for which this is possible,
 *
 * put 0 instead.
 *
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be
 *
 * [1, 1, 4, 2, 1, 1, 0, 0].
 *
 * Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in
 *
 * the range [30, 100].
 *
 * */

package hashTable.daily_tmperatures_739;

public class Solution {
    /**
     * Runtime: 225 ms, faster than 10.63% of Java online submissions for Daily Temperatures.
     *
     * 使用最简单的 BF 方式,也能通过.
     *
     * */
    public int[] dailyTemperatures(int[] T) {
        if (T == null || T.length == 0) {
            return new int[]{0};
        }
        int n = T.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = calculateDays(T, i);
        }
        return ans;
    }
    private int calculateDays(int[] T, int start){
        int days = 0;
        for (int i = start+1; i < T.length; i++) {
            if (T[start] < T[i]) {
                days++;
                return days;
            } else {
                days++;
            }
        }
        return 0;
    }
}
