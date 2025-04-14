/**
Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.

 A mapping of digits to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.


 Example 1:


Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]


 Example 2:


Input: digits = ""
Output: []


 Example 3:


Input: digits = "2"
Output: ["a","b","c"]



 Constraints:


 0 <= digits.length <= 4
 digits[i] is a digit in the range ['2', '9'].


 Related Topics 哈希表 字符串 回溯 👍 3048 👎 0

*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> ans;
        if (digits.empty()) {
            return ans;
        }
        std::unordered_map<char, std::string> letter_map;
        letter_map['2'] = "abc";
        letter_map['3'] = "def";
        letter_map['4'] = "ghi";
        letter_map['5'] = "jkl";
        letter_map['6'] = "mno";
        letter_map['7'] = "pqrs";
        letter_map['8'] = "tuv";
        letter_map['9'] = "wxyz";
        // 这个 queue 是比较好的数据结构
        std::queue<std::string> letter_queue;
        for (int i = 0; i < digits.length(); i++) {
            std::string letteres = letter_map[digits[i]];
            int n                = letter_queue.size();
            if (letter_queue.empty()) {
                for (int j = 0; j < letteres.size(); j++) {
                    letter_queue.push(letteres.substr(j, 1));
                }
            } else {
                for (int j = 0; j < n; j++) {
                    // 对 queue 的操作需要注意
                    std::string prefix = letter_queue.front();
                    letter_queue.pop();
                    for (int k = 0; k < letteres.size(); k++) {
                        letter_queue.push(prefix + letteres.substr(k, 1));
                    }
                }
            }
        }
        int n = letter_queue.size();
        for (int i = 0; i < n; i++) {
            ans.push_back(letter_queue.front());
            letter_queue.pop();
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char *argv[]) {
    Solution solution;
    std::vector<std::string> digits = {"23", "2", ""};
    for (auto digit : digits) {
        std::vector<std::string> ans = solution.letterCombinations(digit);
        for (auto s : ans) {
            std::cout << s << std::endl;
        }
    }
}
