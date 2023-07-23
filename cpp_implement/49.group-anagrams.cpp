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
#include <map>
#include <string>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::map<std::string, std::vector<std::string>> unorder_map;
    for (const auto& item : strs) {
      std::string key = item;
      std::sort(key.begin(), key.end());
      // 使用排序后的字符作为 key 是比较好的思路
      unorder_map[key].push_back(item);
    }
    std::vector<std::vector<std::string>> ans;
    for (const auto& item : unorder_map) {
      ans.push_back(item.second);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution solution;
  auto ans = solution.groupAnagrams(strs);
  for (const auto& item : ans) {
    std::string message = "";
    for (const auto& str : item) {
      message += str + ", ";
    }
    std::cout << message << std::endl;
  }
  return 0;
}
