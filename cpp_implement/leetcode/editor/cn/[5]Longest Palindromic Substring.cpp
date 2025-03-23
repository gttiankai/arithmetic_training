// Given a string s, return the longest palindromic substring in s.
//
//  Example 1:
//
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
//
//  Example 2:
// Input: s = "cbbd"
// Output: "bb"
//
//  Constraints:
//
//  1 <= s.length <= 1000
//  s consist of only digits and English letters.
//
//
//   Related Topics 双指针 字符串 动态规划 👍 7601 👎 0
#include <iostream>
#include <string>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::string longestPalindrome(std::string s) {
        int n = s.length();
        if (n == 1) {
            return s;
        }
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        int max_len = 1;
        int start   = 0;
        // 枚举子串的长度
        // 当子串的长度为 1 时,所有的子串都是回文的
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) dp[i][j] = true;
        };
        //  枚举子串的长度,
        for (int sub_str_len = 2; sub_str_len <= n; sub_str_len++) {
            for (int i = 0; i < n; ++i) {
                // i 是子串的起始位置
                // j 是子串的结束位置
                int j = sub_str_len + i - 1;
                //  循环结束位置
                if (j >= n) break;
                // 下面的代码有两种实现方式
                // dp[i][j] = ((s[i] == s[j]) && dp[i + 1][j - 1]);
                // 另外一种实现方式:
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    // 特殊处理 sub_str 的长度是 2 的情况, 在这种情况下 dp[i+1][j-1] 要求的是 dp 数组的下半区域
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    if (dp[i][j] && max_len < j - i + 1) {
                        max_len = j - i + 1;
                        start   = i;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    };
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char *argv[]) {
    Solution solution;
    std::vector<std::string> test_cases = {"cbbd", "babad"};
    for (auto test_case : test_cases) {
        std::cout << "\"" << test_case << "\" longest palindrome is: " << solution.longestPalindrome(test_case)
                  << std::endl;
    }
    return 0;
}
