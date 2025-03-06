// Given an integer numRows, return the first numRows of Pascal's triangle.
//
//  In Pascal's triangle, each number is the sum of the two numbers directly
// above it as shown:
//
//
//  Example 1:
//  Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//
//  Example 2:
//  Input: numRows = 1
// Output: [[1]]
//
//
//  Constraints:
//
//
//  1 <= numRows <= 30
//
//
#include <iostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> dp;
        dp.push_back({1});
        if (numRows == 1) {
            return dp;
        }
        for (int i = 2; i <= numRows; i++) {
            std::vector<int> row_value(i);
            row_value[0]     = 1;
            row_value[i - 1] = 1;
            for (int j = 1; j < i - 1; j++) {
              
                row_value[j] = dp[i - 2][j - 1] + dp[i - 2][j];
            }
            dp.push_back(row_value);
        }
        return dp;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    // Pascal's triangle.
    auto pascal_triangle = solution.generate(5);
    for (int i = 0; i < pascal_triangle.size(); i++) {
        std::vector<int> row_values = pascal_triangle[i];
        std::cout << "row " << i << " values: [";
        for (auto& value : row_values) {
            std::cout << value << " ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
