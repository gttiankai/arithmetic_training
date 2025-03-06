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
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        std::vector<int> dp(n);
        dp[0] = 0;
        for (int i = 1; i < n; ++i) {
            int max_profit = INT_MIN;
            for (int j = 0; j < i; j++) {
                max_profit = std::max(max_profit, prices[i] - prices[j]);
            }
            dp[i] = std::max(dp[i - 1], max_profit);
        }
        return dp[n - 1];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<int> prices = {7,1,5,3,6,4};
    std::cout << solution.maxProfit(prices) << std::endl;
}
