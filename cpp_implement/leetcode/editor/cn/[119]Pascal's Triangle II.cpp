// Given an integer rowIndex, return the rowIndexᵗʰ (0-indexed) row of the
// Pascal's triangle.
//
//  In Pascal's triangle, each number is the sum of the two numbers directly
// above it as shown:
//
//
//  Example 1:
//  Input: rowIndex = 3
// Output: [1,3,3,1]
//
//  Example 2:
//  Input: rowIndex = 0
// Output: [1]
//
//  Example 3:
//  Input: rowIndex = 1
// Output: [1,1]
//
//
//  Constraints:
//
//
//  0 <= rowIndex <= 33
//
//
//
//  Follow up: Could you optimize your algorithm to use only O(rowIndex) extra
// space?
//
//  Related Topics 数组 动态规划 👍 581 👎 0
#include <iostream>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<int> getRowSlow(int rowIndex) {
        std::vector<int> row_values(rowIndex + 1);
        row_values[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; --j) {
                row_values[j] += row_values[j - 1];
            }
            std::cout << "row " << i ;
            for (auto& value : row_values) {
                std::cout << " value [" << value;
            }
            std::cout << "]" << std::endl;
        }

        return row_values;
    }
    // 由于杨辉三角的计算公司和组合数的计算公式一致,所有可以用组合数的公式推导出杨辉三角额公式
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row_values(rowIndex + 1);
        row_values[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            row_values[i] = 1LL * row_values[i - 1] * (rowIndex - i + 1) / i;

        }
        return row_values;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    int row_index                    = 5;
    std::vector<int> pascal_triangle = solution.getRow(5);
    std::cout << "row " << row_index << " values: [";
    for (auto& value : pascal_triangle) {
        std::cout << value << " ";
    }
    std::cout << "]" << std::endl;
    return 0;
}
