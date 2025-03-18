// Given a string columnTitle that represents the column title as appears in an
// Excel sheet, return its corresponding column number.
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
// Input: columnTitle = "A"
// Output: 1
//
//
//  Example 2:
//
//
// Input: columnTitle = "AB"
// Output: 28
//
//
//  Example 3:
//
//
// Input: columnTitle = "ZY"
// Output: 701
//
//
//
//  Constraints:
//
//
//  1 <= columnTitle.length <= 7
//  columnTitle consists only of uppercase English letters.
//  columnTitle is in the range ["A", "FXSHRXW"].
//
//
//   Related Topics 数学 字符串 👍 423 👎 0
#include <iostream>

#include <ostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int titleToNumber(std::string columnTitle) {
        int num = 0;
        for (int i = 0; i < columnTitle.size(); ++i) {
            num = num * 26 + (columnTitle[i] - 'A' + 1);
        }
        return num;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char *argv[]) {
    Solution solution;
    std::vector<std::string> test_cases = {"A", "Z", "AA", "ZY"};
    for (auto test_case : test_cases) {
        std::cout << test_case << " -> " << solution.titleToNumber(test_case) << std::endl;
    }
    return 0;
}
