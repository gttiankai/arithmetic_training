/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock
 *
 * before you buy again).
 *
 * Example 1:
 *
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 *              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
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
 * 在上一个题目的基础上又增加了限制：最多只能进行两次交易
 *
 * */

package dynamic_programming.best_time_to_bug_and_sell_stock_123;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class Solution {

    /**
     * 无法处理一种情况， {1,2,4,2,5,7,2,4,9,0}
     * 按照下面的解法，结果是： (7-2) + (9 - 2) = 12
     * 但是真正的解是： (7 - 1) + (9 - 2) = 13
     *
     * 所以我认为下面从峰谷法的算法已经失败了，还要找其他解法。
     * 这个题目有意思的是同一类型的题目求解起来有很多方式。
     *
     * */
    public int maxProfitFailed(int[] prices) {
        if (null == prices || prices.length == 0) {
            return 0;
        }
        int valley = prices[0];
        int peak = prices[0];
        int max = 0;
        int i = 0;
        int n = prices.length;
        Queue<Integer> queue = new PriorityQueue<Integer>(
                new Comparator<Integer>() {
                    @Override
                    public int compare(Integer o1, Integer o2) {
                        return o2 - o1;
                    }
                }
        );
        while (i < n-1) {
            while ( i < n-1 && prices[i] >= prices[i +1]) {
                i++;
            }
            valley = prices[i];
            while (i < n-1 && prices[i] <= prices[i+1]) {
                i++;
            }
            peak = prices[i];
            int square = peak -  valley;
            queue.add(square);
        }
        if (queue.size() == 0) {
            return 0;
        } if (queue.size() == 1) {
            return queue.poll();
        } else {
            return queue.poll() + queue.poll();
        }
    }
    public static void main(String[] arguments) {
        int[] prices = {1,2,4,2,5,7,2,4,9,0};
        Solution solution = new Solution();
        System.out.printf("" + solution.maxProfit(prices));
    }
}
