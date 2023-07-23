/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.82%)
 * Likes:    1539
 * Dislikes: 0
 * Total Accepted:    485.1K
 * Total Submissions: 715.4K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams(字谜词) together. You can return
 * the answer in any order.
 *
 * An Anagram(字谜词) is a word or phrase formed by rearranging the letters of a
 * different word or phrase(短语), typically using all the original letters exactly
 * once.
 *
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 *
 * Constraints:
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 */

#include <iostream>
#include <string>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {}
};
// @lc code=end

int main(int argc, char* argv[]) {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution solution;
  auto ans = solution.groupAnagrams(strs);
  for (const auto& item : ans) {
    std::string message = "";
    for (const auto& str : item) {
      message += ", " + str;
    }
    std::cout << message << std::endl;
  }
  return 0;
}
