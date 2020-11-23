/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like
 *
 * (i.e., buy one and sell one share of the stock multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock
 *
 * before you buy again).
 *
 * Example 1:
 *
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 *              Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 * Example 2:
 *
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 *              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
 *              engaging multiple transactions at the same time. You must sell before buying again.
 * Example 3:
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 * */

package dynamic_programming.best_time_to_buy_and_sell_stock_122;

public class  Solution {
    /**
     * 如果采用暴力搜索法： 关键的是怎么搜索，这个是最重要的。
     *
     * 看了官网上的方法，有一种方法是Peak Valley Approach （峰谷法）
     *
     * 这个方法真的是巧妙， 这个方法和上一个121的题目是不同的。
     * 121的题目中有一条限制，只能卖一次，所以它的核心思想是找到数组中的最小值和最大值。且最小值一定要在最大值之前，有一个相对应的关系
     *
     * */
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        int peak = prices[0];
        int valley = prices[0];
        int max = 0;
        int i = 0;
        while (i < prices.length -1) {
            while (i < prices.length - 1 && prices[i] >= prices[i + 1]){
                i++;
            }
            valley = prices[i];
            while (i < prices.length - 1 && prices[i] <= prices[i + 1]){
                i++;
            }
            peak = prices[i];
            max += peak - valley;
        }
        return max;
    }

    /**
     * 思路： 将所有正的价格的差值直接加起来
     * */
    public int maxProfitFaster(int[] prices) {
        int sum = 0;
        for (int i = 1; i < prices.length; i++) {
            int diff = prices[i] - prices[i-1];
            if (diff > 0) {
                sum += diff;
            }
        }
        return sum;
    }
}












