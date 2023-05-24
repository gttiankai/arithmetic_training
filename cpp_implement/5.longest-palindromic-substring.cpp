/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.56%)
 * Likes:    6516
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.8M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
// @lc code=start
/**
 * dp(i): 以 i 为结尾的回文子串的长度
 * 假设: dp(i-1) = k
 *      if s[i-k-1] == s[k]
 *          YES: dp(i) = dp(i-1) + 2;
 *          NO:  dp(i) = 1
 * 返回值: max{dp[i], 0 <= i <= N}
 *
 * */
class Solution {
 public:
  std::string longestPalindrome(std::string s) {
    int N = s.size();
    std::vector<int> dp(N);
    dp[0] = 1;
    int max_len = dp[0];
    for (int i = 1; i < N; ++i) {

    }
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  return 0;
}
