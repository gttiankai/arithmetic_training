// You are given a string s and an array of strings words. All the strings of
// words are of the same length.
//
//  A concatenated string is a string that exactly contains all the strings of
// any permutation of words concatenated.
//
//
//  For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef",
//"cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not
// a concatenated string because it is not the concatenation of any permutation of
// words.
//
//
//  Return an array of the starting indices of all the concatenated substrings
// in s. You can return the answer in any order.
//
//
//  Example 1:
//
//
//  Input: s = "barfoothefoobarman", words = ["foo","bar"]
//
//
//  Output: [0,9]
//
//  Explanation:
//
//  The substring starting at 0 is "barfoo". It is the concatenation of ["bar",
//"foo"] which is a permutation of words. The substring starting at 9 is "foobar".
// It is the concatenation of ["foo","bar"] which is a permutation of words.
//
//  Example 2:
//
//  Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//
//  Output: []
//
//  Explanation:
//
//  There is no concatenated substring.
//
//  Example 3:
//
//
//  Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//
//
//  Output: [6,9,12]
//
//  Explanation:
//
//  The substring starting at 6 is "foobarthe". It is the concatenation of [
//"foo","bar","the"]. The substring starting at 9 is "barthefoo". It is the
// concatenation of ["bar","the","foo"]. The substring starting at 12 is "thefoobar". It is
// the concatenation of ["the","foo","bar"].
//
//
//  Constraints:
//
//
//  1 <= s.length <= 10⁴
//  1 <= words.length <= 5000
//  1 <= words[i].length <= 30
//  s and words[i] consist of lowercase English letters.
//
//
//  Related Topics 哈希表 字符串 滑动窗口 👍 1209 👎 0
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<int> findSubstringWrong(std::string s, std::vector<std::string>& words) {
        std::vector<int> ans;
        int m = s.size();
        int n = words.size();
        int k = words[0].size();
        if (m < n * k) {
            return ans;
        }
        // 使用 words 构建所有的串联子串, 这个构建所有的字符串有点问题,应该怎么构建呢?
        std::vector<std::string> concated_string_array;
        for (int i = 0; i < words.size(); i++) {
            std::string concated_string = words[i];
            for (int j = 0; j < words.size(); j++) {
                if (i != j) {
                    concated_string += words[j];
                }
            }
            concated_string_array.push_back(concated_string);
        }
        // 遍历字符串 s , 找到所有的串联子串的位置,
        for (std::string& concated_string : concated_string_array) {
            if (s.find(concated_string) != std::string::npos) {
                ans.push_back(s.find(concated_string));
            }
        }
        return ans;
    }
    /***
        下面的方案是我自己实现的,但是性能比较差,直接超时了,需要修改下面的代码,进行提速
     **/
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        int m = s.size();
        int n = words.size();
        int k = words[0].size();
        if (m < n * k) {
            return std::vector<int>();
        }
        /**
          针对 s 进行滑动窗口, 找到所有的子串,看这些子串是否是串联子串
         **/
        int window = n * k;
        std::vector<std::string> sub_string_array;
        for (int i = 0; i <= m - window; i++) {
            sub_string_array.push_back(s.substr(i, window));
        }
        // 构建包含所有 word 的 hash_map 以便于后面的判断串联子串
        std::unordered_map<std::string, int> words_map;
        for (auto word : words) {
            words_map[word]++;
        }
        std::unordered_set<int> ans_set;
        for (auto& sub_string : sub_string_array) {
            if (IsConcatedSubString(words_map, k, sub_string)) {
                int pos = 0;
                while(s.find(sub_string, pos) != std::string::npos) {
                    pos = s.find(sub_string, pos);
                    // 为什么要用 set 是因为串联子串在 s 中可能有多个多处,这个做
                    // 的目的是为了出去重复
                    ans_set.insert(pos);
                    pos++;
                }
            }
        }
        return std::vector<int>(ans_set.begin(), ans_set.end());
    }
   private:
    bool IsConcatedSubString(std::unordered_map<std::string, int> words_map, int k, std::string sub_str) {
        for (int i = 0; i < sub_str.size(); i += k) {
            std::string word = sub_str.substr(i, k);
            if (words_map.find(word) == words_map.end()) {
                return false;
            }
            words_map[word]--;
            if (words_map[word] == 0) {
                words_map.erase(words_map.find(word));
            }
        }
        if (words_map.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<std::string> case_for_s                  = {"barfoothefoobarman", "wordgoodgoodgoodbestword",
                                                            "barfoofoobarthefoobarman", "foobarfoobar"};
    std::vector<std::vector<std::string>> case_for_words = {
        {"bar", "foo"}, {"word", "good", "best", "good"}, {"bar", "foo", "the"}, {"foo", "bar"}};
    Solution solution;
    for (int i = 0; i < case_for_s.size(); i++) {
        std::vector<int> ans = solution.findSubstring(case_for_s[i], case_for_words[i]);
        for (auto n : ans) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
