// Given a string s, partition s such that every substring of the partition is a
// palindrome. Return all possible palindrome partitioning of s.
//
//
//  Example 1:
//  Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
//
//  Example 2:
//  Input: s = "a"
// Output: [["a"]]
//
//
//  Constraints:
//
//  1 <= s.length <= 16
//  s contains only lowercase English letters.
//
//
//  Related Topics 字符串 动态规划 回溯 👍 2045 👎 0

#include <string>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 时间复杂度:
     * 空间复杂度: O( N ^ 2)
     ***/
    std::vector<std::vector<std::string>> partition(std::string s) {
        int n = s.size();
        // 下面的实现不是很好懂,我换一个比较好懂得实现
        // std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, true));
        // for (int i = n - 1; i >= 0; --i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
        //     }
        // }
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        // 注意下面遍历的顺讯, 要先遍历 i, 再遍历 j, 也就是要先遍历 row, 再遍历
        // col, 也是因为递推公式: dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
        // dp[i][j] 依赖于左下方的dp[i+1][j-1]
        // 下面的实现中 (i + 1 >= j - 1) 表示只有 i+1 >= j-1 才有实际意义,要不然
        // dp[i+1][j-1] 没有实际的意义
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                if (i == j) {
                    dp[i][j] = true;
                } else {
                    // i + 1 > j - 1 这个条件,不能包括 i + 1 == j - 1
                    // 当 i + 1 ==  j - 1, 表示
                    dp[i][j] =
                        (s[i] == s[j]) && (i + 1 >= j - 1 || dp[i + 1][j - 1]);
                }
            }
        }
        // 下面的实现更有意义
        for (int j = 0; j < n; ++j) {
            // key point i <= j
            for (int i = 0; i < j; ++i) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (i + 1 == j) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    // i+1 <= j - 1 ----> i <= j - 2
                    // 其实 i + 1 == j 是 i+1 <= j-1 的特殊情况
                    dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
                }
            }
        }

        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> sub_strs;
        DFS(ans, dp, s, sub_strs, 0);
        return ans;
    }

   private:
    void DFS(std::vector<std::vector<std::string>>& ans,
             std::vector<std::vector<bool>>& dp, std::string& s,
             std::vector<std::string>& sub_strs, int start) {
        int n = s.size();
        if (start == n) {
            ans.push_back(sub_strs);
            return;
        }
        for (int j = start; j < n; ++j) {
            if (dp[start][j]) {
                sub_strs.push_back(s.substr(start, j - start + 1));
                DFS(ans, dp, s, sub_strs, j + 1);
                sub_strs.pop_back();
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
