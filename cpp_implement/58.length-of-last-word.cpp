/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.cn/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (42.63%)
 * Likes:    588
 * Dislikes: 0
 * Total Accepted:    432.3K
 * Total Submissions: 1M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consisting of words and spaces, return the length of the
 * last word in the string.
 *
 * A word is a maximal substring consisting of non-space characters only.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "Hello World"
 * Output: 5
 * Explanation: The last word is "World" with length 5.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "   fly me   to   the moon  "
 * Output: 4
 * Explanation: The last word is "moon" with length 4.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "luffy is still joyboy"
 * Output: 6
 * Explanation: The last word is "joyboy" with length 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only English letters and spaces ' '.
 * There will be at least one word in s.
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>

// @lc code=start
/**
 * 这个题目很简单,但是我却陷入了一个思维误区: 使用 start 和 end 的方式记录 last word 的开始和结束, 这就带来一个问题就是 end 初始值不好确定
 * 造成了之前实现的解法很笨重.
 *
 * */
class Solution {
 public:
  int lengthOfLastWord(std::string s) {
    int N     = s.size();
    int start = N - 1;
    for (size_t i = N - 1; i >= 0; --i) {
      if (s[i] != ' ') {
        start = i;
        break;
      }
    }

    int len = 0;
    for (int i = start; i >= 0; --i) {
      if (s[i] != ' ') {
        len++;
      } else {
        break;
      }
    }
    return len;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution solution;
  std::vector<std::string> input_message = {"   fly me   to   the moon  ", "a", "a "};
  for (const auto& item : input_message) {
    std::cout << solution.lengthOfLastWord(item) << std::endl;
  }
  return 0;
}
