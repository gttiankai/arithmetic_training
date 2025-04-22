// The count-and-say sequence is a sequence of digit strings defined by the
// recursive formula:
//
//
//  countAndSay(1) = "1"
//  countAndSay(n) is the run-length encoding of countAndSay(n - 1).
//
//
//  Run-length encoding (RLE) is a string compression method that works by
// replacing consecutive identical characters (repeated 2 or more times) with
// the concatenation of the character and the number marking the count of the
// characters ( length of the run). For example, to compress the string
// "3322251" we replace "33" with "23", replace "222" with "32", replace "5"
// with "15" and replace "1" with "11
//". Thus the compressed string becomes "23321511".
//
//  Given a positive integer n, return the nᵗʰ element of the count-and-say
// sequence.
//
//
//  Example 1:
//
// //  Input: n = 4
//
//
//  Output: "1211"
//
//  Explanation:
//
//
// countAndSay(1) = "1"
// countAndSay(2) = RLE of "1" = "11"
// countAndSay(3) = RLE of "11" = "21"
// countAndSay(4) = RLE of "21" = "1211"
//
//
//
//  Example 2:
//
//
//  Input: n = 1
//
//
//  Output: "1"
//
//  Explanation:
//
//  This is the base case.
//
//
//  Constraints:
//
//
//  1 <= n <= 30
//
//
//
// Follow up: Could you solve it iteratively?
//
//  Related Topics 字符串 👍 1110 👎 0

#include <iostream>
#include <string>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::string countAndSay(int n) {
        std::vector<std::string> ans(n);
        ans[0] = "1";
        for (int i = 1; i < n; i++) {
            ans[i] = RLE(ans[i - 1]);
        }

        return ans[n - 1];
    }

   private:
    std::string RLE(std::string s) {
        std::string ans = "";
        int n           = s.length();
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (i < n - 1 && s[i] == s[i + 1]) {
                count++;
                i++;
            }
            ans += std::to_string(count);
            ans.push_back(s[i]);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char *argv[]) {
    std::vector<int> test_case = {1, 2, 3, 4};
    Solution solution;
    for (auto case_ : test_case) {
        std::string ans = solution.countAndSay(case_);
        std::cout << "countAndSay(" << case_ << "):" << ans << std::endl;
    }

    return 0;
}
