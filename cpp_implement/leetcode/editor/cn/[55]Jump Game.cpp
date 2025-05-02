// You are given an integer array nums. You are initially positioned at the
// array's first index, and each element in the array represents your maximum
// jump length at that position.
//
//  Return true if you can reach the last index, or false otherwise.
//
//
//  Example 1:
//
//
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
//
//  Example 2:
//
//
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
// jump length is 0, which makes it impossible to reach the last index.
//
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 10⁴
//  0 <= nums[i] <= 10⁵
//
//
//  Related Topics 贪心
//  数组 动态规划 👍 3050 👎 0
#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 尝试使用贪心算法
     *  bad case: {0, 2, 3}
     *  bad case: {1, 0, 1, 0}
     **/
    bool canJumpComplex(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        bool ans     = false;
        int max_pos = 0;
        for (int i = 0; i < n - 1; i++) {
            max_pos = std::max(nums[i] + i, max_pos);
            if (max_pos >= n - 1) {
                ans = true;
                break;
            }
            if (max_pos == i ) {
                break;
            }
        }
        return ans;
    }
    bool canJump(std::vector<int>& nums) {
        int max_pos = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // 此处的 i <= max_pos 的判断是比较经典的地方
           if (i <= max_pos) {
               max_pos = std::max(nums[i] + i, max_pos);
               if (max_pos >= n - 1) {
                   return true;
               }
           }
        }
        return false;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> test_case;
    test_case.push_back({3, 2, 1, 0, 4});
    test_case.push_back({0, 1});
    test_case.push_back({0, 2, 3});
    test_case.push_back({1, 0, 1, 0});
    Solution solution;
    for (auto case_ : test_case) {
        bool ans = solution.canJump(case_);
        std::cout << ans << std::endl;
    }
}
