/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.cn/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (63.83%)
 * Likes:    2876
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 1.8M
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example,2 is written as II in Roman numeral, just two ones added
 * together. 12 is written as XII, which is simply X + II. The number 27 is
 * written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer.
 *
 * Example 1:
 *
 * Input: s = "III"
 * Output: 3
 * Explanation: III = 3.
 *
 * Example 2:
 * Input: s = "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 *
 * Example 3:
 * Input: s = "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 * Constraints:
 *
 * 1 <= s.length <= 15
 * s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 * It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 *
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
// @lc code=start
class Solution {
   public:
    int romanToInt(std::string s) {
        int ans = 0;
        std::unordered_map<char, int> hash_map;
        hash_map['I'] = 1;
        hash_map['V'] = 5;
        hash_map['X'] = 10;
        hash_map['L'] = 50;
        hash_map['C'] = 100;
        hash_map['D'] = 500;
        hash_map['M'] = 1000;
        int count     = s.size();
        int i         = 0;
        for (int i = 0; i < count; ++i) {
            if (i < count - 1 && hash_map[s[i]] < hash_map[s[i + 1]]) {
                ans -= hash_map[s[i]];
            } else {
                ans += hash_map[s[i]];
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {
    std::vector<std::string> tests = {"III", "LVIII", "MCMXCIV", "IV", "IX", "XL", "XC", "CD", "CM"};
    Solution solution;
    for(auto test : tests) {
        std::cout << test << " : " <<solution.romanToInt(test) << std::endl;
    }
}