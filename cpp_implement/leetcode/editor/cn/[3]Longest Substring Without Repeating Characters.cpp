// Given a string s, find the length of the longest substring without duplicate
// characters.
//
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
//
// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a
// substring.
//
//
//  Constraints:
//
//  0 <= s.length <= 5 * 10⁴
//  s consists of English letters, digits, symbols and spaces.
//
//
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 如何使用滑动窗口的方法来解决这个问题呢?
     *
     ***/
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) {
            return 0;
        }
        std::unordered_set<char> set;
        int longest_length = 0;
        for (int left = 0, right = 0 ; right < s.length(); right++) {
            char c = s[right];
            while (set.find(c) != set.end()) {
                // 这个题目比较关键的地方,并不是只是删除重复的那个元素,重复的元素左边的元素也都要删除
                set.erase(s[left]);
                left++;
            }
            set.insert(c);
            longest_length = std::max(longest_length, right - left + 1);
        }
        return longest_length;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::string> test_cases = {"aab", "abcabcbb", "bbbbb", "pwwkew"};
    for (auto& case_ : test_cases) {
        std::cout << case_ << " longest sub string length is: " << solution.lengthOfLongestSubstring(case_)
                  << std::endl;
    }
    return 0;
}
