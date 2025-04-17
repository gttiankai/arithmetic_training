/**
Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.


 Example 1:
 Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

 Example 2:
 Input: n = 1
Output: ["()"]


 Constraints:


 1 <= n <= 8


 Related Topics 字符串 动态规划 回溯 👍 3819 👎 0

*/
#include <ios>
#include <string>
#include <vector>
// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        std::string parenthesis;
        BackTracking(ans, parenthesis, 0, 0, n);
        return ans;
    }

   private:
    void BackTracking(std::vector<std::string>& ans, std::string parenthesis,
                      int left, int right, int n) {
        if (right > left) {
            return;
        }
        if (left == n && left == right) {
            ans.push_back(parenthesis);
            return;
        }
        if (left < n) {
            parenthesis.push_back('(');
            BackTracking(ans, parenthesis, left + 1, right, n);
            parenthesis.pop_back();
        }
        if (left > right) {
            parenthesis.push_back(')');
            BackTracking(ans, parenthesis, left, right + 1, n);
            parenthesis.pop_back();
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)
