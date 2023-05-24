/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.cn/problems/decode-ways/description/
 *
 * algorithms
 * Medium (33.10%)
 * Likes:    1384
 * Dislikes: 0
 * Total Accepted:    269.9K
 * Total Submissions: 815.4K
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z can be encoded into numbers using the
 * following mapping:
 *
 *
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 *
 *
 * To decode an encoded message, all the digits must be grouped then mapped
 * back into letters using the reverse of the mapping above (there may be
 * multiple ways). For example, "11106" can be mapped into:
 *
 *
 * "AAJF" with the grouping (1 1 10 6)
 * "KJF" with the grouping (11 10 6)
 *
 *
 * Note that the grouping (1 11 06) is invalid because "06" cannot be mapped
 * into 'F' since "6" is different from "06".
 *
 * Given a string s containing only digits, return the number of ways to decode
 * it.
 *
 * The test cases are generated so that the answer fits in a 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "12"
 * Output: 2
 * Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: s = "226"
 * Output: 3
 * Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 *
 *
 * Example 3:
 *
 *
 * Input: s = "06"
 * Output: 0
 * Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>

// @lc code=start
/**
 * 这个题目很好,
 *  1. dynamic programing
 *     dp(0) = 0
 *      IsValid(s[i]) ?
 *          YES: dp(i) += dp(i-1)
 *          NO:  dp(i) += 0
 *      IsValid(s[i-1],s[i]) ?
 *          YES: dp(i) += dp(i-2);
 *          NO:  dp(i) += 0
 * */
class Solution {
 public:
  int numDecodings(std::string s) {
    if (s.empty()) {
      return 0;
    }
    int N = s.length();
    std::vector<int> dp(N, 0);
    dp[0] = IsValid(s[0]) ? 1 : 0;
    if (dp[0] == 0) {
      return 0;
    }
    if (N > 1) {
      if (IsValid(s[1])) {
        dp[1] += 1;
      }
      if (IsValid(s.substr(0, 2))) {
        dp[1] += 1;
      }
    }
    for (int i = 2; i < N; ++i) {
      if (IsValid(s[i])) {
        dp[i] += dp[i - 1];
      }
      if (IsValid(s.substr(i - 1, 2))) {
        dp[i] += dp[i - 2];
      }
      if (dp[i] == 0) {
        return 0;
      }
    }
    return dp[N - 1];
  }

 private:
  bool IsValid(char c) {
    return ('1' <= c && c <= '9');
  }
  bool IsValid(std::string sub_str) {
    if (sub_str.size() != 2 || sub_str[0] == '0') {
      return false;
    }
    int num = atoi(sub_str.c_str());
    return (10 <= num && num <= 26);
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<std::string> message = {"226", "06",
                                      "0522"
                                      "200",
                                      "2012", "201"};
  for (const auto& item : message) {
    std::cout << item << " num decode :" << solution.numDecodings(item) << std::endl;
  }
  return 0;
}
