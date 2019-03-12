/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock),
 design an algorithm to find the maximum profit.

 Note that you cannot sell a stock before you buy one.

 Example 1:

 Input: [7,1,5,3,6,4]
 Output: 5
 Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 Not 7-1 = 6, as selling price needs to be larger than buying price.
 Example 2:

 Input: [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transaction is done, i.e. max prof
 * */
package dynamic_programming.best_time_to_buy_and_sell_stock_121;

public class Solution {
    public static int maxProfit(int[] prices) {
        if(prices == null) {
            return 0;
        }
        int len = prices.length;
        if (len < 2) {
            return 0;
        }
        int result = 0;
        int[] map = new int[len];
        for (int i = 1; i < len; i++) {
            map[i] = 0;
            for (int j = 0; j < i; j ++) {
                int tmp = prices[i] - prices[j];
                if ( tmp > 0 && map[i] < tmp){
                    map[i] = tmp;
                }
            }
            if (result < map[i]) {
                result = map[i];
            }
        }
        return result;
    }

    public static int maxProfitOnePass(int[] prices) {
        if(prices == null) {
            return 0;
        }
        int len = prices.length;
        if (len < 2) {
            return 0;
        }
        int result = 0;
        int min = prices[0];
        for (int i = 1; i < len; i++) {
            if (min > prices[i]) {
                min = prices[i];
            }
            int tmp = prices[i] - min;
            if (result < tmp) {
                result = tmp;
            }
        }
        return result;
    }
    public static void main(String[] arguments) {
        int[] nums = {7,1,5,3,6,4};
        System.out.printf("the values: " + maxProfitOnePass(nums));
    }
}
