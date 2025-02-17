/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 *
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Easy (44.55%)
 * Likes:    2360
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 2.7M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * Given two strings needle and haystack, return the index of the first
 * occurrence of needle in haystack, or -1 if needle is not part of
 * haystack.
 *
 *
 * Example 1:
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6.
 * The first occurrence is at index 0, so we return 0.
 *
 *
 * Example 2:
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" did not occur in "leetcode", so we return -1.
 *
 * Constraints:
 *
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack and needle consist of only lowercase English characters.
 *
 */
#include <iostream>
#include <string>
#include <vector>
// @lc code=start
class Solution {
   public:
    /**
     * 时间复杂度: O(m*n)
     *      haystack.size(): m
     *      needle.size(): n
     * 空间复杂度:
     *      O(1)
     * */
    int strStrSlow(std::string haystack, std::string needle) {
        int index = -1;
        if (needle.size() > haystack.size()) {
            return index;
        }
        int n = needle.size();
        for (int i = 0; i < haystack.size() - n + 1; ++i) {
            if (needle == haystack.substr(i, n)) {
                index = i;
                break;
            }
        }
        return index;
    }
    /**
     * KMP 算法
     *
     * */
    int strStr(std::string haystack, std::string needle) {
        int index = -1;
        if (needle.size() > haystack.size()) {
            return index;
        }
        int n = needle.size();
        for (int i = 0; i < haystack.size() - n + 1; ++i) {
            if (needle == haystack.substr(i, n)) {
                index = i;
                break;
            }
        }
        return index;
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
        std::cout << haystackes[i] << " " << needles[i] << " " << solution.strStr(haystackes[i], needles[i])
                  << std::endl;
    }
    return 0;
}
