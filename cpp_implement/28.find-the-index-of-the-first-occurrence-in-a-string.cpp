/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Medium (42.39%)
 * Likes:    1874
 * Dislikes: 0
 * Total Accepted:    849.5K
 * Total Submissions: 2M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * Given two strings needle and haystack, return the index of the first
 * occurrence of needle in haystack, or -1 if needle is not part of
 * haystack.
 *
 *
 * Example 1:
 *
 *
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6.
 * The first occurrence is at index 0, so we return 0.
 *
 *
 * Example 2:
 *
 *
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" did not occur in "leetcode", so we return -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack and needle consist of only lowercase English characters.
 *
 *
 */
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

// @lc code=start
class Solution {
 public:
  int strStr(std::string haystack, std::string needle) {
    int M = haystack.size();
    int N = needle.size();
    if (M < N) {
      return -1;
    }
    for (int i = 0; i <= M - N; ++i) {
      if (Equal(haystack, needle, i)) {
        return i;
      }
    }
    return -1;
  }

 private:
  bool Equal(std::string& haystack, std::string& needle, int start) {
    int N = needle.size();
    for (int j = 0; j < N; ++j) {
      if (haystack[start + j] != needle[j]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<std::string> haystackes;
  std::vector<std::string> needles;
  haystackes.push_back("sadbutsad");
  needles.push_back("sad");
  haystackes.push_back("leetcode");
  needles.push_back("leeto");
  haystackes.push_back("a");
  needles.push_back("a");
  for (int i = 0; i < haystackes.size(); ++i) {
    std::cout << haystackes[i] << " " << needles[i] << " " << solution.strStr(haystackes[i], needles[i]) << std::endl;
  }
  return 0;
}
