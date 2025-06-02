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
        int dp[n][n];
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (i == j) {
                    dp[i][j] = true;
                } else {
                    // 为什么 (i + 1 > j -1) 的条件应该如何设置?
                    dp[i][j] =
                        (s[i] == s[j]) && (i + 1 > j - 1 || dp[i + 1][j - 1]);
                }
            }
        }
        if (dp[0][n - 1] == true) return 0;
        std::vector<int> f(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            if (dp[0][i] == true) {
                f[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (dp[j + 1][i] == true) {
                        f[i] = std::min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[n - 1];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::string s = "ababababababababababababcbabababababababababababa";
    std::cout << solution.minCut(s);
}
