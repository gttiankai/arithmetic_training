//Given two binary strings a and b, return their sum as a binary string. 
//
// 
// Example 1: 
// Input: a = "11", b = "1"
//Output: "100"
// 
// Example 2: 
// Input: a = "1010", b = "1011"
//Output: "10101"
// 
// 
// Constraints: 
//
// 
// 1 <= a.length, b.length <= 10⁴ 
// a and b consist only of '0' or '1' characters. 
// Each string does not contain leading zeros except for the zero itself. 
// 
//
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /** 有点蠢,进位只能进2, 在高一位只能表示1
     *
     * 这个解法从一开始就是错的,就不应该使用小的作为标准,应该是用长的作为基准
     *
     **/
    std::string addBinaryWrong(std::string a, std::string b) {
        std::string sum_array;
        std::string little;
        int index = 0;
        int m = a.size();
        int n = b.size();
        if (m >= n) {
            sum_array = a;
            index = n - 1;
            little = b;
        } else {
            sum_array = b;
            index = m  - 1;
            little = a;
        }
        bool carry = false;
        while (index >= 0 ) {
            int sum = sum_array[index] - '0' + little[index] - '0';
            if (carry) {
                sum = sum + carry;
            }
            if (sum == 2) {
                sum_array[index] = '0';
                carry = true;
            } else {
                sum_array[index] = char(sum + '0');
                carry = false;
                break;
            }
            index--;
        }
        if (carry) {
            if (index >= 0) {
                while (carry && index >= 0) {
                }
            } else {
                // index < 0
                sum_array.insert(sum_array.begin(), '1');
            }
        }
        return sum_array;
    }
    /**
     * 模拟二进制加法的操作, 肯定是以长的为主
     * */
    std::string addBinary(std::string a, std::string b) {
        std::string sum_array;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        int count = std::max(a.size(), b.size());
        int carry = 0;
        for (int i = 0; i < count; ++i) {
            int sum = carry;
            if (i < a.size()) {
                sum += (a[i] - '0');
            }
            if (i < b.size()) {
                sum += (b[i] - '0');
            }
            sum_array.push_back(char(sum % 2 + '0'));
            carry        = sum / 2;
        }
        if (carry > 0) {
            sum_array.push_back('1');
        }
        std::reverse(sum_array.begin(), sum_array.end());
        return sum_array;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::string> a_array = {"11", "1010", "1", "1"};
    std::vector<std::string> b_array = {"11", "1011", "0", "1"};
    int n                            = a_array.size();
    for (int i = 0; i < n; ++i) {
        auto sum = solution.addBinary(a_array[i], b_array[i]);
        std::cout << a_array[i] << " + " << b_array[i] << " = " << sum << std::endl;
    }
    return 0;
}