/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.cn/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (44.59%)
 * Likes:    3266
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.2M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 * Example 2:
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 * Constraints:
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters if it is non-empty.
 *
 */
#include <iostream>
#include <string>
#include <vector>

// @lc code=start
class Solution {
   public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string common_prefix = "";
        if (strs.empty()) {
            return common_prefix;
        }
        int m = strs[0].size();
        int n = strs.size();
        for (int i = 0; i < m; ++i) {
            common_prefix = strs[0].substr(0, i + 1);
            for (int j = 1; j < n; ++j) {
                if (common_prefix != strs[j].substr(0, i + 1)) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return common_prefix;
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    Solution solution;
    // special case: {"a"}
    std::vector<std::vector<std::string>> cases = {
        {"flower", "flower"},         {"car", "cir"},           {"a"}, {""}, {"", "test"},
        {"flower", "flow", "flight"}, {"dog", "racecar", "car"}};
    for (auto& item : cases) {
        std::cout << "[";
        for (auto& str : item) {
            std::cout << str << " ";
        }
        std::cout << "] longest common prefix:" << solution.longestCommonPrefix(item) << std::endl;
    }
}