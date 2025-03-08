//A phrase is a palindrome if, after converting all uppercase letters into 
//lowercase letters and removing all non-alphanumeric characters, it reads the same 
//forward and backward. Alphanumeric characters include letters and numbers. 
//
// Given a string s, return true if it is a palindrome, or false otherwise. 
//
// 
// Example 1: 
//
// 
//Input: s = "A man, a plan, a canal: Panama"
//Output: true
//Explanation: "amanaplanacanalpanama" is a palindrome.
// 
//
// Example 2: 
//
// 
//Input: s = "race a car"
//Output: false
//Explanation: "raceacar" is not a palindrome.
// 
//
// Example 3: 
//
// 
//Input: s = " "
//Output: true
//Explanation: s is an empty string "" after removing non-alphanumeric 
//characters.
//Since an empty string reads the same forward and backward, it is a palindrome.
//
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 2 * 10⁵ 
// s consists only of printable ASCII characters. 
// 
//
// Related Topics 双指针 字符串 👍 801 👎 0
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
     * 时间复杂度: O(N)
     * 空间复杂度: O(N)
     ***/
    bool isPalindromeFake(std::string s) {
        std::string processed = ProcessChars(s);
        int n = processed.size();
        int i = 0, j = n - 1, mid = n / 2;
        for (; i < mid; ++i, j --) {
            if (processed[i] != processed[j]) {
                return false;
            }
        }
        return true;
    }

private:
    std::string ProcessChars(std::string s) {
        std::string processed = "";
        int diff = std::abs('A'- 'a');
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if ( (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                processed.push_back(c);
            } else if ( c >= 'A' && c <= 'Z') {
                processed.push_back(char( c + diff));
            }
        }
        return processed;
    }
public:
    bool isPalindrome(std::string s) {
        // 使用双指针,不需要额外的数组进行处理
        int i = 0;
        int j = s.length() - 1;
        while (i <= j) {
            if (!IsValid(s[i])) {
                i++;
                continue;
            }
            if (!IsValid(s[j])) {
                j--;
                continue;
            }
            if (LowerCase(s[i]) != LowerCase(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
private:
    bool IsValid(const char c) {
        if ( (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
            return true;
        } else {
            return false;
        }
    }
    char LowerCase(const char c) {
        if ( c >= 'A' && c <= 'Z') {
            return char(c + ('a' - 'A'));
        } else {
            return c;
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char *argv[]) {
    Solution solution;
    std::vector<std::string> test_case;
    test_case.push_back("A man, a plan, a canal: Panama");
    test_case.push_back("0P");
    test_case.push_back("race a car");
    test_case.push_back(" ");
    for (auto& case_ : test_case) {
        // std::cout << case_ << " is palindrome ? the answer is " << solution.isPalindrome(case_) << std::endl;
        std::cout << case_ << " is palindrome ? the answer is " << solution.isPalindromeTwoPointer(case_) << std::endl;
    }
    return 0;
}
