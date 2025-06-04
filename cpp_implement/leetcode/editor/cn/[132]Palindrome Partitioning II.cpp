// Given a string s, partition s such that every substring of the partition is a
// palindrome.
//
//  Return the minimum cuts needed for a palindrome partitioning of s.
//
//
//  Example 1:
//
//
// Input: s = "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1
// cut.
//
//
//  Example 2:
//
//
// Input: s = "a"
// Output: 0
//
//
//  Example 3:
//
//
// Input: s = "ab"
// Output: 1
//
//
//
//  Constraints:
//
//
//  1 <= s.length <= 2000
//  s consists of lowercase English letters only.
//
//
//  Related Topics 字符串 动态规划 👍 826 👎 0
#include <iostream>
#include <string>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int minCut(std::string s) {
        if (s.empty() || s.length() == 1) return 0;
        int n = s.length();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        // dp[i][j] 表示子串 s[i..j] 是否为回文
        // 下面这个不好理解
        // for (int j = 0; j < n; ++j) {
        //     for (int i = 0; i <= j; ++i) {
        //         if (i == j) {
        //             dp[i][j] = true;
        //         } else {
        //             // 为什么 (i + 1 > j -1) 的条件应该如何设置?
        //             dp[i][j] =
        //                 (s[i] == s[j]) && (i + 1 > j - 1 || dp[i + 1][j -
        //                 1]);
        //         }
        //     }
        // }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (i + 1 == j) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
            }
        }
        if (dp[0][n - 1] == true) {
            return 0;
        }
        // f[i] 表示子串 s[0..i] 的最小切割次数
        std::vector<int> f(n, 0);
        for (int i = 0; i < n; ++i) {
            // 最坏情况,每个字符切一次
            f[i] = i;
            if (dp[0][i]) {
                // s[0 ~ i] 回文, 不需要再切割了
                f[i] = 0;
            } else {
                // 从[0, i] 中间,找一个
                for (int j = 0; j < i; ++j) {
                    if (dp[j + 1][i] == true) {
                        f[i] = std::min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[n - 1];
    };
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    // std::string s = "ababababababababababababcbabababababababababababa";
    std::string s = "aab";
    std::cout << solution.minCut(s);
}
