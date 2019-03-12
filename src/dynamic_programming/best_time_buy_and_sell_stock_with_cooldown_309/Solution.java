/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions
 *
 * as you like (ie, buy one and sell one share of the stock multiple times) with the
 *
 * following restrictions:
 *
 * You may not engage in multiple transactions at the same time (ie, you must sell the
 * stock before you buy again).
 *
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * Example:
 *
 * Input: [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 *
 * */

package dynamic_programming.best_time_buy_and_sell_stock_309;

public class Solution {
    public int maxProfit(int[] prices) {
        if (null == prices || prices.length < 2) {
            return 0;
        }
        int n = prices.length;

        int[] hold = new int[n];
        int[] cooldown = new int[n];
        int[] sold = new int[n];
        hold[0] = Integer.MIN_VALUE;
        cooldown[0] = 0;
        sold[0] = 0;
        int max = 0;
        for (int i = 1; i < n; i++) {
            hold[i] = Math.max(hold[i-1], cooldown[i-1] - prices[i]);
            sold[i] = hold[i] + prices[i];
            cooldown[i] = Math.max(cooldown[i-1], sold[i-1]);

        }
        return Math.max(cooldown[n-1], sold[n-1]);
    }
    public static void main(String[] arguments) {
        Solution solution = new Solution();
        int[] prices = {1, 2, 3, 0, 2};
        System.out.printf("" + solution.maxProfit(prices));
    }
}
