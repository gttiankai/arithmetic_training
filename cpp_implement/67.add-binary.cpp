/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.cn/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.99%)
 * Likes:    1031
 * Dislikes: 0
 * Total Accepted:    324.1K
 * Total Submissions: 611.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 *
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 *
 * Constraints:
 *
 *
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 *
 *
 */
#include <iostream>
#include <string>

// @lc code=start
class Solution {
 public:
  std::string addBinary(std::string a, string b) {
    std::string ans;
  }
};
// @lc code=end

int main(int argc, char *argv[]) {
  std::string a = "1010", b = "1011";
  Solution solution;
  std::cout << solution.addBinary(a, b) << std::endl;
  return 0;
}
