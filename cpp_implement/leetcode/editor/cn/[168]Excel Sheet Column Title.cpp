// Given an integer columnNumber, return its corresponding column title as it
// appears in an Excel sheet.
//
//  For example:
//
//
// A -> 1
// B -> 2
// C -> 3
//...
// Z -> 26
// AA -> 27
// AB -> 28
//...
//
//
//
//  Example 1:
//
//
// Input: columnNumber = 1
// Output: "A"
//
//
//  Example 2:
//
//
// Input: columnNumber = 28
// Output: "AB"
//
//
//  Example 3:
//
//
// Input: columnNumber = 701
// Output: "ZY"
//
//
//
//  Constraints:
//
//
//  1 <= columnNumber <= 2³¹ - 1
//
//
//  Related Topics 数学 字符串 👍 715 👎 0

#include <iostream>

#include <ostream>
#include <string>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /***
     * 这个题目要模仿 10 进制的方案进行处理
     * 这个题目最重要的是要注意到, columnNumber 是从 1 开始,并不是从 0 开始的
     *
     ***/
    std::string convertToTitle(int columnNumber) {
        std::string ans;
        while (columnNumber >0) {
            columnNumber -= 1;
            int remainder = columnNumber % 26;
            ans.push_back(char(remainder + 'A'));
            columnNumber = columnNumber / 26;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<int> test_cases = {52, 701, 8690, 1, 26, 27, 28};
    for (auto& case_ : test_cases) {
        std::string tile = solution.convertToTitle(case_);
        std::cout << case_ << ": " << tile << std::endl;
    }
}
