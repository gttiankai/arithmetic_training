//
// The algorithm for myAtoi(string s) is as follows:
//
// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+
//', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit
// character is encountered or the end of the string is reached. If no digits were
// read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-2³¹, 2³¹
// - 1], then round the integer to remain in the range. Specifically, integers
// less than -2³¹ should be rounded to -2³¹, and integers greater than 2³¹ - 1 should
// be rounded to 2³¹ - 1.
//
// Return the integer as the final result.
//
//
// Example 1:
//
// Input: s = "42"
//
// Output: 42
//
// Explanation:
//
// The underlined characters are what is read in and the caret is the current
// reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
//         ^
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
//         ^
// Step 3: "42" ("42" is read in)
//           ^
//
//
//
// Example 2:
//
//
// Input: s = " -042"
//
//
// Output: -42
//
// Explanation:
//
//
// Step 1: "   -042" (leading whitespace is read and ignored)
//            ^
// Step 2: "   -042" ('-' is read, so the result should be negative)
//             ^
// Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
//               ^
//
//
//
// Example 3:
//
//
// Input: s = "1337c0d3"
//
//
// Output: 1337
//
// Explanation:
//
//
// Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
//
//         ^
// Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
//
//         ^
// Step 3: "1337c0d3" ("1337" is read in; reading stops because the next
// character is a non-digit)
//             ^
//
//
//
// Example 4:
//
//
// Input: s = "0-1"
//
//
// Output: 0
//
// Explanation:
//
//
// Step 1: "0-1" (no characters read because there is no leading whitespace)
//         ^
// Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
//         ^
// Step 3: "0-1" ("0" is read in; reading stops because the next character is a
// non-digit)
//          ^
//
//
//
// Example 5:
//
//
// Input: s = "words and 987"
//
//
// Output: 0
//
// Explanation:
//
// Reading stops at the first non-digit character 'w'.
//
//
// Constraints:
//
//
// 0 <= s.length <= 200
// s consists of English letters (lower-case and upper-case), digits (0-9), ' ',
// '+', '-', and '.'.
//
//
// Related Topics 字符串 👍 1885 👎 0
#include <climits>
#include <iostream>
#include <string>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 这个题目有两个地方的难点:
     * 1. 对 signedness 的处理,这部分有三种情况: -, +, default(+)
     * 2. 如何对不在 [INT_MIN, INT_MAX] 范围内的数据进行处理,尤其需要注意的事 INT_MIN, INT_MAX 是不对称的.
     *
     ***/
    int myAtoi(std::string s) {
        s = ProcessWhiteSpace(s);
        if (s.empty()) return 0;
        long long ans = 0;
        int sign      = Signedness(s[0]);
        if (sign != 0) {
            s = s.substr(1, s.length() - 1);
        }
        if (sign == 0) {
            sign = 1;
        }

        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (!IsValid(s[i])) {
                break;
            }
            // key point
            if (sign > 0) {
                ans = ans * 10 + (s[i] - '0');
            } else {
                ans = ans * 10 - (s[i] - '0');
            }
            // key point
            if (ans >= INT_MAX) {
                return INT_MAX;
            }
            if (ans <= INT_MIN) {
                return INT_MIN;
            }
        }
        return ans;
    }

   private:
    std::string ProcessWhiteSpace(std::string s) {
        int n               = s.length();
        std::string sub_str = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                sub_str = s.substr(i, std::string::npos);
                break;
            }
        }
        return sub_str;
    }
    bool IsValid(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        } else {
            return false;
        }
    }
    int Signedness(char c) {
        if (c == '-') {
            return -1;
        } else if (c == '+') {
            return 1;
        }
        return 0;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::string> test_case = {"   -042", "21474836460", "0-1", "1337c0d3", "words and 987", "42", "32.41"};
    for (auto case_ : test_case) {
        std::cout << case_ << " atoi: " << solution.myAtoi(case_) << std::endl;
    }
    return 0;
}
