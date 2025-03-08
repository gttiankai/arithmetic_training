// You are given an array prices where prices[i] is the price of a given stock
// on the iᵗʰ day.
//
//  You want to maximize your profit by choosing a single day to buy one stock
// and choosing a different day in the future to sell that stock.
//
//  Return the maximum profit you can achieve from this transaction. If you
// cannot achieve any profit, return 0.
//
//
//  Example 1:
//
//
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit =
// 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you
// must buy before you sell.
//
//
//  Example 2:
//
//
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
//
//
//
//  Constraints:
//
//
//  1 <= prices.length <= 10⁵
//  0 <= prices[i] <= 10⁴
//
//
//  Related Topics 数组 动态规划 👍 3726 👎 0
#include <iostream>

#include <ostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 时间复杂度 O(N!) 这个题目使用动态规划的方法去做的话是超时的
     *
     ***/
    int maxProfitSlow(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        std::vector<int> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            int max_profit = INT_MIN;
            for (int j = 0; j < i; j++) {
                // 这个地方是是可以优化的,不需要每次都从 0 计算到 i 的 max profit,只需要将 i 之前的
                // 最低的价格记载下来就可以了.
                max_profit = std::max(max_profit, prices[i] - prices[j]);
            }
            dp[i] = std::max(dp[i - 1], max_profit);
        }
        return dp[n - 1];
    }
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        std::vector<int> dp(n);
        dp[0] = 0;
        int max_profit = INT_MIN;
        int lowest_price = prices[0];
        for (int i = 1; i < n; ++i) {
            lowest_price = std::min(lowest_price, prices[i]);
            int profit = prices[i] - lowest_price;
            max_profit = std::max(max_profit, profit);
            dp[i] = std::max(dp[i - 1], max_profit);
        }
        return dp[n - 1];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    std::cout << solution.maxProfit(prices) << std::endl;
}
