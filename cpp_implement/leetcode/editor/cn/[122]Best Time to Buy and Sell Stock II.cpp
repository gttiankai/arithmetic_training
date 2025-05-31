// You are given an integer array prices where prices[i] is the price of a given
// stock on the iᵗʰ day.
//
//  On each day, you may decide to buy and/or sell the stock. You can only hold
// at most one share of the stock at any time. However, you can buy it then
// immediately sell it on the same day.
//
//  Find and return the maximum profit you can achieve.
//
//
//  Example 1:
//
//
// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
// 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3
// = 3.
//
// Total profit is 4 + 3 = 7.
//
//
//  Example 2:
//
//
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
// 5-1 = 4.
// Total profit is 4.
//
//
//  Example 3:
//
//
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the
// stock to achieve the maximum profit of 0.
//
//
//
//  Constraints:
//
//
//  1 <= prices.length <= 3 * 10⁴
//  0 <= prices[i] <= 10⁴
//
//
//  Related Topics 贪心 数组 动态规划 👍 2739 👎 0

#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 下面的算法是模拟所有的交易情况,这个算法是错误的
     ***/
    int maxProfitWrong(std::vector<int>& prices) {
        if (prices.size() == 1 || prices.empty()) return 0;
        int n = prices.size();
        // std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        int dp[n][n];
        // dp[i][j] 代表第 i 天买, 第 j 天卖
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                dp[i][j] = std::max(0, prices[j] - prices[i]);
            }
        }
        return 0;
    }
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        // dp[i][0] 表示第 i 天交易完后手里没有股票的最大利润，
        // dp[i][1] 表示第 i 天交易完后手里有股票的最大利润
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
// leetcode submit region end(Prohibit modification and deletion)
