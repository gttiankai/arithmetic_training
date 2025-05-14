// Given an integer n, return the number of structurally unique BST's (binary
// search trees) which has exactly n nodes of unique values from 1 to n.
//
//
//  Example 1:
//
//
// Input: n = 3
// Output: 5
//
//
//  Example 2:
//
//
// Input: n = 1
// Output: 1
//
//
//
//  Constraints:
//
//
//  1 <= n <= 19
//
//
//  Related Topics 树 二叉搜索树 数学 动态规划 二叉树 👍 2638 👎 0

#include <__ostream/basic_ostream.h>

#include <iostream>
#include <random>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int numTrees(int n) {
        /**
         * dp(n): n 对应的 BST 的个数
         */
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char *argv[]) {
    Solution solution;
    int n = solution.numTrees(4);
    std::cout << n << std::endl;
}
