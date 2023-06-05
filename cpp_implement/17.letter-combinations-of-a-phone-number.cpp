/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (58.08%)
 * Likes:    2487
 * Dislikes: 0
 * Total Accepted:    699.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */

#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

class SolutionUgly {
 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    static std::map<char, std::vector<char>> letter_map_ = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}}, {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};

    std::vector<std::string> ans = {};
    if (digits.empty()) {
      return ans;
    }
    std::queue<std::string> queue;

    int N       = digits.size();
    auto letter = letter_map_[digits[0]];
    for (const auto& iter : letter) {
      std::string temp = "";
      queue.push(temp + iter);
    }
    for (int i = 1; i < N; ++i) {
      letter    = letter_map_[digits[i]];
      int count = queue.size();
      for (int j = 0; j < count; ++j) {
        std::string pre = queue.front();
        queue.pop();
        for (const auto& iter : letter) {
          queue.push(pre + iter);
        }
      }
    }
    while (!queue.empty()) {
      ans.push_back(queue.front());
      queue.pop();
    }
    return ans;
  }
};

// @lc code=start
/**
 * 重构了回溯的方案，本质上和上面的方案是一致的，只是用递归调用的方式实现了回溯方案。
 * 两个方案的时间复杂度是一样的。
 * */
class Solution {
 public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> combinations;
    if (digits.empty()) {
      return combinations;
    }
    static std::map<char, std::vector<char>> letter_map_ = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}}, {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};

    std::string combination;
    BackTrack(combinations, letter_map_, digits, 0, combination);
    return combinations;
  }

 private:
  void BackTrack(std::vector<std::string>& combinations, std::map<char, std::vector<char>>& letter_map,
                 std::string& digists, int index, std::string& combination) {
    if (index == digists.size()) {
      combinations.push_back(combination);
    } else {
      char digit   = digists[index];
      auto& letter = letter_map.at(digit);
      for (const auto& item : letter) {
        combination.push_back(item);
        BackTrack(combinations, letter_map, digists, index + 1, combination);
        combination.pop_back();
      }
    }
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<std::string> test_case;
  test_case.push_back("23");
  test_case.push_back("2");
  test_case.push_back("");
  for (const auto& item : test_case) {
    std::cout << item << " letter combination:";
    auto ans = solution.letterCombinations(item);
    for (const auto& i : ans) {
      std::cout << i << ",";
    }
    std::cout << std::endl;
  }
  return 0;
}