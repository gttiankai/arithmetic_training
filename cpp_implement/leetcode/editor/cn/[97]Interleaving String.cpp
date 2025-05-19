// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of
// s1 and s2.
//
//  An interleaving of two strings s and t is a configuration where s and t are
// divided into n and m substrings respectively, such that:
//
//
//  s = s1 + s2 + ... + sn
//  t = t1 + t2 + ... + tm
//  |n - m| <= 1
//  The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 +
// t3 + s3 + ...
//
//
//  Note: a + b is the concatenation of strings a and b.
//
//
//  Example 1:
//
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Explanation: One way to obtain s3 is:
// Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
// Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" =
//"aadbbcbcac".
// Since s3 can be obtained by interleaving s1 and s2, we return true.
//
//
//  Example 2:
//
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
// Explanation: Notice how it is impossible to interleave s2 with any other
// string to obtain s3.
//
//
//  Example 3:
//
//
// Input: s1 = "", s2 = "", s3 = ""
// Output: true
//
//
//
//  Constraints:
//
//
//  0 <= s1.length, s2.length <= 100
//  0 <= s3.length <= 200
//  s1, s2, and s3 consist of lowercase English letters.
//
//
//
//  Follow up: Could you solve it using only O(s2.length) additional memory
// space?
//
//  Related Topics 字符串 动态规划 👍 1112 👎 0
#include <iostream>
#include <string>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 下面的实现时错误的,没有理解清楚题意,这个就比较低级
     ***/
    bool isInterleaveWrong(std::string s1, std::string s2, std::string s3) {
        if (s1 == "") {
            return s2 == s3;
        }
        if (s2 == "") {
            return s1 == s3;
        }
        int m = s1.length();
        int n = s2.length();
        int k = s3.length();
        if (m + n != k) {
            return false;
        }
        int count = std::min(m, n);
        std::string s1s2;
        std::string s2s1;
        for (int i = 0; i < count; i++) {
            s1s2 += std::to_string(s1[i] + s2[i]);
            s2s1 += std::to_string(s2[i] + s1[i]);
        }
        if (count < m) {
            s1s2 += std::to_string(s1[m - 1]);
            s2s1 += std::to_string(s1[m - 1]);
        } else {
            s1s2 += std::to_string(s2[n - 1]);
            s2s1 += std::to_string(s2[n - 1]);
        }
        if (s3 == s1s2 || s3 == s2s1) {
            return true;
        } else {
            return false;
        }
    }
    bool isInterleaveComplex(std::string s1, std::string s2, std::string s3) {
        if (s1 == "") {
            return s2 == s3;
        }
        if (s2 == "") {
            return s1 == s3;
        }
        int m = s1.length();
        int n = s2.length();
        int k = s3.length();
        if (m + n != k) {
            return false;
        }
        auto dp = std::vector<std::vector<bool>>(
            m + 1, std::vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int p = i + j - 1;
                if (i > 0 && s1[i - 1] == s3[p]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j > 0 && s2[j - 1] == s3[p]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int m = s1.length();
        int n = s2.length();
        int k = s3.length();
        if (m + n != k) {
            return false;
        }
        // dp[j] 表示用 s1 的前 i 个字符和 s2 的前 j 个字符是否能交错组成 s3
        // 的前 i+j 个字符。
        auto dp = std::vector<bool>(n + 1, false);
        dp[0]   = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int p = i + j - 1;
                if (i > 0) {
                    dp[j] = dp[j] && (s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    dp[j] = dp[j] || (dp[j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return dp[n];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char *argv[]) {
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbcbcac";
    Solution solution;
    auto ans = solution.isInterleave(s1, s2, s3);
    std::cout << ans << std::endl;
    std::cout << solution.isInterleave(s1, s2, s3);
}
