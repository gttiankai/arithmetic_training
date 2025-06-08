// Given an integer array nums where every element appears three times except
// for one, which appears exactly once. Find the single element and return it.
//
//  You must implement a solution with a linear runtime complexity and use only
// constant extra space.
//
//  Example 1:
//  Input: nums = [2,2,3,2]
// Output: 3
//
//  Example 2:
//  Input: nums = [0,1,0,1,0,1,99]
// Output: 99
//
//  Constraints:
//  1 <= nums.length <= 3 * 10⁴
//  -2³¹ <= nums[i] <= 2³¹ - 1
//  Each element in nums appears exactly three times except for one element
// which appears once.
//
//
//  Related Topics 位运算 数组 👍 1284 👎 0
#include <iostream>
#include <vector>

// leetcode submit region begin(Prohibit modification and deletion)
class Solution {
   public:
    /**
     * 下面实现的解法比较容易理解
     *
     * 使用 1 个 32 位的数组,统计每个数在 32 位上的 1 的个数,然后对 3 取余数,
     * 然后将 32 位编码还原成原始值
     ***/
    int singleNumber(std::vector<int>& nums) {
        std::vector<int> flags(32, 0);
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            for (int j = 0; j < 32; j++) {
                flags[j] += (num >> j) & 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans |= ((flags[i] % 3) << i);
        }
        return ans;
    }
};
// leetcode submit region end(Prohibit modification and deletion)

int main(int argc, char* argv[]) {
    Solution solution;
    std::vector<std::vector<int>> test_case = {
        {-2, -2, 1, 1, 4, 1, 4, 4, -4, -2},
        {2, 2, 3, 2},
    };

    for (auto nums : test_case) {
        std::cout << solution.singleNumber(nums) << std::endl;
    }
}
