// Given an array of strings strs, group the anagrams together. You can return
// the answer in any order.
//
//
//  Example 1:
//
//
//  Input: strs = ["eat","tea","tan","ate","nat","bat"]
//
//
//  Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//
//  Explanation:
//
//
//  There is no string in strs that can be rearranged to form "bat".
//  The strings "nat" and "tan" are anagrams as they can be rearranged to form
// each other.
//  The strings "ate", "eat", and "tea" are anagrams as they can be rearranged
// to form each other.
//
//
//  Example 2:
//
//
//  Input: strs = [""]
//
//
//  Output: [[""]]
//
//  Example 3:
//
//
//  Input: strs = ["a"]
//
//
//  Output: [["a"]]
//
//
//  Constraints:
//
//
//  1 <= strs.length <= 10⁴
//  0 <= strs[i].length <= 100
//  strs[i] consists of lowercase English letters.
//
//
//  Related Topics 数组 哈希表 字符串 排序 👍 2254 👎 0
#include <string>
#include <unordered_map>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     *  时间复杂度: O(m*nlogn), m 为 strs 中字符串的个数, n 为所有字符串中的最大
     *  长度,
     ***/
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hash_map;
        std::vector<std::vector<std::string>> ans;
        for (auto& str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end());
            hash_map[key].push_back(str);
        }
        for (auto& item : hash_map) {
            ans.push_back(item.second);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
