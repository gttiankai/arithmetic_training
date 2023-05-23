/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
/**
 *  1. bad case: [-2, -1]
 *      考虑之前的 max 是负数的情况
 * */

// @lc code=start
/**
 * 这种解法超时了
 * 时间复杂度: O( N^2 )
 * 空间复杂度: O( N )
 * */
class SolutionSlow {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int N = nums.size();
    std::vector<int> dp(N);
    dp[0] = nums[0];
    for (int i = 1; i < N; ++i) {
      int max = dp[i - 1];
      if (nums[i] > 0) {
        int sum = 0;
        int j   = i;
        while (j >= 0) {
          sum += nums[j];
          j--;
          max = sum > max ? sum : max;
        }
      } else {
        max = std::max(nums[i], max);
      }
      // nums[i] <= 0 will not influence max sub array
      dp[i] = max;
    }
    return dp[N - 1];
  }
};

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
  }
}
// @lc code=end

int main(int argc, char* argv[]) {
  //std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  std::vector<int> nums = {-2, -1};
  Solution solution;
  std::cout << solution.maxSubArray(nums) << std::endl;
  return 0;
}