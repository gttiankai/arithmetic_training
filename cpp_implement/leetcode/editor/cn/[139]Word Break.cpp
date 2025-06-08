// Given a string s and a dictionary of strings wordDict, return true if s can
// be segmented into a space-separated sequence of one or more dictionary words.
//
//  Note that the same word in the dictionary may be reused multiple times in
// the segmentation.
//
//
//  Example 1:
//
//
// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
//
//
//  Example 2:
//
//
// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple
// pen apple".
// Note that you are allowed to reuse a dictionary word.
//
//
//  Example 3:
//
//
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
//
//
//
//  Constraints:
//
//
//  1 <= s.length <= 300
//  1 <= wordDict.length <= 1000
//  1 <= wordDict[i].length <= 20
//  s and wordDict[i] consist of only lowercase English letters.
//  All the strings of wordDict are unique.
//
//
//  Related Topics 字典树 记忆化搜索 数组 哈希表 字符串 动态规划 👍 2772 👎 0

#include <string>
#include <unordered_set>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    bool wordBreakHard(std::string s, std::vector<std::string>& wordDict) {
        int max_len = 0;
        for (auto& word : wordDict) {
            max_len = std::max(max_len, (int)word.size());
        }
        std::unordered_set<std::string> word_set(wordDict.begin(),
                                                 wordDict.end());
        int n = s.size();
        std::vector<int> dp(n + 1, -1);
        return DFS(s, word_set, dp, max_len, n);
    }

   private:
    bool DFS(std::string& s, std::unordered_set<std::string>& word_set,
             std::vector<int>& dp, int& max_len, int i) {
        if (i == 0) {
            return true;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        for (int j = i - 1; j >= std::max(0, i - max_len); j--) {
            if (word_set.count(s.substr(j, i - j)) &&
                DFS(s, word_set, dp, max_len, j)) {
                dp[i] = true;
                return dp[i];
            }
        }
        dp[i] = false;
        return dp[i];
    }

   public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int max_len = 0;
        for (auto& word : wordDict) {
            max_len = std::max(max_len, (int)word.size());
        }
        std::unordered_set<std::string> word_set(wordDict.begin(),
                                                 wordDict.end());
        int n = s.size();
        /**
         * dp[i], 代表子字符串 [0, i-1] 是否能够由 wordDict 中的单词组成
         * dp[0] = true, 是起始状态
         * dp[i] 那么如何求 dp[i]的状态呢?
         *  假设 j 位于[0, i-1] 中间的某个位置, dp[i] = dp[j] && (s[j, i-1])
         *是否在 wordDict 中,接下来只需要遍历 j 的 位置,如果找到了 j 的位置,那么
         *dp[i] 的值 设置为 true, 如果遍历完成之后, dp[j] && s[j, i-1] 始终为
         *false, 那么 dp[i] 的值始终为 false;
         ***/
        std::vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            /***
             * 下面的判断存在一个可以优化的点, wordDict
             * 中的子串是由最大长度的限制的, 如果 j ~ i-1 的长度超过了 wordDict
             * 中子串的最大长度,那么[j, i-1] 就不可能 在 wordDict 字典中
             */
            for (int j = 0; j < i; j++) {
                if (i - j > max_len) {
                    continue;
                }
                if (dp[j] && word_set.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// leetcode submit region end(Prohibit modification and deletion)
