// Given an input string s, reverse the order of the words.
//
//  A word is defined as a sequence of non-space characters. The words in s will
// be separated by at least one space.
//
//  Return a string of the words in reverse order concatenated by a single
//  space.
//
//
//  Note that s may contain leading or trailing spaces or multiple spaces
// between two words. The returned string should only have a single space
// separating the words. Do not include any extra spaces.
//
//
//  Example 1:
//
//
// Input: s = "the sky is blue"
// Output: "blue is sky the"
//
//
//  Example 2:
//
//
// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing
// spaces.
//
//
//  Example 3:
//
//
// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single
// space in the reversed string.
//
//
//
//  Constraints:
//
//
//  1 <= s.length <= 10⁴
//  s contains English letters (upper-case and lower-case), digits, and spaces '
//'.
//  There is at least one word in s.
//
//
//
//  Follow-up: If the string data type is mutable in your language, can you
// solve it in-place with O(1) extra space?
//
//  Related Topics 双指针 字符串 👍 1314 👎 0
#include <iostream>
#include <string>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    // 时间复杂度: O(N)
    // 空间复杂度: O(N)
    std::string reverseWordsOn(std::string s) {
        // 删除头部空格
        s.erase(0, s.find_first_not_of(' '));
        // 删除尾部空格
        s.erase(s.find_last_not_of(' ') + 1);
        std::vector<std::string> ans;
        while (!s.empty()) {
            std::string sub_str = s.substr(0, s.find_first_of(' '));
            ans.push_back(sub_str);
            s.erase(0, s.find_first_of(' '));
            s.erase(0, s.find_first_not_of(' '));
        }
        int size = ans.size();
        std::string reverse_str;
        for (int i = size - 1; i > 0; i--) {
            reverse_str += ans[i] + " ";
        }
        return reverse_str + ans[0];
    }
    std::string reverseWords(std::string s) {
        // 删除头部空格
        s.erase(0, s.find_first_not_of(' '));
        // 删除尾部空格
        s.erase(s.find_last_not_of(' ') + 1);
        std::reverse(s.begin(), s.end());
        int size  = s.size();
        int index = 0;
        for (int start = 0; start < size; start++) {
            if (s[start] != ' ') {
                if (index != 0) {
                    s[index] = ' ';
                    index++;
                }
                int end = start;
                while (end < size && s[end] != ' ') {
                    s[index] = s[end];
                    index++;
                    end++;
                }
                std::reverse(s.begin() + index - (end - start),
                             s.begin() + index);
                start = end;
            }
        }
        s.erase(s.begin() + index, s.end());
        return s;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char *argv[]) {
    std::string str = "   the   sky is blue ";
    Solution solution;
    std::cout << solution.reverseWords(str) << std::endl;
}
