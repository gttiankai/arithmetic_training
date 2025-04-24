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
#include <__ostream/basic_ostream.h>

#include <iostream>
#include <string>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::string multiply(std::string num1, std::string num2) {
        int M = num1.length();
        int N = num2.length();
        if (M == 1 && num1[0] == '0') return "0";
        if (N == 1 && num2[0] == '0') return "0";
        std::string ans;
        for (int i = M - 1; i >= 0; i--) {
            std::string product;
            char a    = num1[i];
            int carry = 0;
            for (int j = N - 1; j >= 0; j--) {
                char b = num2[j];
                int p  = (a - '0') * (b - '0') + carry;
                carry  = p / 10;
                p      = p % 10;
                product.push_back(char(p + '0'));
            }
            if (carry > 0) {
                product.push_back(char(carry + '0'));
            }
            ans = SumProduct(ans, product, M - 1 - i);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }

   private:
    std::string SumProduct(std::string sum, std::string product, int offset) {
        std::string ans;
        while (offset > 0) {
            product.insert(product.begin(), '0');
            offset--;
        }
        int m     = sum.length();
        int n     = product.length();
        int i     = 0;
        int j     = 0;
        int carry = 0;
        while (i < m && j < n) {
            int c = sum[i] - '0' + product[j] - '0' + carry;
            carry = c / 10;
            c     = c % 10;
            ans.push_back(char(c + '0'));
            i++;
            j++;
        }
        while (i < m) {
            int c = sum[i] - '0' + carry;
            carry = c / 10;
            c     = c % 10;
            ans.push_back(char(c + '0'));
            i++;
        }
        while (j < n) {
            int c = product[j] - '0' + carry;
            carry = c / 10;
            c     = c % 10;
            ans.push_back(char(c + '0'));
            j++;
        }
        if (carry > 0) {
            ans.push_back(char(carry + '0'));
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char *argv[]) {
    Solution solution;
    std::vector<std::string> test_case_nums1 = {"123", "1234"};
    std::vector<std::string> test_case_nums2 = {"456", "5678"};
    for (int i = 0; i < test_case_nums1.size(); ++i) {
        std::string num1 = test_case_nums1[i];
        std::string num2 = test_case_nums2[i];
        std::string ans = solution.multiply(num1, num2);
        std::cout << num1 << " x " << num2 << " = " << ans << std::endl;
    }
}
