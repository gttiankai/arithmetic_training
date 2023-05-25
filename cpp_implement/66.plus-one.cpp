/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.cn/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.15%)
 * Likes:    1232
 * Dislikes: 0
 * Total Accepted:    632.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3]'
 *
 * You are given a large integer represented as an integer array digits, where
 * each digits[i] is the i^th digit of the integer. The digits are ordered from
 * most significant to least significant in left-to-right order. The large
 * integer does not contain any leading 0's.
 *
 * Increment the large integer by one and return the resulting array of
 * digits.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * Incrementing by one gives 123 + 1 = 124.
 * Thus, the result should be [1,2,4].
 *
 *
 * Example 2:
 *
 *
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * Incrementing by one gives 4321 + 1 = 4322.
 * Thus, the result should be [4,3,2,2].
 *
 *
 * Example 3:
 *
 *
 * Input: digits = [9]
 * Output: [1,0]
 * Explanation: The array represents the integer 9.
 * Incrementing by one gives 9 + 1 = 10.
 * Thus, the result should be [1,0].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * digits does not contain any leading 0's.
 *
 *
 */

#include <_ctype.h>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
// @lc code=start
class Solution {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    int N = digits.size();
    for (int i = N - 1; i >= 0; --i) {
      int num = digits[i] + 1;
      if (num < 10) {
        digits[i] = num;
        return digits;
      } else {
        digits[i] = 0;
      }
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  std::vector<int> digits = {9, 9};
  Solution solution;
  auto ans = solution.plusOne(digits);
  for (const auto& item : ans) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  return 0;
}
