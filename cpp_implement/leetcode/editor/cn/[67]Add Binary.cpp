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

#include <string>
#include <iostream>
#include <vector>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::string addBinary(std::string a, std::string b) {
        std::string sum_array;
        std::string little;
        int index = 0;
        int m = a.size();
        int n = b.size();
        if (m > n) {
            sum_array = a;
            index = n - 1;
            little = b;
        } else {
            sum_array = b;
            index = m  - 1;
            little = a;
        }
        int carry = 0;
        while (index >= 0 ) {
            int sum = sum_array[index] - '0' + little[index] - '0';
            if (carry > 0) {
                sum = sum + carry;
            }
            if (sum == 4) {
                sum_array[index] = '0';
                carry = 2;
            } else if (sum == 3) {
                sum_array[index] = '1';
                carry = 1;
            } else if (sum == 2) {
                sum_array[index] = '0';
                carry = 1;
            } else {
                sum_array[index] = sum + '0';
                carry = 0;
                break;
            }
        }
        if (carry > 0) {

        }
        return sum_array;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::string> a_array = {"11", "1010", "1"};
    std::vector<std::string> b_array = {"1", "1011", "0"};
    int n                            = a_array.size();
    for (int i = 0; i < n; ++i) {
        auto sum = solution.addBinary(a_array[i], b_array[i]);
        std::cout << a_array[i] << " + " << b_array[i] << " = " << sum << std::endl;
    }
    return 0;
}