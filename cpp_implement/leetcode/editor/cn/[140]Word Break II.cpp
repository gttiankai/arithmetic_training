// Given a string s and a dictionary of strings wordDict, add spaces in s to
// construct a sentence where each word is a valid dictionary word. Return all
// such possible sentences in any order.
//
//  Note that the same word in the dictionary may be reused multiple times in
// the segmentation.
//
//
//  Example 1:
//
//
// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
//
//
//  Example 2:
//
//
// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine",
//"pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.
//
//
//  Example 3:
//
//
// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []
//
//
//
//  Constraints:
//
//
//  1 <= s.length <= 20
//  1 <= wordDict.length <= 1000
//  1 <= wordDict[i].length <= 10
//  s and wordDict[i] consist of only lowercase English letters.
//  All the strings of wordDict are unique.
//  Input is generated in a way that the length of the answer doesn't exceed
//  10⁵.
//
//
//
//  Related Topics 字典树 记忆化搜索 数组 哈希表 字符串 动态规划 回溯 👍 790 👎
//  0
#include <string>
#include <unordered_set>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::string> wordBreak(std::string s,
                                       std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> word_set(wordDict.begin(),
                                                 wordDict.end());
        std::vector<std::string> ans;
        std::string sub_str;
        BackTracking(ans, word_set, s, sub_str, 0);
        return ans;
    }

   private:
    void BackTracking(std::vector<std::string>& ans,
                      std::unordered_set<std::string>& word_set,
                      std::string& str, std::string& sub_str, int start) {
        int n = str.length();
        if (start >= n) {
            ans.push_back(sub_str.substr(0, sub_str.length() - 1));
            return;
        }
        // 容易出错的点: i <= n ,其中 i 最大值是 n, 这个是因为 substr 的区间范围
        // 是前闭后开,所以 i 的值最大要为 n
        for (int i = start + 1; i <= n; i++) {
            std::string s = str.substr(start, i - start);
            if (word_set.find(s) != word_set.end()) {
                int sub_str_len = sub_str.length();
                sub_str += s + " ";
                BackTracking(ans, word_set, str, sub_str, i);
                sub_str = sub_str.substr(0, sub_str_len);
            }
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<std::string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    std::string str                   = "catsanddog";
    Solution solution;
    auto ans = solution.wordBreak(str, wordDict);
}
