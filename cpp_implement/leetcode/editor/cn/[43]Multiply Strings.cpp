// Given two non-negative integers num1 and num2 represented as strings, return
// the product of num1 and num2, also represented as a string.
//
// Note: You must not use any built-in BigInteger library or convert the inputs
// to integer directly.
//
//
// Example 1:
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
//
//  Constraints:
//
//
//  1 <= num1.length, num2.length <= 200
//  num1 and num2 consist of digits only.
//  Both num1 and num2 do not contain any leading zero, except the number 0
// itself.
//
//
//  Related Topics 数学 字符串 模拟 👍 1422 👎 0
#include <string>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::string multiply(std::string num1, std::string num2) {
        int m = num1.length();
        int n = num2.length();
        std::string ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
