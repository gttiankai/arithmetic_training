// Given two integers n and k, return all possible combinations of k numbers
// chosen from the range [1, n].
//
//  You may return the answer in any order.
//
//
//  Example 1:
//
//
// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to
// be the same combination.
//
//
//  Example 2:
//
//
// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.
//
//
//
//  Constraints:
//
//
//  1 <= n <= 20
//  1 <= k <= n
//
//
//  Related Topics 回溯 👍 1763 👎 0
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> ans;
        std::vector<int> nums;
        BackTracking(ans, nums, n, k, 1);
        return ans;
    }

   private:
    void BackTracking(std::vector<std::vector<int>>& ans,
                      std::vector<int>& nums, int n, int k, int begin) {
        if (nums.size() == k) {
            ans.push_back(nums);
            return;
        }
        for (int i = begin; i <= n; i++) {
            // 添加的元素是 i , 并不是其他的元素
            nums.push_back(i);
            BackTracking(ans, nums, n, k, i + 1);
            nums.pop_back();
        }
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    solution.combine(4, 2);
}
