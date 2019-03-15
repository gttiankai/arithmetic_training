/**
 *
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most k transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock
 *
 * before you buy again).
 *
 * Example 1:
 *
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
 * Example 2:
 *
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
 *              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 * */

package dynamic_programming.best_time_to_buy_and_sell_stock_188;

public class Solution {

    public int maxProfit(int k, int[] prices) {
        if (k == 0 || null == prices || prices.length <2) {
            return 0;
        }
        int n = prices.length;
        if (k >= n / 2) {
            return peakAndVally(prices);
        }

        int[][] local = new int[n][k+1];
        int[][] global = new int[n][k+1];

        for (int i = 1; i < prices.length; i++) {
            int diff = prices[i] - prices[i-1];

            for (int j = 1; j < k+1; j++) {
                // 这个local的递归方程一直没有想清楚。在到道理上没有想清楚。
                local[i][j] = Math.max(
                        global[i-1][j-1] + Math.max(diff, 0),
                        local[i-1][j] + diff);

                global[i][j] = Math.max(global[i-1][j], local[i][j]);
            }
        }
        return global[n -1][k];
    }

    private int peakAndVally(int[] prices) {

        int peak = prices[0];
        int vally = prices[0];
        int i = 0;
        int max = 0;
        while (i < prices.length-1) {
            while ((i < prices.length-1) &&(prices[i] >= prices[i+1])) {
                i++;
            }
            vally = prices[i];
            while ( i < prices.length-1 && prices[i] <= prices[i+1]) {
                i++;
            }
            peak = prices[i];
            max += peak - vally;
        }
        return max;
    }
}
