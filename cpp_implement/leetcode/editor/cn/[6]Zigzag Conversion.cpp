// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
// of rows like this: (you may want to display this pattern in a fixed font for
// better legibility)
//
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
//
//  And then read line by line: "PAHNAPLSIIGYIR"
//
//  Write the code that will take a string and make this conversion given a
// number of rows:
//
//
// string convert(string s, int numRows);
//
//
//  Example 1:
//
//
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
//
//
//  Example 2:
//
//
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//
//
// Example 3:
// Input: s = "A", numRows = 1
// Output: "A"
//
//  Constraints:
//
//  1 <= s.length <= 1000
//  s consists of English letters (lower-case and upper-case), ',' and '.'.
//  1 <= numRows <= 1000
//
//  Related Topics 字符串 👍 2477 👎 0
#include <iostream>
#include <string>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;
        std::string ans;
        int mode = 2 * numRows - 2;
        int n    = s.size();
        std::vector<std::string> zigzag(numRows);
        for (int i = 0; i < n; i++) {
            int index = i % mode;
            if (index < numRows) {
                zigzag[index] += s.substr(i, 1);
            } else {
                index = numRows - 1 - (index - numRows + 1);
                zigzag[index] += s.substr(i, 1);
            }
        }
        for (auto item : zigzag) {
            ans += item;
        }
        return ans;
    }
    /**
     * 使用直接计算的方式能够更快的解决这个问题
     ***/
    std::string convertFaster(std::string s, int numRows) {
        if (numRows == 1) return s;
        std::string ans;
        int mode = 2 * numRows - 2;
        int n    = s.size();
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < (n / mode + 1); j++) {
                int index = j * mode + i;
                if (index >= n) {
                    break;
                }
                if (i == 0 || i == numRows - 1) {
                    ans += s.substr(index, 1);
                } else {
                    ans += s.substr(index, 1);
                    index = (j + 1) * mode - i;
                    if (index < n) ans += s.substr(index, 1);
                }
            }
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char *argv[]) {
    Solution solution;
    std::vector<std::string> test_case = {"PAHNAPLSIIGYIR", "PAHNAPLSIIGYIR", "A", "AB"};
    std::vector<int> numes             = {4, 3, 1, 1};
    for (int i = 0; i < test_case.size(); i++) {
        std::cout << test_case[i] << " " << numes[i] << " zigzag: " << solution.convert(test_case[i], numes[i])
                  << std::endl;
    }
    return 0;
}
