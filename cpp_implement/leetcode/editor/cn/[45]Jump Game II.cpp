// You are given a 0-indexed array of integers nums of length n. You are
// initially positioned at nums[0].
//
// Each element nums[i] represents the maximum length of a forward jump from
// index i. In other words, if you are at nums[i], you can jump to any nums[i +
// j] where:
//
//
//  0 <= j <= nums[i] and
//  i + j < n
//
//
//  Return the minimum number of jumps to reach nums[n - 1]. The test cases are
// generated such that you can reach nums[n - 1].
//
//
//  Example 1:
//
//
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1
// step from index 0 to 1, then 3 steps to the last index.
//
//
//  Example 2:
//
//
// Input: nums = [2,3,0,1,4]
// Output: 2
//
//
//
//  Constraints:
//
//
//  1 <= nums.length <= 10⁴
//  0 <= nums[i] <= 1000
//  It's guaranteed that you can reach nums[n - 1].
//
//
//  Related Topics 贪心 数组 动态规划 👍 2816 👎 0
#include <algorithm>
#include <iostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    int jumpSlow(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int ans   = 0;
        int start = 0;
        int end   = 1;
        while (end < n) {
            int max_pos = 0;
            // 从 start 位置开始,能跳到的最远的位置
            for (int i = start; i < end; i++) {
                max_pos = std::max(max_pos, i + nums[i]);
            }
            // ans++ 代表跳了一步,接下来就要更新 start 和 end 的值
            ans   = ans + 1;
            start = end;
            end   = max_pos + 1;
        }
        return ans;
    }

    int jump(std::vector<int>& nums) {
        int jump_num = 0;
        int end      = 0;
        int max_pos  = 0;
        int n        = nums.size();
        if (n == 1) return 0;
        for (int i = 0; i < n - 1; i++) {
            max_pos = std::max(max_pos, i + nums[i]);
            if (i == end) {
                end = max_pos;
                jump_num++;
                if (end >= n - 1) {
                    break;
                }
            }
        }
        return jump_num;
    }
};
// leetcode submit region end(Prohibit modification and deletion)
int main(int argc, char* argv[]) {
    Solution solution;

    std::vector<std::vector<int> > test_case = {
        {2, 3, 1, 1, 4},
        {1, 2, 1, 1, 1},
    };
    for (auto item : test_case) {
        int jump_num = solution.jump(item);
        std::cout << jump_num << std::endl;
    }
    return 0;
}
