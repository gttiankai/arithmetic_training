// Given two strings word1 and word2, return the minimum number of operations
// required to convert word1 to word2.
//
//  You have the following three operations permitted on a word:
//
//
//  Insert a character
//  Delete a character
//  Replace a character
//
//
//
//  Example 1:
//
//
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
//
//
//  Example 2:
//
//
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
//
//
//
//  Constraints:
//
//
//  0 <= word1.length, word2.length <= 500
//  word1 and word2 consist of lowercase English letters.
//
//
//   Related Topics 字符串 动态规划 👍 3670 👎 0

#include <algorithm>
#include <iostream>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    // 下面的实现是递归的实现,是从上往下的实现
    int minDistanceRecursiton(std::string word1, std::string word2) {
        int m = word1.length(), n = word2.length();
        if (m == 0 || n == 0) {
            return std::max(m, n);
        }
        if (word1[m - 1] == word2[n - 1]) {
            // 下面的代码不需要 + 1, 没有继续操作
            return minDistanceRecursiton(word1.substr(0, m - 1),
                                         word2.substr(0, n - 1));
        }
        int min_distance_for_add =
            minDistanceRecursiton(word1, word2.substr(0, n - 1)) + 1;
        int min_distance_for_del =
            minDistanceRecursiton(word1.substr(0, m - 1), word2) + 1;
        int min_distance_for_rep =
            minDistanceRecursiton(word1.substr(0, m - 1),
                                  word2.substr(0, n - 1)) +
            1;
        return std::min(std::min(min_distance_for_add, min_distance_for_del),
                        min_distance_for_rep);
    }

    int minDistanceRecurtion2(std::string word1, std::string word2) {
        int m = word1.length(), n = word2.length();
        // 递归结束的条件往往是比较重要的
        if (m == 0 || n == 0) {
            return std::max(m, n);
        }
        if (word1[0] == word2[0]) {
            return minDistanceRecurtion2(word1.substr(1, m),
                                         word2.substr(1, n));
        }
        int min_distance_for_add =
            minDistanceRecurtion2(word1, word2.substr(1, n)) + 1;
        int min_distance_for_del =
            minDistanceRecurtion2(word1.substr(1, m), word2) + 1;
        int min_distance_for_rep =
            minDistanceRecurtion2(word1.substr(1, m), word2.substr(1, n)) + 1;
        return std::min(std::min(min_distance_for_add, min_distance_for_del),
                        min_distance_for_rep);
    }

    int minDistance(std::string word1, std::string word2) {
        int m = word1.length(), n = word2.length();
        if (m == 0 || n == 0) {
            return std::max(m, n);
        }
        // dp[i][j] 为 word1[i] 和 word2[j] 的编辑距离
        int dp[m + 1][n + 1];
        // dp[i][0], 代表 word2 始终为空,
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        // dp[0][j], 代表 word1 始终为空
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        // 这里有个地方需要注意 word1 wrod2 的下标和 dp 下标的对应关系
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // key point
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] =
                        1 + std::min(std::min(dp[i - 1][j], dp[i][j - 1]),
                                     dp[i - 1][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char *argv[]) {
    std::vector<std::string> word1_test = {"horse", "intention"};
    std::vector<std::string> word2_test = {"ros", "execution"};
    Solution solution;
    for (int i = 0; i < word1_test.size(); ++i) {
        int min_distance = solution.minDistance(word1_test[i], word2_test[i]);
        std::cout << min_distance << std::endl;
    }
}
