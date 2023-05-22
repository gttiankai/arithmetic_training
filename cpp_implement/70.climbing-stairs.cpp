/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <iostream>
// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    if (n < 3) {
      return n;
    }
    std::vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < n + 1; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  int n = 7;
  Solution solution;
  std::cout << solution.climbStairs(n) << std::endl;
  return 0;
}
